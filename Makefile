# Makefile
CC=g++
LIBS=-lm

OBJECTS1=CrankNicolson.o
TARGET1=CrankNicolson

all:	${TARGET1}

CrankNicolson:	${OBJECTS1}
	${CC} ${LIBS} ${OBJECTS1} -o ${TARGET1}

CrankNicolson.o:	CrankNicolson.cpp
	${CC} -c CrankNicolson.cpp

clean:
	rm -f ${TARGET1}
	rm -f *~
	rm -f *.o
