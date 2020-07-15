/*********************
Name: Kendall Shearman
Coding 06
Purpose: Binary Tree
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"
#include <iostream>

using std::endl;
using std::cout;

class BinTree {

public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();
    void clear();
    bool addNode(int, string);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    DataNode* minValueNode(DataNode*);

    DataNode *root;
    int count;
};








#endif /* BINTREE_BINTREE_H */

