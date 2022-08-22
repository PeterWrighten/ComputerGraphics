OBJS = color.o ray.o vec3.o


peray: main.o $(OBJS) vec3.h ray.h color.h 
	g++ -std=c++14 main.o $(OBJS) -o $@


clean:
	rm *.gch
	rm *.o

.PHONY clean