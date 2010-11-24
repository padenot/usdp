#!/usr/bin/php
<?php
/**
	Coupeur de troncons Q&D - no error checked
**/

function out($str) { echo "$str\n"; }

// work
$fn = $_SERVER['argv'][1];

function id($what) {
	return $what->getElementsByTagName('id')->item(0)->textContent;
}

// Finds a node according to its id, in the child node "id"
function find($where, $what, $which = null)
{
	$candidates = $where->getElementsByTagName($what);
	for($i = 0; $i < $candidates->length; ++$i)
	{
		$candidate = $candidates->item($i);
		if($candidate instanceof DOMElement)
		{
			if($which !== null)
			{
				$id = id($candidate);
				if($id == $which)
					return $candidate;
			}
			// returns the first child node if tag name $what
			else
				return $candidate;
		}
	}

	return null;
}

function divide($xml, $troncon, $step, $newId = 1)
{
	if($step < 1)
		return $newId;

	$root = find($xml, 'config');
	$_Ax = array();

	// début troncon
	$beginNodeId	= find($troncon, 'noeudDebut')->textContent;
	$beginNode	= find($xml, 'noeud', $beginNodeId);
	if($beginNode === null)
		throw new Exception("begin node (id=$beginNodeId) not found");

	// fin troncon
	$endNodeId		= find($troncon, 'noeudFin')->textContent;
	$endNode	= find($xml, 'noeud', $endNodeId);
	if($endNode === null)
		throw new Exception("en node (id=$endNodeId) not found");

	// milieu du troncon
	$middleX = (find($beginNode, 'x')->textContent + find($endNode, 'x')->textContent)/2;
	$middleY = (find($beginNode, 'y')->textContent + find($endNode, 'y')->textContent)/2;

	out("new node at (x, y)=($middleX, $middleY)");

	// nouveau noeud au milieu
	$node = $xml->createElement('noeud');
	$node_id = $xml->createElement('id');
	$node_x = $xml->createElement('x');
	$node_y = $xml->createElement('y');
	$node_suivant = $xml->createElement('suivanteGauche');

	$node_id_val = id($troncon).$newId;
	++$newId;
	$troncon_id_val = id($troncon).$newId;
	++$newId;

	$node_id->nodeValue = $node_id_val;
	$node_x->nodeValue = $middleX;
	$node_y->nodeValue = $middleY;
	$node_suivant->nodeValue = $troncon_id_val;

	$node->appendChild($node_id);
	$node->appendChild($node_x);
	$node->appendChild($node_y);
	$node->appendChild($node_suivant);

	$root->appendChild($node);
	unset($node, $node_id, $node_x, $node_y, $node_suivant);

	// nouveau troncon à la suite du courant
	$new_troncon = $xml->createElement('troncon');
	$troncon_id = $xml->createElement('id');
	$troncon_id->nodeValue = $troncon_id_val;
	$troncon_begin = $xml->createElement('noeudDebut');
	$troncon_begin->nodeValue = $node_id_val;
	$troncon_end = $xml->createElement('noeudFin');
	$troncon_end->nodeValue = id($endNode);

	$new_troncon->appendChild($troncon_id);
	$new_troncon->appendChild($troncon_begin);
	$new_troncon->appendChild($troncon_end);

	$root->appendChild($new_troncon);
	unset($troncon_id, $troncon_begin, $troncon_end);

	// changer fin troncon actuel
	find($troncon, 'noeudFin')->nodeValue = $node_id_val;
	find($beginNode, 'suivantGauche')->nodeValue = $troncon_id_val;

	--$step;
	$newId = divide($xml, $troncon, $step, $newId);
	divide($xml, $new_troncon, $step, $newId);
	return $newId;
}

out("parsing $fn");
try
{
	$xml = new DOMDocument();
	$xml->load($fn);
	// find the troncon node
	$troncon = find($xml, 'troncon', $_SERVER['argv'][2]);

	if($troncon === null)
		throw new Exception('troncon '.$_SERVER['argv'][2].' not found');

	$step = $_SERVER['argv'][3]-1;
	out('découpe en '.pow(2, $step).' troncons');

	divide($xml, $troncon, $step);

	$xml->save('updated_'.$fn);
}
catch(Exception $e) {
	out('Fatal: '.$e->getMessage());
}

