CC= g++
CFLAGS=  -Wno-write-strings -fopenmp

MAINS_DIR= Code/
ATMO_DIR=  Code/Atmo/
GEOAC_DIR= Code/GeoAc/

INSTALL_DIR= /usr/local/bin

GeoAcGlobal:
	${CC} ${ATMO_DIR}G2S_GlobalSpline1D.cpp ${ATMO_DIR}Atmo_State.Absorption.Global.cpp ${GEOAC_DIR}GeoAc.Parameters.Global.cpp ${GEOAC_DIR}GeoAc.Eigenray.Global.cpp ${GEOAC_DIR}GeoAc.EquationSets.Global.cpp ${GEOAC_DIR}GeoAc.Solver.cpp ${GEOAC_DIR}GeoAc.Interface.Global.cpp ${MAINS_DIR}GeoAcGlobal_main.cpp ${CFLAGS} -o GeoAcGlobal `ncxx4-config --cflags --libs`

all: GeoAcGlobal 

clean: 
	rm GeoAcGlobal 

install: GeoAcGlobal 
	install -m 0755 GeoAcGlobal ${INSTALL_DIR}

uninstall:
	rm ${INSTALL_DIR}/GeoAcGlobal 
	rm GeoAcGlobal 
