all: commands.o autobash.o main.o
	mkdir -p ./../build
	gcc commands.o autobash.o main.o -o ./../build/autobash
	$(MAKE) clean

main.o:
	gcc -c main.c

commands.o:
	gcc -c commands.c

autobash.o:
	gcc -c autobash.c
	
install:
	cp ./../build/autobash /usr/local/bin/

clean:
	rm -rf *.o
	
clean-all:
	rm -rf ./../build/