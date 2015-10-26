//
// Created by Makram Kamaleddine on 10/25/15.
//

#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

#include <type_traits>
#include "matrix.h"

template<typename, typename, const unsigned int, typename = void, typename = void> class adjacency_matrix;

template<typename vertex_type, typename weight_type, const int N>
class adjacency_matrix<vertex_type, weight_type, std::enable_if<std::is_integral<vertex_type>::value>::type,
                       std::enable_if<std::is_integral<weight_type>::value>::type>
{
public:
    adjacency_matrix()
    : adj_matrix()
    {

    }


private:
    matrix<weight_type, N, N> adj_matrix;
};


#endif //GRAPHS_ADJACENCY_MATRIX_H
