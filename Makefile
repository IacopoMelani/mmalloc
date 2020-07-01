release: main.c
	$(CC) main.c core/**/*.c -o $(shell basename $(CURDIR)) -Wall -Wextra -pedantic -std=c99 -Wno-unknown-pragmas
debug: main.c
	$(CC) main.c core/**/*.c -o $(shell basename $(CURDIR)) -Wall -Wextra -pedantic -std=c99 -Wno-unknown-pragmas -D DEBUG