/*
Header Node file by Andrew Thomas 3/19/20. This is a node with a right and left node and data with it
11;rgb:0000/0000/0000Header Node file by Andrew Thomas 3/19/20. This is a node with a right and left node and data with it
 */
#ifndef NODE_H
#define NODE_H
//#include <cstdlib>
#include <iostream> 
#include<cstring>
using namespace std;
class Node{
 public:
  Node(); // constructor
  ~Node(); // destructor
  void setRight(Node* inputRight); // setters
  void setLeft(Node* inputLeft);
  void setData(int* inputData);
  void setColor(int c);
  Node* getRight(); // getters
  Node* getLeft();
  int* getData();
  int getColor();
    Node* getParent();
    void setParent(Node* newParent);
private: // right left and data storage
  Node* parent;
  Node* right;
  Node* left;
  int* data = new int;
  int color;
  
};
#endif
