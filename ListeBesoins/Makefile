SRC_PATH=src/
OUTPUT=liste-besoins

all: ${SRC_PATH}/*
	cd ${SRC_PATH} && python Export.py ${OUTPUT}.tex && make

clean:
	cd ${SRC_PATH} ; rm -rf bin ; rm -rf tmp ; rm -f ${OUTPUT}.tex
