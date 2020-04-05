/*
Node cpp file that has a right and left node. It also has a data value. There are getters and setters for each item.
 */
#include<iostream>
//#include <cstdlib>
#include<cstring>
#include "Node.h"
using namespace std;
Node::Node(){ // constructor
    right = NULL;
  left = NULL;
  //pdata = NULL;
  parent = NULL;
  (*color) = 0;
}
Node::~Node(){ // destructor

  right = NULL;
   left = NULL;
  data = NULL;
  parent = NULL;
  color = NULL;
}
void Node::setRight(Node* inputRight){ // setter Right
  right = inputRight;
}
Node* Node::getRight(){ // getter right
  return right;
}
void Node::setLeft(Node* inputLeft){ // setter left
  left = inputLeft;
}
Node* Node::getLeft(){ // getter left
  return left;
}
void Node::setData(int* inputData){ // setter data
  (*data) = (*inputData);
}
int* Node::getData(){ // getter data
  return data;
}
int* Node::getColor(){
  return color;
}
void Node::setColor(int* c){
  (*color) = (*c);
}
void Node::setParent(Node* newParent) {
  parent = newParent;
}
