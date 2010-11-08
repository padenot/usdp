#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import codecs
from xml.dom.minidom import parse, parseString

def getText(nodelist):
	rc = []
	for node in nodelist:
		if node.nodeType == node.TEXT_NODE:
			rc.append(node.data)
	return ''.join(rc)

dom = parse('data.xml')

domains = dom.getElementsByTagName('d')
parsedDomains = []

for d in domains:
	title = d.getElementsByTagName('t')[0].childNodes[0].data
	title.strip()

	aloneCases = d.getElementsByTagName('c')
	parsedAloneCases = []
	for a in aloneCases:
		if a.parentNode.nodeName != "gr":
			parsedAloneCases.append(a.childNodes[0].data)

	groups = dom.getElementsByTagName('gr')
	parsedGroups = []
	for g in groups:
		name = g.getElementsByTagName('n')[0].childNodes[0].data
		cases = g.getElementsByTagName('c')
		parsedCases = []

		for c in cases:
			parsedCases.append(c.childNodes[0].data)

		parsedGroups.append((name, parsedCases))

	parsedDomains.append((title, parsedAloneCases, parsedGroups))
	
domainString = ""

# [ (Nom du domaine, [Cas sans groupe], (Titre, [Cas])) ]
for d in parsedDomains:
	domainString += "\domainNeeds{" + d[0] + "}"

	domainString += "\n{\n"
	for c in d[1]:domainString += "\t\\paragraph{ " + c + "}\n"
	domainString += "}\n"

	domainString += "{\n"
	for g in d[2]:
		domainString += "\paragraph{" + g[0] + "}\n"
		domainString += "\\begin{itemize}\n"
		for c in g[1]: domainString += "\t\\item " + c + "\n"
		domainString += "\\end{itemize}\n\n"

	domainString += "}\n\n"

f=codecs.open(sys.argv[1], encoding="utf-8", mode="w")
f.write(domainString)
f.close()

