#pragma once

#include <string>
#include <vector>
#include "vertice.h"

class Edge
{
public:
    char Ax;
    char Bx;

    Edge() : Ax{0}, Bx(0) {}

    Edge(char ax, char bx)
    {
        Ax = ax < bx ? ax : bx;
        Bx = ax < bx ? bx : ax;
    }

    inline std::string to_string()
    {
        return "(" + std::string(1, Ax) + "," + std::string(1, Bx) + ")";
    }

    inline bool operator==(Edge &b) { return Ax == b.Ax && Bx == b.Bx; }
    inline bool operator!=(Edge &b) { return !(*this == b); }

    bool is_suitable_for(Vertices vertices);
};

class Edges
{
private:
    std::vector<Edge> _edges;
    void shrink_size(size_t new_len);

public:
    inline int size() { return _edges.size(); }

    Edges(std::vector<Edge> edges) : _edges(edges){};
    Edges(int length) : _edges(length){};

    inline Edge &operator[](std::size_t index) { return _edges.at(index); }
    inline const Edge &operator[](std::size_t index) const { return _edges.at(index); }

    std::string to_string();
    bool contains(Edge &e);

    static Edges build_all_combinations(Vertices &vertices);

    Edges suitable_for(Vertices &vertices);

    Edges operator|(Edges &b);
    Edges operator&(Edges &b);
    Edges operator-(Edges &b);
    Edges operator^(Edges &b);
};