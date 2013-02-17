#include <stdlib.h>
#include <iostream>
#include "bst.h"

Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

bool exists(TreeNode *root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value > value)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}

bool exists(Tree *tree, int value)
{
    return exists(tree->root, value);
}

TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add(TreeNode *&node, int value)
{
    if (node == NULL)
    {
        node = createNode(value);
        return;
    }

    if (value < node->value)
        add(node->left, value);
    else
        add(node->right, value);
}

void add(Tree *tree, int value)
{
    add(tree->root, value);
}

TreeNode *leftmostChild(TreeNode *node)
{
    if (node->left != NULL)
        return leftmostChild(node->left);
    else
        return node;
}

bool isLeaf(TreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}

bool hasOneChild(TreeNode *node)
{
    return ((node->left != NULL && node->right == NULL)
            || (node->left == NULL && node->right != NULL));
}

void remove(TreeNode *&node, int value)
{
    if (node->value > value)
        remove(node->left, value);
    else if (node->value < value)
        remove(node->right, value);
    else if (isLeaf(node))
    {
        delete node;
        node = NULL;
    }
    else if (hasOneChild(node))
    {
        if (node->left != NULL)
        {
            TreeNode *temp = node->left;
            delete node;
            node = temp;
        }
        else if (node->right != NULL)
        {
            TreeNode *temp = node->right;
            delete node;
            node = temp;
        }
    }
    else
    {
        TreeNode *temp = leftmostChild(node->right);
        node->value = temp->value;
		remove(node->right, temp->value);
    }
}

void remove(Tree *tree, int value)
{
    if (!exists(tree, value))
       return;
    remove(tree->root, value);
}

void clearTree(TreeNode *&node)
{
	if (node->left != NULL)
		clearTree(node->left);
	if (node->right != NULL)
		clearTree(node->right);
	delete node;
	node = NULL;
}
void clearTree(Tree *tree)
{
	if (tree->root != NULL)
		clearTree(tree->root);
	delete tree;
}
void printInOrder(TreeNode *&node)
{
	if (node != NULL)
	{
		if (node->left != NULL)
			printInOrder(node->left);
		std::cout << node->value << ' ';
		if (node->right != NULL)
			printInOrder(node->right);
	}
}

void printInOrder(Tree *tree)
{
	printInOrder(tree->root);
}

void printInRevOrder(TreeNode *&node)
{
	if (node != NULL)
	{
		if (node->right != NULL)
			printInRevOrder(node->right);
		std::cout << node->value << ' ';
		if (node->left != NULL)
			printInRevOrder(node->left);
	}
}

void printInRevOrder(Tree *tree)
{
	printInRevOrder(tree->root);
}

int operation (char oper, int first, int second)
{
	if (oper == '+') 
		return (first + second);
	if (oper == '-') 
		return (first - second);
	if (oper == '*') 
		return (first * second);
	if (oper == '/') 
		return (first / second);
	return NULL;
}

bool isOper(char symbol)
{
	return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

bool isNumber(char symbol)
{
	return (symbol >= '0') && (symbol <= '9');
}

int makeTree(TreeNode *&node, char *buffer, int pos)
{
	char symbol = buffer[pos];
	add(node, symbol);
	pos++;
	if (isOper(symbol))
	{
		pos = makeTree(node->left, buffer, pos);
		pos = makeTree(node->right, buffer, pos);
	}
	return pos;		
	
}

void makeTree(Tree *tree, char* buffer)
{
	makeTree(tree->root, buffer, 0);
}

int countTree(TreeNode *node)
{
	int result = 0;
	if ((node->left == NULL) && (node->right == NULL))
		result = node->value - '0';
	else
		result = operation(node->value, countTree(node->left), countTree(node->right));
	return result;
}
