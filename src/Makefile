
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O3
LDFLAGS = -lm -s

SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=./koch


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) -o $@ -c  $< $(CFLAGS)

cleanobj:
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)

run: all
	$(EXEC) 270 4 0xFF0000 0xFFFFFF koch.ppm all
