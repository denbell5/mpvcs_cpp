#include <iostream>
#include <vector>
#include <string>
#include "vertice.h"
#include "edge.h"
#include "graph.h"

using namespace std;

int main()
{
    Vertices v1(vector<Vertice>{Vertice('a'), Vertice('b'), Vertice('c')});
    Vertices v2(vector<Vertice>{Vertice('a'), Vertice('b'), Vertice('e')});

    Edges e1(vector<Edge>{Edge('a', 'b'), Edge('b', 'c')});
    Edges e2(vector<Edge>{Edge('a', 'b'), Edge('a', 'e')});

    Graph g1(v1, e1);
    Graph g2(v2, e2);

    auto g_1 = g1 | g2;
    auto g_2 = g1 & g2;
    auto g_3 = g1 ^ g2;
    auto g_4 = g1 - g2;
    auto g_5 = !g1;

    cout << "g1 " << g1.to_string() << endl;
    cout << "g2 " << g2.to_string() << endl;
    cout << endl;
    cout << "| " << g_1.to_string() << endl;
    cout << "& " << g_2.to_string() << endl;
    cout << "^ " << g_3.to_string() << endl;
    cout << "- " << g_4.to_string() << endl;
    cout << "! " << g_5.to_string() << endl;
    cout << endl;
}