## What it does
This snippet of code shows you how to use your own C++ functions on a numpy array instancied in Python
You will find two simple examples on which you can expand :
- one with a simple c++ function to square the values of a numpy array
- one with an oop approach

## Why
The initial problem appeared when training RL models on fluid mechanics problems and more generally on simulations where returning the next step of the environment is very costly due to complex numerical schemes. Solving these numerical schemes in Python makes it the bottleneck of the program
A good implementation of said numerical scheme on c++ can be a solution then - we still use Python to handle the environment and model with openai-gym for example

It can of course be used for other means

## You will need
The library boost python, and you'll need to change`LIBRARIES` and `INCLUDES` in the makefile to match your boost local path
If you have a clean installation of python3.6, the python3 example should work as it is

(On UiO computers, type `module load python/anaconda` in terminal and it will work as it is for python2)
