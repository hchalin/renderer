CC = g++
CFLAGS = -std-c++11


PROG1 = main

PROGS = ${PROG1}

all: ${PROGS}

${PROG1}: ${PROG1}.o
	${CC} ${CFLAGS} -o ${PROG1} ${PROG1}.o
	chmod og+x ${PROG1}

${PROG1}.o: ${PROG1}.cpp
	${CC}  -c ${PROG1}.cpp



clean cls:
	rm -f ${PROGS} *.o *~ \#*
