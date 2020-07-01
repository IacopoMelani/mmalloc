main: main.c
	$(CC) main.c core/**/*.c -o $(shell basename $(CURDIR)) -Wall -Wextra -pedantic -std=c99 -Wno-unknown-pragmas