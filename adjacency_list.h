//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_ADJACENCY_LIST_H
#define GRAPHS_ADJACENCY_LIST_H

#include <vector>
#include <map>
#include <numeric>
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
    /**
     * The type that will be held inside the adjacency list:
     * it is actually a list of lists.
     */
    typedef std::vector<vertex_type> vertex_list;
    typedef unsigned long size_type;

    /**
     * Construct an empty adjacency list.
     */
    adjacency_list()
    :adj_list()
    {

    }

    /**
     * Construct an adjacency list with the given vertex
     * count.
     */
    adjacency_list(size_type vertex_count)
    :adj_list(vertex_count),
     next_vertex(vertex_count + 1),
     vertex_map()
    {

    }

    /**
     * Construct an adjacency list as a copy of another
     * adjacency list.
     */
    adjacency_list(const adjacency_list& other)
    :adj_list(other.adj_list),
     next_vertex(other.next_vertex),
     vertex_map(other.vertex_map)
    {

    }

    /**
     * Add a vertex to this adjacency list.
     */
    void add_vertex(vertex_type vertex)
    {
        // look for the vertex
        if (vertex_map.find(vertex) != vertex_map.end()) {
            return; // already in the graph
        }

        vertex_map[vertex] = next_vertex;
        next_vertex++;

        // push back a new vertex list: this will be the adjacency list of the
        // new vertex
        adj_list.push_back(vertex_list());
    }

    /**
     * Remove a vertex and all outgoing edges from it in this adjacency list.
     */
    void remove_vertex(vertex_type vertex)
    {

    }

    /**
     * Add an edge to this adjacency list. If the edge is in
     * the graph, nothing is done.
     */
    void add_edge(const edge<vertex_type, weight_type>& edge)
    {
        // make sure that both v1 and v2 are in the graph
        // maybe in the future we can make this easier and
        // add vertices through adding edges
        auto find_v1 = vertex_map.find(edge.v1);
        auto find_v2 = vertex_map.find(edge.v2);
        if (find_v1 == vertex_map.end() || find_v2 == vertex_map.end()) {
            return; // one of the vertices is not in the graph
        }

        auto index_v1 = vertex_map[edge.v1];
        auto index_v2 = vertex_map[edge.v2];

        // add the vertices to their respective adjacency lists
        adj_list[index_v1].push_back(edge.v2);
        adj_list[index_v2].push_back(edge.v1);
    }

    /**
     * Add an edge that connects vertices v1 and v2. If such an
     * edge already exists, do nothing.
     */
    void add_edge(vertex_type v1, vertex_type v2)
    {
        edge<vertex_type, weight_type> e;
        e.v1 = v1;
        e.v2 = v2;
        add_edge(e);
    }

    /**
     * Remove an edge from this graph and if it is not in this graph,
     * do nothing.
     */
    void remove_edge(const edge<vertex_type, weight_type>& edge)
    {

    }

    /**
     * Remove the edge that connects v1 and v2 from this adjacency list.
     * If the edge does not exist in the graph, do nothing.
     */
    void remove_edge(vertex_type v1, vertex_type v2)
    {

    }

    /**
     * Get the list of vertices adjacent to the given vertex.
     * If the vertex is not in the adjacency list an exception
     * may be thrown.
     */
    const vertex_list& operator[](vertex_type vertex) const
    {
        return adj_list[vertex_map[vertex]];
    }

    /**
     * Returns the average degree of vertices in this graph.
     */
    double average_degree() const
    {
        auto sum = std::accumulate(adj_list.begin(), adj_list.end(), 0.0,
                    [](const vertex_list& left, const vertex_list& right) {
                        return left.size() + right.size();
                    });
        return sum / adj_list.size();
    }

    size_type max_degree() const
    {
        auto max = std::max_element(adj_list.begin(), adj_list.end(),
                    [](const vertex_list& left, const vertex_list& right) {
                        return left.size() < right.size();
                    });
        return max == adj_list.end() ? -1 : *max;
    }
private:
    // the adjacency list itself.
    std::vector<vertex_list> adj_list;

    // since vertex types can be pretty much anything (strings, floating point numbers, etc)
    // we need to map them to integers so that we can use them
    // to index into the vector above
    std::map<vertex_type, size_type> vertex_map;

    // this will hold the integer key of the next vertex that will be inserted.
    // we will start from 0 and increment it by 1 each time a vertex is added.
    size_type next_vertex;
};


#endif //GRAPHS_ADJACENCY_LIST_H
