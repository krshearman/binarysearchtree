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
    bool isEmpty = false;
    if(count != 0){
        isEmpty = true;
    }
    return isEmpty;
}

int BinTree::getCount(){
    return 0;
}

bool BinTree::getRootData(Data * data){
    bool getRoot = false;
    if(root != nullptr){
        data->id = root->data.id;
        data->information = root->data.information;
        getRoot = true;
    } else {
        data->id = -1;
        data->information = "";
    }
    return getRoot;
}

void BinTree::displayTree(){

}

void BinTree::clear(){

}

bool BinTree::addNode(int id, string data){
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
    DataNode *temp = root;
    return getNode(data, id, temp);
}

bool BinTree::contains(int id){
    return false;
}

int BinTree::getHeight(){
    DataNode * temp;
    temp = new DataNode;
    temp = root;
    return getHeight(temp);
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
    if(*temp == nullptr){
        *temp = new DataNode;
        (*temp)->left = nullptr;
        (*temp)->right = nullptr;
        (*temp)->data.id = t->data.id;
        (*temp)->data.information = t->data.information;
        count++;
        inserted = true;
    }
    if (t->data.id < (*temp)->data.id){
        DataNode *t2 = new DataNode;
        t2 =  (*temp)->left;
        inserted = addNode(t, &t2);
    } else if (t->data.id > (*temp)->data.id){
        DataNode *t3 = new DataNode;
        t3 =  (*temp)->right;
        inserted = addNode(t, &t3);
    }
    return inserted;
}

DataNode* BinTree::removeNode(int id, DataNode * data){
    DataNode * ptr;
    return ptr;
}

bool BinTree::getNode(Data * data, int id, DataNode * temp){
    bool found = false;
    if(temp != nullptr){
        if(id == temp->data.id){
            data->id = temp->data.id;
            data->information = temp->data.information;
            found = true;
        } else if (id < temp->data.id){
            found = getNode(data, id, temp->left);
        } else {
            found = getNode(data, id, temp->right);
        }
    }
    return found;
}

bool BinTree::contains(int id, DataNode * data){
    return false;
}

int BinTree::getHeight(DataNode * temp){
    int height;
    int x, y;
    if (temp == nullptr){
        height = 0;
    } else {
        x = getHeight(temp->left);
        y = getHeight(temp->right);
        height = x > y ? x + 1 : y + 1;
    }
    return height;
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