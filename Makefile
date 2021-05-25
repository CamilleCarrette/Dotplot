##################
#ça c'est du make
##################

graphtest: dotplot.cpp
	g++ -Wpedantic $^ -o dotplot

mostlyclean :
	rm -rf *.o *.dat

clean : 
	rm -rf *.o *.dat dotplot.png