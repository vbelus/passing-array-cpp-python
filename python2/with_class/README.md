
- You can also open a python terminal in the directory of cpp.so and type `import cpp`
- You can create an object of the C++ class with `C = cpp.Array_cpp(5)`
- You can then call the member functions of the class : `C.set_array(array)`, `C.compute_exponent()`, `C.get_array()`

You can define your own classes in c++ but you have to let boost know that you want to use them in Python :
```
BOOST_PYTHON_MODULE(cpp)
{
    Py_Initialize();
    np::initialize();
    p::class_<Array_cpp>("Array_cpp", p::init<int>())
        .def("set_array", &Array_cpp::set_array)
        .def("get_array", &Array_cpp::get_array)
        .def("compute_exponent", &Array_cpp::compute_exponent)
    ;
}
```

## More info

Please read [Python_Programming/Extending_with_C](https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C%2B%2B) for more details
For more information about adding you own functions or class, [here for functions not in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/index.html) and [in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/tutorial/exposing.html) 
