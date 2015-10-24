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
    typedef typename adjacency_list<vertex_type, weight_type>::size_type size_type;

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

    const vertex_list& adj_list_of(vertex_type vertex) const
    {
        return adj_list[vertex];
    }

    size_type degree_of(vertex_type vertex) const
    {
        return adj_list[vertex].size();
    }

    double avg_degree() const
    {
        return adj_list.average_degree();
    }

    size_type max_degree() const
    {
        return adj_list.max_degree();
    }

    size_type min_degree() const
    {
        return adj_list.min_degree();
    }

    void add_vertex(vertex_type vertex)
    {
        adj_list.add_vertex(vertex);
    }

    void add_edge(vertex_type v1, vertex_type v2, weight_type w = 0)
    {
        adj_list.add_edge(v1, v2, w);
    }

    void remove_vertex(vertex_type vertex)
    {
        adj_list.remove_vertex(vertex);
    }

    void remove_edge(vertex_type v1, vertex_type v2)
    {
        adj_list.remove_edge(v1, v2);
    }

    size_type edges() const
    {
        return adj_list.edge_count();
    }

    size_type vertices() const
    {
        return adj_list.vertex_count();
    }
private:
    adjacency_list<vertex_type, weight_type> adj_list;
};


#endif //GRAPHS_GRAPH_H
