all:
	rm -Rf rsase/SGBag/doc/* && doxygen && sed -i -e "s/charset=iso-8859-1/charset=utf-8/g" rsase/SGBag/doc/html/*html
	cd Rapport && scons
