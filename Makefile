CC = clang
CFLAGS = -g
SRCDIR = ./src/
DEPS = DataHolder.h list.h
OBJ = DataHolder.o list.o test.o

%.o: $(SRCDIR)%.c
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o test