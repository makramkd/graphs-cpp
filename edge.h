//
// Created by Makram Kamaleddine on 10/23/15.
//

#ifndef GRAPHS_EDGE_H
#define GRAPHS_EDGE_H

#include <type_traits>

/**
 * Dummy templates in order to use sfinae to let only integral types
 * be allowed for use.
 */
template<typename, typename, typename = void, typename = void> struct edge;
template<typename, typename, typename = void, typename = void> struct d_edge;

/**
 * A class that is supposed to represent an edge in an
 * undirected graph. The edge could have a weight: if
 * it doesn't, it's weight would be 0.
 */
template<typename vertex_type,
        typename weight_type>
struct edge<vertex_type, weight_type, typename std::enable_if<std::is_integral<vertex_type>::value>::type,
            typename std::enable_if<std::is_integral<weight_type>::value>::type>
{

    // default ctor: almost never what the caller wants.
    edge()
    : v1(),
      v2(),
      weight()
    {

    }

    // typical ctor : made for convenience.
    edge(vertex_type v1, vertex_type v2, weight_type weight = 0)
    :v1(v1),
     v2(v2),
     weight(weight)
    {

    }

    vertex_type v1;
    vertex_type v2;
    weight_type weight;
};

/**
 * A class that is supposed to represent an edge in an
 * undirected graph. The edge could have a weight: if
 * it doesn't, it's weight would be 0.
 */
template<typename vertex_type,
        typename weight_type>
struct d_edge<vertex_type, weight_type, typename std::enable_if<std::is_integral<vertex_type>::value>::type,
        typename std::enable_if<std::is_integral<weight_type>::value>::type>
{

    d_edge()
    :from(),
     to(),
     weight()
    {

    }

    d_edge(vertex_type from, vertex_type to, weight_type weight = 0)
    : from(from),
      to(to),
      weight(weight)
    {

    }

    vertex_type from;
    vertex_type to;
    weight_type weight;
};


#endif //GRAPHS_EDGE_H
