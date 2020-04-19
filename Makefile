all : main

base.o : base.c
	gcc -c base.c -I.

extras.o : extras.c
	gcc -c extras.c -I.

main.o : main.c
	gcc -c main.c -I.

main : base.o extras.o main.o
	gcc -o main base.o extras.o main.o

clean : 
	rm *.o
	rm main

	
