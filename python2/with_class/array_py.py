import numpy as np
import cpp

def main():
    exponent = 5
    array = np.arange(0, 10)

    C = cpp.Array_cpp(exponent)

    C.set_array(array)

    print(C.get_array())

    C.compute_exponent()

    print(C.get_array())

if __name__ == "__main__":
    main()
