import codecs
import os
import sys

def readFile(filename):
	f = open(filename)

	buffer = f.read()
	f.close()
	return buffer

def getSourceFiles(srcPath, ext):
	root = srcPath
	sourceList = []
	for path, subdirs, files in os.walk(root):
		for name in files:
			if name.endswith(ext): 
				sourceList.append((name, os.path.join(os.path.abspath(path), name)))
	return sourceList

def toLatex(sourceList):
	output = ""
	for s in sourceList:
		n = s[0]
		p = s[1]

		buffer = "\\begin{lstlisting}\n"
		try:
			buffer += codecs.encode(readFile(p), 'utf8') + "\n"
		except: 
			print n
#			buffer += readFile(p).decode('ascii').encode('utf-8') + "\n"
		buffer += "\\end{lstlisting}\n\n"
		output += buffer
	return output
	
def main():
	print toLatex(getSourceFiles(sys.argv[1], "cpp"))

main()
