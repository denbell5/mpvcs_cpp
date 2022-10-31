#include <string>
#include <vector>

#include "vertice.h"

using namespace std;

void Vertices::shrink_size(size_t new_len)
{
    auto len = _vertices.size();
    for (size_t i = len; i > new_len; i--)
    {
        _vertices.pop_back();
    }
}

string Vertices::to_string()
{
    string res = "";
    for (size_t i = 0; i < size(); i++)
    {
        res += _vertices[i].to_string();
        if (i < size() - 1)
            res += ",";
    }
    return res;
}

bool Vertices::contains(Vertice &v)
{
    for (size_t i = 0; i < size(); i++)
    {
        if (_vertices[i] == v)
            return true;
    }
    return false;
}

Vertices Vertices::operator|(Vertices &b)
{
    Vertices ab(size() + b.size());
    for (int i = 0; i < size(); i++)
    {
        ab[i] = _vertices[i];
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

Vertices Vertices::operator&(Vertices &b)
{
    Vertices ab(size() + b.size());
    size_t abi = 0;
    for (size_t i = 0; i < size(); i++)
    {
        auto curr = _vertices[i];
        if (b.contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}

Vertices Vertices::operator-(Vertices &b)
{
    Vertices ab(size() + b.size());
    auto abi = 0;
    for (int i = 0; i < size(); i++)
    {
        auto curr = _vertices[i];
        if (!b.contains(curr))
        {
            ab[abi] = curr;
            abi++;
        }
    }
    ab.shrink_size(abi);
    return ab;
}

Vertices Vertices::operator^(Vertices &b)
{
    Vertices ab(size() + b.size());
    auto abi = 0;
    for (int i = 0; i < size(); i++)
    {
        auto curr = _vertices[i];
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
