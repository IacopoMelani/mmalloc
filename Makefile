main: main.c
	$(CC) main.c core/**/*.c -o foffo -Wall -Wextra -pedantic -std=c99 -Wno-unknown-pragmas