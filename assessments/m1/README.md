[![m1](https://github.com/alainguimaraes/ese-coursera-course1/actions/workflows/m1.yml/badge.svg)](https://github.com/alainguimaraes/ese-coursera-course1/actions/workflows/m1.yml)
# Statistics Functions

Author: Alain Guimarães

This project contains a set of functions to perform basic statistical analysis on a dataset of unsigned char values.

## Functions

The following functions are provided:

1. `print_statistics(unsigned char *ptr, unsigned int size)`: Prints the minimum, maximum, mean, and median values of the input array, along with their corresponding indices.

2. `print_array(unsigned char *ptr, unsigned int size)`: Prints the values in the input array.

3. `find_minimum_index(unsigned char *ptr, unsigned int size)`: Finds the index of the minimum value in the input array.

4. `find_maximum_index(unsigned char *ptr, unsigned int size)`: Finds the index of the maximum value in the input array.

5. `find_median_index(unsigned char *ptr, unsigned int size)`: Finds the index of the median value in the input array.

6. `find_median(unsigned char *ptr, unsigned int size)`: Finds the median value in the input array.

7. `find_mean(unsigned char *ptr, unsigned int size)`: Finds the mean value of the input array.

8. `find_maximum(unsigned char *ptr, unsigned int size)`: Finds the maximum value in the input array.

9. `find_minimum(unsigned char *ptr, unsigned int size)`: Finds the minimum value in the input array.

10. `sort_array(unsigned char *ptr, unsigned int size)`: Sorts the input array in ascending order.

## Usage

To use the functions, include the `stats.h` header file in your C code and call the desired functions, passing in the appropriate parameters.

## Testing

Additionally, a GitHub Actions workflow is set up to automatically run the tests whenever changes are pushed to the repository.

## Contributing

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

Alain Guimarães
