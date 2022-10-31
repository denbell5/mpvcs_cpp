#pragma once

#include <string>
#include <vector>
#include <iostream>

class Node
{
private:
    std::string child_to_string(Node *child);
    inline bool is_dot(char ch) { return ch == '.'; }

public:
    Node *Left;
    Node *Right;
    char Name;

    Node(char name) : Name{name}, Left{NULL}, Right{NULL} {}

    std::string to_string();
    void print();

    void process_tree_string(std::string tree_str, int &i);
    void traverse_infix();
    void traverse_prefix();
    void traverse_postfix();
};