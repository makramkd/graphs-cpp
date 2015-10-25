//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "adjacency_list.h"

/**
 * Leveraging sfinae again.
 */
template<typename, typename, typename = void, typename = void> class graph;

/**
 * A class that represents an undirected graph. There may
 * be weights on some of the edges.
 */
template<typename vertex_type, typename weight_type>
class graph<vertex_type, weight_type, typename std::enable_if<std::is_integral<vertex_type>::value>::type,
            typename std::enable_if<std::is_integral<weight_type>::value>::type>
{
public:
    typedef typename adjacency_list<vertex_type, weight_type>::vertex_list vertex_list;
    typedef typename adjacency_list<vertex_type, weight_type>::size_type size_type;

    /**
     * Construct an empty graph.
     */
    graph()
    : adj_list()
    {

    }

    /**
     * Construct a graph with num_vertices in it.
     */
    graph(size_type num_vertices)
    : adj_list(num_vertices)
    {

    }

    /**
     * Construct a graph as a copy of another graph.
     */
    graph(const graph& other)
    : adj_list(other.adj_list)
    {

    }

    /**
     * Get the adjacency list of the given vertex.
     */
    const vertex_list& adj_list_of(vertex_type vertex) const
    {
        return adj_list[vertex];
    }

    /**
     * Get the degree of the given vertex.
     */
    size_type degree_of(vertex_type vertex) const
    {
        return adj_list[vertex].size();
    }

    /**
     * Get the average degree of vertices in this graph.
     */
    double avg_degree() const
    {
        return adj_list.average_degree();
    }

    /**
     * Get the maximum degree over the degrees of all
     * vertices in this graph.
     */
    size_type max_degree() const
    {
        return adj_list.max_degree();
    }

    /**
     * Get the minimum degree over the degrees of all
     * vertices in this graph.
     */
    size_type min_degree() const
    {
        return adj_list.min_degree();
    }

    /**
     * Add a vertex to this graph.
     */
    void add_vertex(vertex_type vertex)
    {
        adj_list.add_vertex(vertex);
    }

    /**
     * Add an edge to this graph, with an optional weight.
     */
    void add_edge(vertex_type v1, vertex_type v2, weight_type w = 0)
    {
        adj_list.add_edge(v1, v2, w);
    }

    /**
     * Remove a vertex from this graph, as well as
     * all incident edges.
     */
    void remove_vertex(vertex_type vertex)
    {
        adj_list.remove_vertex(vertex);
    }

    /**
     * Remove an edge from this graph.
     */
    void remove_edge(vertex_type v1, vertex_type v2)
    {
        adj_list.remove_edge(v1, v2);
    }

    /**
     * Return the number of edges in this graph.
     */
    size_type edges() const
    {
        return adj_list.edge_count();
    }

    /**
     * Return the number of vertices in this graph.
     */
    size_type vertices() const
    {
        return adj_list.vertex_count();
    }

    bool adjacent(vertex_type v1, vertex_type v2) const
    {
        return adj_list.adjacent_to(v1, v2);
    }
private:
    adjacency_list<vertex_type, weight_type> adj_list;
};


#endif //GRAPHS_GRAPH_H
