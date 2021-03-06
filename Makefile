CFLAGS=-I/usr/local/include
ARC=-DARC64
F_CPU=16000000UL
DEVICE=atmega328p
all: clean
	avr-gcc -c -g $(ARC) $(CFLAGS) -D__AVR -std=c11 -DF_CPU=$(F_CPU) -Os -mmcu=$(DEVICE) -o tmp_io.o tmp_io.c
	ar rc lib/libtmp_io.a tmp_io.o
	cp tmp_io.h inc

debug: clean
	gcc -std=gnu11 -c $(ARC) $(CFLAGS) -Wall -o tmp_io.o tmp_io.c
	gcc -std=gnu11 $(ARC) $(CFLAGS) -Iinc -Llib -o debug debug.c tmp_io.o -lpthread -lm
clean:
	rm -f *.o *.exec debug
	rm -f inc/mdl/* lib/*
