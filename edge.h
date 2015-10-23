//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_EDGE_H
#define GRAPHS_EDGE_H


/**
 * A class that is supposed to represent an edge in an
 * undirected graph. The edge could have a weight: if
 * it doesn't, it's weight would be 0.
 */
template<typename vertex_type = int,
        typename weight_type = int>
struct edge {
    vertex_type v1;
    vertex_type v2;
    weight_type weight;
};

/**
 * A class that is supposed to represent an edge in an
 * undirected graph. The edge could have a weight: if
 * it doesn't, it's weight would be 0.
 */
template<typename vertex_type = int,
        typename weight_type = int>
struct d_edge {
    vertex_type from;
    vertex_type to;
    weight_type weight;
};


#endif //GRAPHS_EDGE_H
