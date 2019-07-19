## What it does
This snippet of code shows you how to make operations with c++ functions to a numpy array instancied in Python

## Why
The initial problem appeared when training RL models on fluid mechanics problems and more generally on simulations where returning the next step of the environment is very costly due to complex numerical schemes.
A good implementation of said numerical scheme on c++ can be a solution then, as it is the bottleneck of the model training - we still use Python to handle the environment and model with openai-gym for example

It can of course be used for other means

## You will need
The library boost python, and you'll need to change`LIBRARIES` and `INCLUDES` in the makefile to match your boost local path
(On UiO computers, boost is preinstalled, type `module load python/anaconda` in terminal and it will work as it is)

## Test it
- After you have changed the makefile, open a terminal in its directory and type `make`
- Then you can execute the script `array_py.py` 
- You can also open a python terminal in the directory of cpp.so and type `import cpp`

You can for example : 
- Create an instance of the class Array_cpp with `C = cpp.Array_cpp(5)`
- Then `C.set_array(array)` will make `array` a data member of `C`
- `C.compute_exponent()` will take elements of `array` (as a data member of `C`) to the power of 5 (argument of the constructor)
- `C.get_array()` will return the `array` data member, you can see that its elements have been taken to the power of 5 

## More info

Please read [Python_Programming/Extending_with_C](https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C%2B%2B) for more details
For more information about adding you own functions or class, [here for functions not in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/index.html) and [in a class](https://www.boost.org/doc/libs/1_68_0/libs/python/doc/html/tutorial/tutorial/exposing.html) 
