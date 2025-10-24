/* R. Fabbri, 2024*/
#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data);
Node* insert(Node* node, int data);
Node* search(Node* root, int data);
void deleteTree(Node* node);

#endif // TREE_H
