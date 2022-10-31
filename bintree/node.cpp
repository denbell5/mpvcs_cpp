#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;

string Node::child_to_string(Node *child)
{
    if (child == NULL)
        return ".";
    else
        return string(1, child->Name);
}

string Node::to_string()
{
    return string(1, Name) + ": (" +
           child_to_string(Left) + "," + child_to_string(Right) + ")";
}

void Node::print() { cout << to_string() << endl; }

void Node::process_tree_string(std::string tree_str, int &i)
{
    i = i + 1;
    auto next_name = tree_str[i];

    if (!is_dot(next_name))
    {
        Left = new Node(next_name);
        Left->process_tree_string(tree_str, i);
    }

    i = i + 1;
    next_name = tree_str[i];

    if (!is_dot(next_name))
    {
        Right = new Node(next_name);
        Right->process_tree_string(tree_str, i);
    }
}

void Node::traverse_infix()
{
    if (Left != NULL)
        Left->traverse_infix();
    print();
    if (Right != NULL)
        Right->traverse_infix();
}

void Node::traverse_prefix()
{
    print();
    if (Left != NULL)
        Left->traverse_prefix();
    if (Right != NULL)
        Right->traverse_prefix();
}

void Node::traverse_postfix()
{
    if (Left != NULL)
        Left->traverse_postfix();
    if (Right != NULL)
        Right->traverse_postfix();
    print();
}