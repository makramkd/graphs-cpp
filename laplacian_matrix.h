//
// Created by Makram Kamaleddine on 10/25/15.
//

#ifndef GRAPHS_LAPLACIAN_MATRIX_H
#define GRAPHS_LAPLACIAN_MATRIX_H

#include "matrix.h"

template<const unsigned int N>
class laplacian_matrix {
public:
    laplacian_matrix()
    :laplace()
    {

    }

private:
    matrix<int, N, N> laplace;
};


#endif //GRAPHS_LAPLACIAN_MATRIX_H
