/* R. Fabbri, 2024*/
#include "gtest/gtest.h"
#include "../tree.h"

TEST(TreeTest, Insertion) {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    ASSERT_EQ(root->data, 50);
    ASSERT_EQ(root->left->data, 30);
    ASSERT_EQ(root->left->left->data, 20);
    ASSERT_EQ(root->left->right->data, 40);
    ASSERT_EQ(root->right->data, 70);
    ASSERT_EQ(root->right->left->data, 60);
    ASSERT_EQ(root->right->right->data, 80);

    deleteTree(root);
}

TEST(TreeTest, Search) {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    Node* found = search(root, 40);
    ASSERT_TRUE(found != NULL);
    ASSERT_EQ(found->data, 40);

    Node* notFound = search(root, 100);
    ASSERT_TRUE(notFound == NULL);

    deleteTree(root);
}
