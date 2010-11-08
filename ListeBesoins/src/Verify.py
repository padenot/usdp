#!/usr/bin/env python
# -*- coding: utf-8 -*-

from xml.dom.minidom import parse, parseString

try:
	dom = parse('data.xml')
	print "OK"
except Exception:
	print "You fail dude !"
