#pragma once

#include <string>
#include <vector>

class Vertice
{
public:
    char Name;

    Vertice() : Name{0} {}
    Vertice(char name) : Name{name} {}

    inline std::string to_string() { return std::string(1, Name); }
    inline bool operator==(const Vertice &other) { return other.Name == Name; }
    inline bool operator!=(const Vertice &other) { return other.Name != Name; }
};

class Vertices
{
private:
    std::vector<Vertice> _vertices;
    void shrink_size(size_t new_len);

public:
    inline int size() { return _vertices.size(); }

    Vertices(std::vector<Vertice> vertices) : _vertices{vertices} {}
    Vertices(int length) : _vertices(length) {}

    inline Vertice &operator[](std::size_t index) { return _vertices.at(index); }
    inline const Vertice &operator[](std::size_t index) const { return _vertices.at(index); }

    std::string to_string();
    bool contains(Vertice &v);
    Vertices operator|(Vertices &b);
    Vertices operator&(Vertices &b);
    Vertices operator-(Vertices &b);
    Vertices operator^(Vertices &b);
};