/*
    Sample implementation of:
    Kruskal's Minimum Spanning Tree algorithm

    Copyright 2021 by Michał Gibas
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#include "disjointset.hpp"

// the tuple elements refer to: first node, second node, edge weight
typedef std::tuple<size_t, size_t, int> edge_t;

void find_minimum_spanning_tree(std::vector<edge_t> edges, size_t n_nodes);

int main(void) {
    size_t n_edges, n_nodes;
    std::vector<edge_t> edges;
    std::cout << "Author: Michal Gibas\n"
        << "This program finds the minnimum spanning tree of a given graph using the Krustkal's algorithm\n\n";
    std::cout << "Number of nodes: "; std::cin >> n_nodes;
    std::cout << "Number of edges: "; std::cin >> n_edges;
    std::cout << "Edges [first node index, second node index, weight]: \n";
    edges.reserve(n_edges);
    edges.resize(n_edges);

    for(size_t i = 0; i < n_edges; ++i) {
        size_t a, b;
        int weight;
        std::cin >> a >> b >> weight;
        edge_t edge = std::make_tuple(a, b, weight);
        edges.at(i) = edge;
    } 

    find_minimum_spanning_tree(edges, n_nodes);

    return 0;
}

void find_minimum_spanning_tree(std::vector<edge_t> edges, size_t n_nodes) {
    
    std::sort(edges.begin(), edges.end(), [](edge_t a, edge_t b) {
        return std::get<2>(a) < std::get<2>(b);
    });
    std::vector<edge_t> mst;
    mst.reserve(edges.size());

    DisjointSet dset = DisjointSet(n_nodes);
    
    for(auto edge : edges) {    
        size_t a = dset.find(std::get<0>(edge));
        size_t b = dset.find(std::get<1>(edge));
        if(a != b) {
            mst.push_back(edge);
            dset.unify(std::get<0>(edge), std::get<1>(edge));
        }
    }

    //print the minnimum spanning tree
    for(auto edge : mst) {
        std::cout  << std::get<0>(edge) 
            << ' ' << std::get<1>(edge) 
            << ' ' << std::get<2>(edge)
            << '\n'; 
    }
}