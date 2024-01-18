CC = clang
CFLAGS = -g
SRCDIR = ./src/
DEPS = list.h
OBJ = list.o test.o

%.o: $(SRCDIR)%.c
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o test