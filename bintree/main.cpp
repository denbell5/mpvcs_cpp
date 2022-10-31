#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;

int main()
{
    string tree_str = "abc..de..fg...hi..jkl..m..n..";

    int i = 0;
    Node root(tree_str[i]);
    root.process_tree_string(tree_str, i);

    cout << "infix" << endl;
    root.traverse_infix();

    cout << "prefix" << endl;
    root.traverse_prefix();

    cout << "postfix" << endl;
    root.traverse_postfix();
}