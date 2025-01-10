#315CA-Neacsa Leonard
CC = gcc
CFLAGS = -lm -Wall -Wextra -g
SRC = main.c alloc_free.c write_read.c errors.c grid.c resize.c init_contur.c march.c
EXE = marching_squares

build:
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

debug:
	valgrind ./$(EXE)
pack:
	zip -FSr 315CA_LeonardNeacsa_Tema2.zip README Makefile *.c *.h
clean:
	rm -f $(EXE)
.PHONY: pack clean