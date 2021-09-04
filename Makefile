CC      = clang
CFLAGS  = -Wall -Werror -g

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

test: main
	./main

clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY: clean test
