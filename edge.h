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
template<typename size_type = unsigned int,
        typename id_type = int>
struct edge {
    id_type v1;
    id_type v2;
    size_type weight;
};


#endif //GRAPHS_EDGE_H
