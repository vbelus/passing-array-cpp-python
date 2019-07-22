CC = g++
CFLAGS = -std=c++11 -Ofast -march=native -flto
LIBRARIES = \
 \
-lpython3.6m -lboost_numpy3

INCLUDES = \
-I/usr/include/python3.6 \

OBJ_FILES = array_cpp.o

cpp.so : $(OBJ_FILES)
	$(CC) -shared -o $@ $(OBJ_FILES) $(LIBRARIES) $(CFLAGS)

%.o: %.cpp
	$(CC) -fPIC -o $@ -c $< $(INCLUDES) $(CFLAGS)

clean :
	rm array_cpp.o cpp.so
