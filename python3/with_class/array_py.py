import numpy as np
import cpp

def main():
    exponent = 5
    array = np.arange(0, 10)
    array = array.astype("double")

    C = cpp.Array_cpp(exponent)

    C.set_array(array)

    print("Compute takes array's elements to the power of {}".format(exponent))
    print("")
    print("Array before computing : {}".format(C.get_array()))
    print("")

    C.compute_exponent()

    print("Array after computing : {}".format(C.get_array()))
    print("")

    print("Same array after computing but elements are integer : {}".format(np.array(C.get_array(), dtype = "int")))
    print("")



if __name__ == "__main__":
    main()
