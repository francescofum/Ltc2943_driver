CC=gcc
CFLAGS=-I. -O0 -g -Wall
DEPS = Ltc2943.h IChipCtrl.h
OBJDIR=./obj

# $(OBJDIR):
# 	mkdir -p $(OBJDIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

Ltc2943: main.o Ltc2943.o
	$(CC) -o main.exe main.o Ltc2943.o


clean:
	rm -f  main.o Ltc2943.o main.exe
