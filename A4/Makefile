CC = g++ --std=c++11

all: Scheduler.out

Scheduler.out: main.o computer.o core.o process.o thread.o
	${CC} main.o computer.o core.o process.o thread.o

main.o: main.o computer.h core.h process.h thread.h
	${CC} -c main.cpp

computer.o: computer.cpp computer.h core.h process.h thread.h
	${CC} -c computer.cpp

core.o: core.cpp core.h computer.h process.h thread.h
	${CC} -c core.cpp

process.o: process.cpp process.h core.h computer.h thread.h
	${CC} -c process.cpp

thread.o: thread.cpp thread.h core.h computer.h process.h
	${CC} -c thread.cpp

.PHONY: clean
clean:
	rm *.o 
	rm Scheduler.out
