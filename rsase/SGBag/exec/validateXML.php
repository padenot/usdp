#!/usr/bin/php
<?php

echo "Xml Validator in a few line, use DOM\n";

$xml = new DOMDocument();
echo "loading: {$_SERVER['argv'][1]}\n";

$xml->load($_SERVER['argv'][1]);

$ok = true;
if($xml->validate())
	echo "XML is valid according to the DTD\n";
else
	$ok = false;

if($xml->schemaValidate($_SERVER['argv'][2]))
	echo "XML is valid according to XMLSchema sgbag-schema.xsd\n";
else
	$ok = false;

if($ok)
	echo "XML Validated succesfuly !\n";

unset($xml);
