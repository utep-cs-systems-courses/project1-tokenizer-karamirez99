CFLAGS = -g -O3 

all:
	lab1

history.o: history.h
tokenizer.o: tokenizer.h

lab1: ui.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

test:
	cc -o Test tester.c tokenizer.c history.c

clean:
	rm -f *.o lab1
