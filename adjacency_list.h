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
 * Adapting the adjacency_list class so that we can use sfinae.
 */
template<typename, typename, typename = void, typename = void> class adjacency_list;

/**
 * A class that represents an adjacency list. An adjacency list
 * is one possible way to store the information about a graph.
 *
 * It consists of a list of vertices in the graph, and each element
 * in the list is a list of the vertices that are adjacent to that
 * respective vertex.
 */
template<typename vertex_type, typename weight_type>
class adjacency_list<vertex_type, weight_type, typename std::enable_if<std::is_integral<vertex_type>::value>::type,
                    typename std::enable_if<std::is_integral<weight_type>::value>::type>
{
public:

    // we need to hold the vertex id
    // and the weight of the edge to that vertex
    struct adjacent_vertex {
        vertex_type vertex;
        weight_type weight;
    };

    /**
     * The type that will be held inside the adjacency list. It is
     * list of adjacent_vertex objects that each vertex in the
     * graph will have.
     */
    typedef std::vector<adjacent_vertex> vertex_list;
    typedef unsigned long size_type;

    /**
     * Construct an empty adjacency list.
     */
    adjacency_list()
    :adj_list(),
     next_vertex(0),
     vertex_map(),
     num_edges(0)
    {

    }

    /**
     * Construct an adjacency list with the given vertex
     * count.
     */
    adjacency_list(size_type vertex_count)
    :adj_list(vertex_count),
     next_vertex(vertex_count),
     vertex_map(),
     num_edges(0)
    {
        // fill up the map
        for (unsigned long i = 0; i < vertex_count; ++i) {
            vertex_map[i] = i;
        }
    }

    /**
     * Construct an adjacency list as a copy of another
     * adjacency list.
     */
    adjacency_list(const adjacency_list& other)
    :adj_list(other.adj_list),
     next_vertex(other.next_vertex),
     vertex_map(other.vertex_map),
     num_edges(other.num_edges)
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
        if (vertex_map.find(vertex) == vertex_map.end()) {
            return; // vertex not in graph
        }

        // we need to erase the entry of this vertex
        // in the adjacency list, as well as all occurences
        // of this vertex in the adjacency list of other vertices
        auto index = vertex_map[vertex];

        // remove all occurrences of this vertex in
        // the adjacency list except for that particular
        // index
        auto begin = vertex_map[0];
        auto end = vertex_map[adj_list.size() - 1];
        for (auto idx = begin; idx != end; ++idx) {
            if (idx == index) {
                continue; // don't do anything to this index: will remove later
            } else {
                auto& v_list = adj_list[idx];
                auto iter = std::remove_if(v_list.begin(), v_list.end(), [&vertex](const adjacent_vertex& v1) {
                    return v1.vertex == vertex;
                });
                if (iter == v_list.end()) {
                    continue;
                } else {
                    v_list.erase(iter);
                    --num_edges;
                }
            }
        }

        // finally, remove the vertex itself.
        auto iter = adj_list.begin();
        std::advance(iter, index);
        adj_list.erase(iter);

        // erase it from the vertex map as well
        vertex_map.erase(vertex);
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
        adj_list[index_v1].push_back({edge.v2, edge.weight});
        adj_list[index_v2].push_back({edge.v1, edge.weight});

        ++num_edges;
    }

    /**
     * Add an edge that connects vertices v1 and v2. If such an
     * edge already exists, do nothing.
     */
    void add_edge(vertex_type v1, vertex_type v2, weight_type w)
    {
        edge<vertex_type, weight_type> e;
        e.v1 = v1;
        e.v2 = v2;
        e.weight = w;
        add_edge(e);
    }

    void add_edge(vertex_type v1, vertex_type v2)
    {
        edge<vertex_type, weight_type> e;
        e.v1 = v1;
        e.v2 = v2;
        e.weight = 0;
        add_edge(e);
    }

    /**
     * Remove an edge from this graph and if it is not in this graph,
     * do nothing.
     */
    void remove_edge(const edge<vertex_type, weight_type>& edge)
    {
        auto find_v1 = vertex_map.find(edge.v1);
        auto find_v2 = vertex_map.find(edge.v2);
        if (find_v1 == vertex_map.end() || find_v2 == vertex_map.end()) {
            return; // edge is not in the graph
        }

        auto index_v1 = vertex_map[edge.v1];
        auto index_v2 = vertex_map[edge.v2];

        // remove the edge from both adjacency lists
        auto& loc_v1 = adj_list[index_v1];
        loc_v1.erase(std::remove_if(loc_v1.begin(), loc_v1.end(), [&edge](const adjacent_vertex& vertex) {
            return vertex.vertex == edge.v2;
        }));
        auto& loc_v2 = adj_list[index_v2];
        loc_v2.erase(std::remove_if(loc_v2.begin(), loc_v2.end(), [&edge](const adjacent_vertex& vertex) {
            return vertex.vertex == edge.v1;
        }));

        --num_edges;
    }

    /**
     * Remove the edge that connects v1 and v2 from this adjacency list.
     * If the edge does not exist in the graph, do nothing.
     */
    void remove_edge(vertex_type v1, vertex_type v2)
    {
        remove_edge(edge<vertex_type, weight_type>(v1, v2));
    }

    /**
     * Get the list of vertices adjacent to the given vertex.
     * If the vertex is not in the adjacency list an exception
     * may be thrown.
     */
    const vertex_list& operator[](vertex_type vertex) const
    {
        auto index = vertex_map.at(vertex);
        return adj_list[index];
    }

    /**
     * Returns the average degree of vertices in this graph.
     */
    double average_degree() const
    {
        auto sum = std::accumulate(adj_list.begin(), adj_list.end(), 0.0,
                    [](double init, const vertex_list& right) {
                        return init + static_cast<double>(right.size());
                    });
        return sum / adj_list.size();
    }

    /**
     * Returns the maximum degree of all vertices in this graph.
     */
    size_type max_degree() const
    {
        auto max = std::max_element(adj_list.begin(), adj_list.end(),
                    [](const vertex_list& left, const vertex_list& right) {
                        return left.size() < right.size();
                    });
        return max == adj_list.end() ? 0 : max->size();
    }

    /**
     * Returns the minimum degree of all vertices in this graph.
     */
    size_type min_degree() const
    {
        auto min = std::min_element(adj_list.begin(), adj_list.end(),
                    [](const vertex_list& left, const vertex_list& right) {
                        return left.size() < right.size();
                    });
        return min == adj_list.end() ? 0 : min->size();
    }

    /**
     * Get the number of edges in this graph.
     */
    size_type edge_count() const
    {
        return num_edges;
    }

    /**
     * Get the number of vertices in this graph.
     */
    size_type vertex_count() const
    {
        return adj_list.size();
    }

    /**
     * Returns true if and only if vertex v1 is adjacent to vertex v2
     * (and vice versa, since this is an undirected graph)
     */
    bool adjacent_to(vertex_type v1, vertex_type v2) const
    {
        if (vertex_map.find(v1) == vertex_map.end() || vertex_map.find(v2) == vertex_map.end()) {
            return false;
        } else {
            auto index = vertex_map[v1];
            auto v_list = adj_list[index];
            auto find = std::find_if(v_list.begin(), v_list.end(), [&v2](const adjacent_vertex& vertex) {
                return vertex.vertex == v2;
            });
            return find == v_list.end();
        }
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

    // store the number of edges because there's no super
    // easy and cheap way to calculate it
    size_type num_edges;
};


#endif //GRAPHS_ADJACENCY_LIST_H
