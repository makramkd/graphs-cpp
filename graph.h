//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "adjacency_list.h"

/**
 * A class that represents an undirected graph. There may
 * be weights on some of the edges.
 */
template<typename vertex_type = int, typename weight_type = int>
class graph {
public:
    graph()
    {

    }


private:
    adjacency_list<vertex_type, weight_type> adj_list;
};


#endif //GRAPHS_GRAPH_H
