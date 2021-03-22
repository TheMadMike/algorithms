#pragma once

#include <memory>

class DisjointSet {
public:
    DisjointSet(size_t size) 
    :size(size) {
        data = std::make_unique<size_t[]>(size);
        for(size_t i = 0; i < size; ++i) {
            data[i] = i;
        }
    }

    size_t find(size_t p) {
        size_t root = p;
        while(root != data[root])
            root = data[root];
        
        //path compression
        while(p != root) {
            size_t next = data[p];
            data[p] = root;
            p = next;
        }

        return root;
    }

    size_t unify(size_t a, size_t b) {
        size_t a_root = this->find(a);
        size_t b_root = this->find(b);
        
        if(a_root == b_root)
            return a_root;
        
        data[a] = data[b];
        return data[a];
    }

private:
    std::unique_ptr<size_t[]> data;
    size_t size;
};