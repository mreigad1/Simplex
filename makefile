LIBS=-pthread
all: cirrus

sharpen: main.cpp cirrus.cpp
	g++ main.cpp cirrus.cpp ${LIB_PATHS} ${LIBS} -o cirrusTest

.PHONY:clean

clean:
	rm cirrusTest
