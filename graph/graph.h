#pragma once

#include <string>
#include <vector>
#include "vertice.h"
#include "edge.h"

class Graph
{
public:
    Vertices vertices;
    Edges edges;

    Graph(Vertices vertices, Edges edges)
        : vertices{vertices}, edges{edges} {}

    inline std::string to_string()
    {
        return vertices.to_string() + " | " + edges.to_string();
    }

    Graph operator|(Graph &b);
    Graph operator&(Graph &b);
    Graph operator-(Graph &b);
    Graph operator^(Graph &b);
    Graph operator!();
};