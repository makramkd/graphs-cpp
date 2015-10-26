//
// Created by Makram Kamaleddine on 10/25/15.
//

#ifndef GRAPHS_MATRIX_H
#define GRAPHS_MATRIX_H

#include <type_traits>
#include <vector>

template<typename, const unsigned int, const unsigned int, typename = void> class matrix;

template<typename T, const unsigned int N, const unsigned int M>
class matrix<T, N, M, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
public:
    matrix()
    :vec(N * M),
     rows(N),
     columns(M)
    {

    }

    matrix(T filler)
    : vec(N * M),
      rows(N),
      columns(M)
    {
        std::fill(vec.begin(), vec.end(), filler);
    }

    matrix(const matrix& other)
    : vec(other.vec),
      rows(other.rows),
      columns(other.columns)
    {

    }

    T& operator()(unsigned int i, unsigned int j)
    {
        return vec[i * columns + j];
    }

private:
    std::vector<T> vec;
    unsigned int rows;
    unsigned int columns;
};


#endif //GRAPHS_MATRIX_H
