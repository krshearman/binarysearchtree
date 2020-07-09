/*********************
Name: Kendall Shearman
Coding 06
Purpose: Binary Tree
**********************/

#include "bintree.h"

//public methods
BinTree::BinTree(){
    count = 0;
    root = nullptr;
}

BinTree::~BinTree(){

}

bool BinTree::isEmpty(){
    return false;
}

int BinTree::getCount(){
    return 0;
}

bool BinTree::getRootData(Data * data){
    return false;
}

void BinTree::displayTree(){

}

void BinTree::clear(){

}

bool BinTree::addNode(int id, string data){
    //bool inserted = false;
   /* DataNode *t;
    if(root == nullptr){
        t = new DataNode;
        t->data.id = id;
        t->data.information = data;
        t->left = nullptr;
        t->right = nullptr;
        inserted = true;
    }
    if(id < root->data.id){
        DataNode *l = root->left;
        DataNode *left = l;
        inserted = addNode(t, &left);
    }
    if(id > root->data.id){
        DataNode *r = root->right;
        DataNode *right = r;
        inserted = addNode(t, &right);
    }*/

   DataNode * t = new DataNode;
   t->data.id = id;
   t->data.information = data;
   t->left = nullptr;
   t->right = nullptr;
   DataNode *temp = root;
   return addNode(t, &temp);
}

bool BinTree::removeNode(int id){
    return false;
}

bool BinTree::getNode(Data * data, int id){
    return false;
}

bool BinTree::contains(int id){
    return false;
}

int BinTree::getHeight(){
    return 0;
}

void BinTree::displayPreOrder(){

}

void BinTree::displayPostOrder(){

}

void BinTree::displayInOrder(){

}

//private methods

void BinTree::clear(DataNode*){

}

bool BinTree::addNode(DataNode * t, DataNode ** temp){
    bool inserted = false;
    DataNode *n;
    if(root == nullptr){
        *temp = new DataNode;
        (*temp)->left = nullptr;
        (*temp)->right = nullptr;
        (*temp)->data.id = t->data.id;
        (*temp)->data.information = t->data.information;
        inserted = true;
        //cout << "INSERTED" << endl;
    }
    if (t->data.id < (*temp)->data.id){
        DataNode *t2 = new DataNode;
        t2 =  (*root).left;
        inserted = addNode(t, &t2);

    } else if (t->data.id > (*temp)->data.id){
        DataNode *t3 = new DataNode;
        t3 =  (*root).right;
        inserted = addNode(t, &t3);
    }
    return inserted;
}

DataNode* BinTree::removeNode(int id, DataNode * data){
    DataNode * ptr;
    return ptr;
}

bool BinTree::getNode(Data * data, int id, DataNode * ptr){
    return false;
}

bool BinTree::contains(int id, DataNode * data){
    return false;
}

int BinTree::getHeight(DataNode * data){
    return 0;
}

void BinTree::displayPreOrder(DataNode * data){

}

void BinTree::displayPostOrder(DataNode * data){

}

void BinTree::displayInOrder(DataNode * temproot){
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
    return;
}