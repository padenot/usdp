all:
	rm -Rf rsase/SGBag/doc/* &&	doxygen
	cd Rapport && scons
