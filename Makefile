all:
	doxygen dox.config
	cd Rapport && scons
