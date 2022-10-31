#include <string>
#include <vector>
#include <memory>

#include "edge.h"
#include "vertice.h"

using namespace std;

bool Edge::is_suitable_for(Vertices vertices)
{
    auto ax_fits = false;
    auto bx_fits = false;
    Vertice ax(Ax);
    Vertice bx(Bx);
    for (int i = 0; i < vertices.size(); i++)
    {
        auto v = vertices[i];
        if (ax == v)
            ax_fits = true;
        else if (bx == v)
            bx_fits = true;
    }
    return ax_fits && bx_fits;
}

void Edges::shrink_size(size_t new_len)
{
    auto len = _edges.size();
    for (size_t i = len; i > new_len; i--)
    {
        _edges.pop_back();
    }
}

string Edges::to_string()
{
    string res = "";
    for (size_t i = 0; i < size(); i++)
    {
        res += _edges[i].to_string();
        if (i < size() - 1)
            res += ",";
    }
    return res;
}

bool Edges::contains(Edge &e)
{
    for (size_t i = 0; i < size(); i++)
    {
        if (_edges.at(i) == e)
            return true;
    }
    return false;
}

Edges Edges::build_all_combinations(Vertices &vertices)
{
    auto e_len = 0;
    for (int i = vertices.size(); i > 0; i--)
    {
        e_len += i;
    }
    Edges edges(e_len);
    auto e_i = 0;
    for (int i = 0; i < vertices.size(); i++)
    {
        for (int j = i; j < vertices.size(); j++)
        {
            edges[e_i] = Edge(vertices[i].Name, vertices[j].Name);
            e_i++;
        }
    }
    return edges;
}

Edges Edges::suitable_for(Vertices &vertices)
{
    Edges edges(size());
    auto e_i = 0;
    for (int i = 0; i < size(); i++)
    {
        auto e = _edges[i];
        if (e.is_suitable_for(vertices))
        {
            edges[e_i] = e;
            e_i++;
        }
    }
    edges.shrink_size(e_i);
    return edges;
}

Edges Edges::operator|(Edges &b)
{
    Edges ab(size() + b.size());
    for (int i = 0; i < size(); i++)
    {
        ab[i] = _edges[i];
    }
    auto abi = size();
    for (int i = 0; i < b.size(); i++)
    {
        auto curr = b[i];
        if (!contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}

Edges Edges::operator&(Edges &b)
{
    Edges ab(size() + b.size());
    size_t abi = 0;
    for (size_t i = 0; i < size(); i++)
    {
        auto curr = _edges.at(i);
        if (b.contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}

Edges Edges::operator-(Edges &b)
{
    Edges ab(size() + b.size());
    auto abi = 0;
    for (int i = 0; i < size(); i++)
    {
        auto curr = _edges.at(i);
        if (!b.contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}

Edges Edges::operator^(Edges &b)
{
    Edges ab(size() + b.size());
    auto abi = 0;
    for (int i = 0; i < size(); i++)
    {
        auto curr = _edges.at(i);
        if (!b.contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        auto curr = b[i];
        if (!contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}