#pragma once

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
};

Tree *createTree();
bool exists(Tree *tree, int value);
void add(Tree *tree, int value);
void add(TreeNode *&node, int value);
void remove(Tree *tree, int value);
TreeNode *createNode(int value);
void clearTree(Tree *tree);
void printInOrder(Tree *tree);
void printInRevOrder(Tree *tree);
void makeTree(Tree *tree, char* buffer);
int countTree(TreeNode *node);