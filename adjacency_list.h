//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_H

#include <vector>
#include "edge.h"

/**
 * A class that represents an adjacency list. An adjacency list
 * is one possible way to store the information about a graph.
 *
 * It consists of a list of vertices in the graph, and each element
 * in the list is a list of the vertices that are adjacent to that
 * respective vertex.
 */
template<typename vertex_type = int, typename weight_type = int>
class adjacency_list {
public:
    typedef std::vector<int> vector_list;

    adjacency_list();

    /**
     * Add a vertex to this adjacency list.
     */
    void add_vertex(vertex_type vertex);

    /**
     * Remove a vertex and all outgoing edges from it in this adjacency list.
     */
    void remove_vertex(vertex_type vertex);

    /**
     * Add an edge to this adjacency list. If the edge is in
     * the graph, nothing is done.
     */
    void add_edge(const edge<vertex_type>& edge);

    /**
     * Add an edge that connects vertices v1 and v2. If such an
     * edge already exists, do nothing.
     */
    void add_edge(vertex_type v1, vertex_type v2);

    /**
     * Remove an edge from this graph and if it is not in this graph,
     * do nothing.
     */
    void remove_edge(const edge<vertex_type>& edge);

    /**
     * Remove the edge that connects v1 and v2 from this adjacency list.
     * If the edge does not exist in the graph, do nothing.
     */
    void remove_edge(vertex_type v1, vertex_type v2);

private:

};


#endif //GRAPHS_ADJACENCY_LIST_H
