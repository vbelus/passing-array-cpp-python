
- You can also open a python terminal in the directory of cpp.so and type `import cpp`
- You can then use functions from the file `array_cpp.cpp`, such as `cpp.square()` which squares the values of a numpy.ndarray

You can define your own functions in c++ but you have to let boost know that you want to use them in Python :
```
BOOST_PYTHON_MODULE(cpp)
{
    Py_Initialize();
    np::initialize();
    def("square", square_array_from_py);
}
```
Here the only function you can use is `square_array_from_py`, renamed as `square` when using it in Python

## More info

Please read [Python_Programming/Extending_with_C](https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C%2B%2B) for more details
For more information about adding you own functions or class, [here for functions not in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/index.html) and [in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/tutorial/exposing.html) 
