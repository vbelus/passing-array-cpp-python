CC = g++
CFLAGS = -std=c++11 -Ofast -march=native -flto
CFLAGS_BOOST = -lpython2.7 -lboost_numpy27
INCLUDES = \
-L/opt/uio/modules/packages/python/anaconda/pkgs/boost-1.70.0-py27h9de70de_1/lib \
-I/usr/include/python2.7 \
-I/opt/uio/modules/packages/python/anaconda/include

OBJ_FILES = array_cpp.o

cpp.so : $(OBJ_FILES)
	$(CC) -shared -o $@ $(OBJ_FILES) $(INCLUDES) $(CFLAGS) $(CFLAGS_BOOST)

%.o: %.cpp
	$(CC) -fPIC -o $@ -c $< $(INCLUDES) $(CFLAGS) $(CFLAGS_BOOST)

clean :
	rm array_cpp.o cpp.so
