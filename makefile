string: new_string.c new_string.h main.c
	gcc -Wall -o string main.c

clean:
	rm -f *.o string
