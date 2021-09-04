CC      = cc
CFLAGS  = -Wall -Werror -g

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

test: $(TARGET)
	./main

clean:
	rm -rf $(TARGET) $(OBJ)
