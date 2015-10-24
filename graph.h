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
    typedef typename adjacency_list<vertex_type, weight_type>::vertex_list vertex_list;
    graph()
    : adj_list()
    {

    }

    graph(int num_vertices)
    : adj_list(num_vertices)
    {

    }

    graph(const graph& other)
    : adj_list(other.adj_list)
    {

    }

    vertex_list adjList(vertex_type vertex)
    {
        return adj_list[vertex];
    }

private:
    adjacency_list<vertex_type, weight_type> adj_list;
};


#endif //GRAPHS_GRAPH_H
