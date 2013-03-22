CXX = g++
CXXFLAGS = -Wall -g
OFILES = Circle.o Corpus.o Loop.o Modeller.o Text.o driver.o
.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~

# The following lines define the dependencies for this lab.  For
# example, if avltree.h is modified, then make knows to re-compile
# avltree.o and tree_test.o (and the final executable).  These lines
# are generated through the command 'g++ -MM *.cpp', and that output
# is pasted below.
Circle.o: Circle.cpp Circle.h Corpus.h Text.h
Corpus.o: Corpus.cpp Text.h Corpus.h
Loop.o: Loop.cpp Loop.h
Modeller.o: Modeller.cpp Modeller.h Circle.h Corpus.h Text.h Loop.h
Text.o: Text.cpp Text.h
driver.o: driver.cpp Text.h Corpus.h Circle.h Loop.h Modeller.h
