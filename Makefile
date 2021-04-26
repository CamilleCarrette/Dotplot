##################
#ça c'est du make
##################

graphtest: dotplot.cpp
	g++ -Wpedantic $^ -o dotplot