#include <string>
#include <vector>

#include "graph.h"

using namespace std;

Graph Graph::operator|(Graph &b)
{
    auto _vertices = vertices | b.vertices;
    auto _edges = edges | b.edges;
    return Graph(_vertices, _edges);
}

Graph Graph::operator&(Graph &b)
{
    auto _vertices = vertices & b.vertices;
    auto _edges = edges & b.edges;
    return Graph(_vertices, _edges);
}

Graph Graph::operator-(Graph &b)
{
    auto _vertices = vertices - b.vertices;
    auto _edges = edges - b.edges;
    _edges = _edges.suitable_for(_vertices);
    return Graph(_vertices, _edges);
}

Graph Graph::operator^(Graph &b)
{
    auto _vertices = vertices ^ b.vertices;
    auto _edges = edges ^ b.edges;
    _edges = _edges.suitable_for(_vertices);
    return Graph(_vertices, _edges);
}

Graph Graph::operator!()
{
    auto _edges = edges.build_all_combinations(vertices);
    _edges = _edges - edges;
    return Graph(vertices, _edges);
}