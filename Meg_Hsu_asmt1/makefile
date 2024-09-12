CXX = g++
CXXFLAGS = -std=c++11

PROG = mainProgram.cpp myLibrary.cpp testing.cpp
OBJS = ${PROG:.cpp=.o}
HEADERS = myLibrary.h testing.h

MAIN = main

${MAIN}:${OBJS}
	${CXX} -o ${MAIN} ${OBJS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} ${MAIN} *.o *~.