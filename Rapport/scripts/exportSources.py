import os
import sys

def getSourceFiles(srcPath, ext):
	root = srcPath
	sourceList = []
	for path, subdirs, files in os.walk(root):
		for name in files:
			if name.endswith(ext) : sourceList.append((name, os.path.join(os.path.abspath(path), name)))
	return sourceList

def toLatex(sourceList):
	output = ""
	for s in sourceList:
		n = s[0]
		p = s[1]
		output += "\\nCode{" + n + "}{" + p + "}\n";
	return output
	
def main():
	print toLatex(getSourceFiles(sys.argv[1], "cpp"))

main()
