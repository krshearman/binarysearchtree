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
    if(count == 0){
        isEmpty = true;
    }
    return isEmpty;
}

int BinTree::getCount(){
    return count;
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
    cout << "DISPLAY TREE" << endl << "==============================================" << endl;
    isEmpty() == false ? cout << "The Tree is NOT empty" : cout << "The Tree is empty";
    cout << endl;
    cout << "Height " << getHeight() << endl;
    cout << "Node Count: " << count << endl << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << endl;
}

void BinTree::clear(){
    DataNode *temp = root;
    clear(temp);
}

bool BinTree::addNode(int id, string data){
   bool added = false;
   if(id > 0 && data != ""){
       DataNode * t = new DataNode;
       t->data.id = id;
       t->data.information = data;
       t->left = nullptr;
       t->right = nullptr;
       DataNode **temp = &root;
       added = addNode(t, temp);
   }
   return added;
}

bool BinTree::removeNode(int id){
    bool removed = false;
    int tempCount = count;
    DataNode *temp = root;
    root = removeNode(id, temp);
    if(count < tempCount){
        removed = true;
    }
    return removed;
}

bool BinTree::getNode(Data * data, int id){
    bool found = false;
    if(id > 0){
        DataNode *temp = root;
        found = getNode(data, id, temp);
    }
    return found;
}

bool BinTree::contains(int id){
    bool containing = false;
    if(id > 0){
        DataNode *temp = root;
        containing = contains(id, temp);
    }
    return containing;
}

int BinTree::getHeight(){
    DataNode *temp = root;
    return getHeight(temp);
}

void BinTree::displayPreOrder(){
    DataNode *temp = root;
    displayPreOrder(temp);
}

void BinTree::displayPostOrder(){
    DataNode *temp = root;
    displayPostOrder(temp);
}

void BinTree::displayInOrder(){
    DataNode *temp = root;
    displayInOrder(temp);
}

//private methods

void BinTree::clear(DataNode * temp){
   /* if(temp != nullptr){
        clear(temp->left);
        clear(temp->right);
        temp->left = nullptr;
        temp->right = nullptr;
        delete temp;
        count--;
        root = temp;
    }*/
}

bool BinTree::addNode(DataNode * t, DataNode ** temp){
    bool inserted = false;
    if(*temp == nullptr){
        *temp = t;
        count++;
        inserted = true;
    } else {
        if (t->data.id < (*temp)->data.id){
            inserted = addNode(t, &(*temp)->left);
        } else {
            inserted = addNode(t, &(*temp)->right);
        }
    }
    return inserted;
}

DataNode* BinTree::removeNode(int id, DataNode * temp){
    if(temp != nullptr){
        if(id < temp->data.id){
            temp->left = removeNode(id, temp->left);
        } else if (id > temp->data.id){
            temp->right = removeNode(id, temp->right);
        } else {
            DataNode * nTemp = new DataNode;
            if(temp->left == nullptr){
                nTemp = temp->right;
                delete temp;
                temp = nTemp;
                count--;
            } else if (temp->right == nullptr){
                nTemp = temp->left;
                delete temp;
                temp = nTemp;
                count--;
            } else {
                nTemp = minValueNode(temp->right);
                temp->data.id = nTemp->data.id;
                temp->data.information = nTemp->data.information;
                temp->right = removeNode(nTemp->data.id,temp->right);
            }
        }
    }
    return temp;
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

bool BinTree::contains(int id, DataNode * temp){
    bool found = false;
    if(temp != nullptr){
        if(id == temp->data.id){
            found = true;
        } else if (id < temp->data.id){
            found = contains(id, temp->left);
        } else {
            found = contains(id, temp->right);
        }
    }
    return found;
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

void BinTree::displayPreOrder(DataNode * temp){
    if(temp != nullptr){
        cout << temp->data.id << " " << temp->data.information << endl;
        if(temp->left){
            displayPreOrder(temp->left);
        }
        if(temp->right){
            displayPreOrder(temp->right);
        }
    }
}

void BinTree::displayPostOrder(DataNode * temp){
    if(temp != nullptr){
        if(temp->left){
            displayPostOrder(temp->left);
        }
        if(temp->right){
            displayPostOrder(temp->right);
        }
        cout << temp->data.id << " " << temp->data.information << endl;
    }
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

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}