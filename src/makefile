OBJS = main.o conf.o gen.o
LIBS = -lconfig++

main: $(OBJS)
	g++ $(OBJS) -o papero $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o 

conf.o: conf.h conf.cpp
	g++ -c conf.cpp -o conf.o

gen.o: gen.h gen.cpp
	g++ -c gen.cpp -o gen.o

clean:
	rm -rf *o papero
