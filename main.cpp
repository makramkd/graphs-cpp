#include <iostream>
#include "graph.h"
#include "matrix.h"

int main() {
    std::cout << "Graph test" << std::endl;

    graph<int, int> g;

    // add some vertices to g
    for (int i = 0; i < 5; ++i) {
        g.add_vertex(i);
    }

    // add some edges
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 5); // 5 is not in the graph, so this won't add anything
    g.add_edge(4, 1);
    g.add_edge(4, 3);

    // print out some adjacency lists
    for (int i = 0; i < 5; ++i) {
        std::cout << "Vertex v_" << i << "'s adjacency list:" << std::endl;
        std::cout << "( ";
        for (auto v : g.adj_list_of(i)) {
            std::cout << v.vertex << " ";
        }
        std::cout << ")" << std::endl;
    }

    std::cout << "Number of edges in g: " << g.edges() << std::endl;
    std::cout << "Number of vertices in g: " << g.vertices() << std::endl;
    std::cout << "Max degree of g: " << g.max_degree() << std::endl;
    std::cout << "Min degree of g: " << g.min_degree() << std::endl;
    std::cout << "Average degree of g: " << g.avg_degree() << std::endl;

    // try to remove some edges
    g.remove_edge(0, 1);

    std::cout << g.edges() << std::endl;
    std::cout << "( ";
    for (auto v : g.adj_list_of(0)) {
        std::cout << v.vertex << " ";
    }
    std::cout << ")";

    // try to remove a vertex
    g.remove_vertex(1);

    std::cout << "Number of vertices in g: " << g.vertices() << std::endl;
    std::cout << "Number of edges in g: " << g.edges() << std::endl;

    matrix<int, 3, 3> m(0);

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            m(i, j) = i + j;
        }
    }

    for (unsigned i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            std::cout << "a(" << i << ", " << j << ") = " << m(i, j) << std::endl;
        }
    }
}