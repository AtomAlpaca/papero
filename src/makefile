OBJS = main.o conf.o gen.o rss.o
LIBS = -lconfig++

main: $(OBJS)
	g++ $(OBJS) -o papero $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o 

conf.o: conf.h conf.cpp
	g++ -c conf.cpp -o conf.o

gen.o: gen.h gen.cpp
	g++ -c gen.cpp -o gen.o

rss.o: rss.h rss.cpp gen.h gen.cpp
	g++ -c rss.cpp -o rss.o

clean:
	rm -rf *o papero
