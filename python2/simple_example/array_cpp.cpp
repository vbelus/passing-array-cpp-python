#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <valarray>

namespace p = boost::python;
namespace np = boost::python::numpy;

// Takes np::ndarray, returns valarray - it's a deep copy
std::valarray<double> to_valarray(np::ndarray & array_from_py)
{
  int len_array_from_py = array_from_py.shape(0);
  std::valarray<double> valarray(len_array_from_py);
  for(int i=0; i<len_array_from_py; i++)
  {
    valarray[i] = p::extract<double>(array_from_py[i]);
  }
  return valarray;
}

// Takes valarray, returns np::ndarray - it's a deep copy
np::ndarray to_ndarray(std::valarray<double> & valarray)
{
    int array_size = valarray.size();
    p::tuple shape = p::make_tuple(array_size);
    p::tuple stride = p::make_tuple(sizeof(double));
    np::dtype dt = np::dtype::get_builtin<double>();
    np::ndarray ndarray = np::from_data(&valarray[0], dt, shape, stride, p::object());
    return ndarray.copy();
}

// Squares all elements of a valarray
void square_valarray(std::valarray<double> & valarray)
{
  for(int i = 0; i<valarray.size(); i++)
  {
    valarray[i] = valarray[i]*valarray[i];
  }
}

// The function called by Python
np::ndarray square_array_from_py(np::ndarray & array_from_py)
{
  std::valarray<double> valarray = to_valarray(array_from_py); // We create a valarray, copy of the ndarray from Python
  square_valarray(valarray);                                   // We square the values of the valarray
  np::ndarray array_to_py = to_ndarray(valarray);              // We create a ndarray, copy of the valarray and return it
  return array_to_py;
}


BOOST_PYTHON_MODULE(cpp)
{
    Py_Initialize();
    np::initialize();
    def("square", square_array_from_py);
}
