/*********************
Name: Kendall Shearman
Coding 06
Purpose: Binary Tree
**********************/

#include "bintree.h"

//public methods
BinTree::BinTree(){
    count = 0;
    DataNode * root = nullptr;
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
    return false;
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

bool BinTree::addNode(DataNode * data, DataNode ** dataptr){
    return false;
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

void BinTree::displayInOrder(DataNode * data){

}