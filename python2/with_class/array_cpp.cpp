#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <valarray>
#include <cmath>

namespace p = boost::python;
namespace np = boost::python::numpy;

class Array_cpp
{
private:
    std::valarray<double> valarray;
    int exponent;

public:
    // Constructor
    Array_cpp(int exponent_from_py)
    {
        exponent = exponent_from_py;
    }

    // Member functions
    void set_array(np::ndarray array_from_py);
    void compute_exponent();
    np::ndarray to_ndarray(std::valarray<double> & valarray_to_numpy);
    np::ndarray get_array();
};

void Array_cpp::set_array(np::ndarray array_from_py)
{
  int len_array_from_py = array_from_py.shape(0);
  std::valarray<double> new_valarray(len_array_from_py);
  for(int i=0; i<len_array_from_py; i++)
  {
    new_valarray[i] = p::extract<double>(array_from_py[i]);
  }
  valarray = new_valarray;
}

// Takes every element of array to given exponent
void Array_cpp::compute_exponent()
{
  for(unsigned int i = 0; i < valarray.size(); i++)
  {
    valarray[i] = std::pow(valarray[i], exponent);
  }
}

// Takes valarray, returns np::ndarray - it's a deep copy
np::ndarray Array_cpp::to_ndarray(std::valarray<double> & valarray_to_numpy)
{
    int array_size = valarray_to_numpy.size();
    p::tuple shape = p::make_tuple(array_size);
    p::tuple stride = p::make_tuple(sizeof(double));
    np::dtype dt = np::dtype::get_builtin<double>();
    np::ndarray ndarray = np::from_data(&valarray_to_numpy[0], dt, shape, stride, p::object());
    return ndarray.copy();
}

// Return array to Python
np::ndarray Array_cpp::get_array()
{
  return Array_cpp::to_ndarray(valarray);
}


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
