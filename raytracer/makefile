render: main.cc color.h.gch ray.h.gch vec3.h.gch
	g++ -std=c++14 main.cc color.h.gch ray.h.gch vec3.h.gch  -o render

color.h.gch: color.h vec3.h.gch
	g++ -c -std=c++14 color.h vec3.h.gch

ray.h.gch: ray.h vec3.h.gch
	g++ -c -std=c++14 ray.h vec3.h.gch

vec3.h.gch: vec3.h
	g++ -c -std=c++14 vec3.h 

clean:
	rm *.h.gch


