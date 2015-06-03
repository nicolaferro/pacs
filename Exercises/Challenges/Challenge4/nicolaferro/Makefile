CXX = ${mkCxxCompiler}
OPTFLAGS = -std=c++11
CXXFLAGS = $(OPTFLAGS) -I.
EXEC = main
EXESRCS = main.cpp
EXEOBJS = $(EXESRCS: .cpp = .o)
SRCS = polynom.cpp
OBJS = $(SRCS: .cpp =.o)
HEADERS = $(SRCS: .cpp =.hpp)

$(EXEC) $(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o polynom.o polynom.cpp
	$(CXX) -c $(CXXFLAGS) -o main.o $(EXESRCS)
	$(CXX) -o $(EXEC) main.o $(OBJS) -std=c++11

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) $(EXEC)

