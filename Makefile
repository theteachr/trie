CC      = cc
CFLAGS  = -Wall -Werror -g

INCLUDE = include/
SRC     = $(wildcard src/*.c) main.c
OBJ     = $(SRC:.c=.o)
TARGET  = bin/main

%.o: %.c
	$(CC) -I $(INCLUDE) -c $< -o $@

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

test: $(TARGET)
	bin/main

clean:
	rm -rf $(TARGET) $(OBJ)
