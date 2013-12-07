Mam22: main.o mat.o
	gcc main.o mat.o -o Mam22

main.o: main.c mat.h
	gcc -c -g -Wall -ansi -pedantic main.c

mat.o: mat.c mat.h
	gcc -c -g -Wall -ansi -pedantic mat.c

clean:
	-rm -f *.o Mam22
	
test: Mam22
	-rm -f output
	./Mam22.exe <input>output
