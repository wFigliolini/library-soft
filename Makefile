CC = clang
CFLAGS = 
DEPS = utils/list.h
OBJ = list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o test