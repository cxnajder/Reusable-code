#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // adds ostream_iterator
#include <numeric>  // adds iota

// PRINT VECTOR OPTION 1

template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for ( size_t n = vec.size(); T vec_element: vec )
        std::cout << vec_element << ( --n ? " " : "" );
    return strm;
}


int main( void )
{
  std::vector<int> vec(3);
  std::iota( vec.begin(), vec.end(), 1 );

  std::cout << "Original vector : ";
  std::cout << vec << '\n';

  std::vector<int> test_vec(6);
  std::fill(test_vec.begin(), test_vec.end(), 0);

// COPY

  std::copy( vec.begin(), vec.end(), test_vec.begin() );
  std::cout << "copy begin : ";
  std::cout << test_vec << '\n';
  std::fill(test_vec.begin(), test_vec.end(), 0);


  std::copy( vec.begin(), vec.end(), test_vec.rbegin() );
  std::cout << "copy rbegin : ";
  std::cout << test_vec << '\n';
  std::fill(test_vec.begin(), test_vec.end(), 0);


  // COPY BACKWORD

  std::copy_backward( vec.begin(), vec.end(), test_vec.end() );
  std::cout << "copy backwrd end : ";
  std::cout << test_vec << '\n';
  std::fill(test_vec.begin(), test_vec.end(), 0);


  std::copy_backward( vec.begin(), vec.end(), test_vec.rend() );
  std::cout << "copy backwrd rend : ";
  std::cout << test_vec << '\n';
  std::fill(test_vec.begin(), test_vec.end(), 0);


}
