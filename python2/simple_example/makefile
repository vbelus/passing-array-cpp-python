CC = g++
CFLAGS = -std=c++11 -Ofast -march=native -flto
LIBRARIES = \
-L/opt/uio/modules/packages/python/anaconda/pkgs/boost-1.70.0-py27h9de70de_1/lib \
-lpython2.7 -lboost_numpy27

INCLUDES = \
-I/usr/include/python2.7 \
-I/opt/uio/modules/packages/python/anaconda/include

OBJ_FILES = array_cpp.o

cpp.so : $(OBJ_FILES)
	$(CC) -shared -o $@ $(OBJ_FILES) $(LIBRARIES) $(CFLAGS)

%.o: %.cpp
	$(CC) -fPIC -o $@ -c $< $(INCLUDES) $(CFLAGS)

clean :
	rm array_cpp.o cpp.so
