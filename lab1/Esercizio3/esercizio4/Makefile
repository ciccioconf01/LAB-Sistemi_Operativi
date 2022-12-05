DIO=gcc
CRISTO=-c

target1:
	$(DIO) $(CRISTO) E04.c

Install: target 
	mkdir ../bin
	cp eseguibile ../bin
	cp E04.o ../bin
	rm E04.o eseguibile
target:
	$(DIO) $(CRISTO) E04.c
	$(DIO) -o eseguibile E04.o

clean:
	rm E04.o
distClean: 
	rm -r ../bin

