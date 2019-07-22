import numpy as np
import cpp

def square(array):
    return cpp.square(array.astype('double'))

def main():
    array_py = np.arange(0, 10)

    print("")
    print("Array before c++ operations : {}". format(array_py))
    print(array_py.__class__)
    print("")

    array_squared = square(array_py)

    print("Array after c++ operations : {}". format(array_squared))
    print(array_squared.__class__)

if __name__ == "__main__":
    main()
