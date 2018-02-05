all: makepic.c
	gcc -o create makepic.c

run: makepic
	make all
	./create
	display mypic.ppm

clean:
	rm *.ppm
	rm create
	rm *.~

