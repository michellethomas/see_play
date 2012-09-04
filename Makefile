CFLAGS=-I/Users/michelle/play/see_play/
stack: rpn_calculator.o
	gcc -o stack rpn_calculator.o

list: my_list.o
	gcc -o list my_list.o

rpn_calculator.o: rpn_calculator.c stack.h
	gcc -c $(CFLAGS) rpn_calculator.c

my_list.o: my_list.c list.h
	gcc -c $(CFLAGS) my_list.c
