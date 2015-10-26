//
// Created by Makram Kamaleddine on 10/25/15.
//

#ifndef GRAPHS_INCIDENCE_MATRIX_H
#define GRAPHS_INCIDENCE_MATRIX_H

#include "matrix.h"

template<const unsigned int N, const unsigned int M>
class incidence_matrix {
public:
    incidence_matrix()
    : inc_matrix(),
      vertex_count_(N),
      edge_count_(M)
    {

    }


private:
    matrix<unsigned int, N, M> inc_matrix;
    unsigned int vertex_count_;
    unsigned int edge_count_;
};


#endif //GRAPHS_INCIDENCE_MATRIX_H
