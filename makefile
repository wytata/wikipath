CC=g++ -std=c++17

SOURCE_DIR=wikipath
OUT_DIR=out
OBJ_DIR=${OUT_DIR}/objs
BIN_DIR=${OUT_DIR}/bin

TARGET=wikipath.bin

${TARGET}: ${SOURCE_DIR}/wikipath.cc
	${CC} -lssl ${SOURCE_DIR}/wikipath.cc -o ${BIN_DIR}/${TARGET}

clean:
	rm -f ${OBJ_DIR}/* ${BIN_DIR}/*
