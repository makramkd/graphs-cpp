//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_H

#include "edge.h"

/**
 * A class that represents an adjacency list. An adjacency list
 * is one possible way to store the information about a graph.
 *
 * It consists of a list of vertices in the graph, and each element
 * in the list is a list of the vertices that are adjacent to that
 * respective vertex.
 */
class adjacency_list {
public:
    adjacency_list();

    /**
     * Add a vertex to this adjacency list.
     */
    void add_vertex(int vertex);

    /**
     * Remove a vertex and all outgoing edges from it in this adjacency list.
     */
    void remove_vertex(int vertex);

    /**
     * Add an edge to this adjacency list. If the edge is in
     * the graph, nothing is done.
     */
    void add_edge(const edge& edge);

    /**
     * Add an edge that connects vertices v1 and v2. If such an
     * edge already exists, do nothing.
     */
    void add_edge(int v1, int v2);

    /**
     * Remove an edge from this graph and if it is not in this graph,
     * do nothing.
     */
    void remove_edge(const edge& edge);

    /**
     * Remove the edge that connects v1 and v2 from this adjacency list.
     * If the edge does not exist in the graph, do nothing.
     */
    void remove_edge(int v1, int v2);

private:

};


#endif //GRAPHS_ADJACENCY_LIST_H
