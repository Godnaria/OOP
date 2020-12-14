all:dep
	g++ -o test1.elf test1.cpp
	g++ -o test2.elf test2.cpp Vector.o Trace.o
dep:
	g++ -c Vector.cpp -o Vector.o
	g++ -c Trace.cpp -o Trace.o
clean:
	rm -f *.o *.elf