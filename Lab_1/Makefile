CC = gcc
CFLAGS = -Wall -Wextra 
CHILDSOURCE = child_process.c
CHILDOUT = bin/child_process
MAINSOURCE = main.c
MAINOUT = bin/main


main:
	$(CC) $(CFLAGS) $(MAINSOURCE) -o $(MAINOUT)

child:
	$(CC) $(CFLAGS) $(CHILDSOURCE) -o $(CHILDOUT)

clean:
	rm -fv bin/*

run:
	./$(MAINOUT)



