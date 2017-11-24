#COP3514 Program Design, Project 10 Extra Credit

dealer: dealer.o car.o readline.o
	gcc -o dealer dealer.o car.o readline.o
car.o: car.c car.h
	gcc -c car.c
readline.o: readline.c readline.h
	gcc -c readline.c
dealer.o: dealer.c car.h readline.h
	gcc -c dealer.c