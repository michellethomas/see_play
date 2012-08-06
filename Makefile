CFLAGS=-I/Users/michelle/play/see_play/
stack: rpn_calculator.o
	gcc -o stack rpn_calculator.o

rpn_calculator.o: rpn_calculator.c stack.h
	gcc -c $(CFLAGS) rpn_calculator.c

