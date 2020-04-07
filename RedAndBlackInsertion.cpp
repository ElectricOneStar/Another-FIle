#include <iostream>

#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std;
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced); // functions
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header);
void Add(Node* header, Node* add);
//void Subtract();
//void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special);
void Print(Node* header, int length, int count, int i);
//void Search();
void Search(Node* header, int* searchData, bool* exists);
void maxSize(char* input, int* size);
Node* getRightMost(Node* header);
void rotateLeft(Node *&header, Node *&pointer);
void rotateRight(Node *&header, Node *&pointer);
void fixViolation(Node* &header, Node* &pointer);
void balance(Node* &head, Node* &curr);
void balance2(Node* &head, Node* &curr);
int main(){ // initialization of variables
  //HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
  char* inputType = new char[20];
  char* input = new char[500];
  char* FileName = new char[20];
  char* inputFunction = new char[20];
  bool quit = false;
  int* index = new int;
  int* parced = new int;
  int* counterOne = new int;
  (*counterOne) = 0;
  int* wordCounter = new int;
  (*wordCounter) = 0;
  int* size = new int;
  Node* header = new Node;
  (*size) = 1;
  char* additionInput = new char[20];
  bool* exists = new bool;
  (*exists) = false;
  // Node* one = new Node;
  //(*one).setData(Parce(input, index, counterOne, wordCounter, parced));
  char* searchInput = new char[20];
  char* subtractInput = new char[20];
  Node* previous = new Node;
  int* DCounter = new int;
  (*DCounter) = 0;
  int* skip = new int;
  (*skip) = 0;
  int* special = new int;
  Node* Parent = new Node;
  Node* Uncle = new Node;
  Node* GrandParent = new Node;
  /*
  int* ones = new int;
  int* twos = new int;
  int* threes = new int;
  */
(*index) = 1;
  do{
  cout << "Welcome to Binary Tree Please Select your Input: User or File" << endl;
  cin.get(inputType, 20); // will continue to ask for type of input
  cin.clear();
  cin.ignore();
  }
  while(strcmp(inputType, "User") != 0 && strcmp(inputType, "File") != 0);
  if(strcmp(inputType, "User") == 0){ // USER INPUT
    cout << "Please Enter a series of number separated by spaces. Up to 100 numbers should be stored" << endl;
    cin.get(input, 500); // gets the user input
    cin.ignore();
      cin.clear();
      //cout << "Input: " << input << endl;
  }
  else if(strcmp(inputType, "File") == 0){ // FILE INPUT
    cout << "Please Enter the name of the file" << endl;
    cin.get(FileName, 500); // gets the file name
    cin.ignore();
      cin.clear();
      ifstream rfile;
      rfile.open(FileName);
      rfile.getline(input, 500); // gets input from file
      //cout << "Input: " << input << endl;
  }
  maxSize( input, size); // gets size of tree
  //cout << "First Number: " << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  BuildTree(input, index, counterOne, wordCounter, parced, size, header); // builds the tree
  do{
  cout << "The Binary tree is now created. you can ADD, DELETE, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program" << endl; 
  cin.get(inputFunction, 20); // gets the function that the users want to do
  //cin.ignore();
  cin.clear();
    cin.ignore();
    if(strcmp(inputFunction, "ADD") == 0){ //add function that adds a node to the tree
    // cout << "add" << endl;
    cout << "Please enter the 3 digit value that you want to add to the tree" << endl;
    cin.get(additionInput, 20);
    cin.clear();
    cin.ignore();
    Node* two = new Node; // creates the new node
    (*two).setData(Parce(additionInput, index, counterOne, wordCounter, parced));
    //cout << "added data" << (*(*two).getData()) << endl;
    //Node*
    Add(header, two);
    //  cout << (*(*getParent(header, two, Parent)).getData()) << endl;
    //fixViolation(header, two);
    // balance2(header, two);
    cout << "there" << endl;
    // FixTree(header, two, getUncle(header, two, Uncle), getGrandParent(header, two, GrandParent), getParent(header, two, Parent));
    cout << "Added" << endl;
  }
    if(strcmp(inputFunction, "DELETE") == 0){ // delete function that deletes a node form tree
      cout << "I will finish this in the next part" << endl;
    }

    if(strcmp(inputFunction, "SEARCH") == 0){ // function that searches the binary tree and checks if a node exists or not
	//cout << "search" << endl;
	//int Length = (*size);
	cout << "Please enter the 3 digit number that you want to search for in the tree" << endl;
	cin.get(searchInput, 20); // what node should I search for
	cin.clear();
	cin.ignore();
	Search(header, Parce(searchInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){ // it exists
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	  //cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
      }
      if(strcmp(inputFunction, "PRINT") == 0){ // function that prints the tree in a way that clearly demonstrates the parent and child relationship
	  //  cout << "print" << endl;
	  int Length = (*size);
	  if(header == NULL){
	    cout << "tree is empty" << endl;
	  }
	  else{
	  Print(header, Length, 0, 1);
	  }
	  }
	if(strcmp(inputFunction, "QUIT") == 0){ // quit the program
	  quit = true;
	}
	//if(strcmp(inputFunction, "ADD") == 0){
	//  cout << "add" << endl;
	//  }

  }

  while(strcmp(inputFunction, "ADD") != 0 && strcmp(inputFunction, "SUBTRACT") != 0 && strcmp(inputFunction, "SEARCH") != 0 && strcmp(inputFunction, "PRINT") != 0 && strcmp(inputFunction, "QUIT") != 0 || quit == false); 
}
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced){ // this function pareces the input
  //cout << "parce" << endl;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] != ' ' && (*wordCounter) != 3){ // add to integer up to 3 digits
      (*wordCounter)++;
	if((*wordCounter) == 1){
	  (*parced) = (int)input[i]-48;
	}
      	if((*wordCounter) == 2){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}
	if((*wordCounter) == 3){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}

      
    }
    if(input[i] == ' '){ // there is a space
      (*wordCounter) = 0;
      (*counterOne)++;
    }
    if((*counterOne) == (*index) || input[i+1] == '\0'){ // I want this number pareced
      (*wordCounter) = 0;
      (*counterOne) = 0;
      return parced; // returns parced integer
    }
  }
  //return index;
}
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header){ // this builds the tree
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  // cout << "build tree" << endl;
  // cout << (*size) << endl;
  // Node* header = new Node;
  int* RED = new int;
  (*RED) = 1;
  int* BLACK = new int;
  (*BLACK) = 0;
  (*header).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the head
  (*header).setColor((*BLACK));
  (*index)++; 
  //cout << "head data" << (*(*header).getData()) << endl;
  do{
    Node* one = new Node;
    (*one).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the new node
    
    //(*one).setColor(BLACK);
    //cout << "data" << (*(*one).getData()) << endl;
    Add(header, one); // adds the new node
    // fixViolation(header, one);
    (*index)++;
  }
  while((*index) != (*size)+1); // continues to do this until all the numbers from input are put into the tree
}
void Add(Node* header, Node* add){ // this funcitons adds a node to the list
  // cout << "add" << endl;
  if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() != NULL){ // this node should go to the left because it is <= current node
    Add((*header).getLeft(), add);
  }
  //if((*(*header).getData()) >= (*(*add).getData()) && (*header).getLeft() == NULL){
     if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() == NULL){
       (*header).setLeft(add);
     } // add it to the end

     //if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() != NULL){
     if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() != NULL){ // this node should go to the right because it is > than current node
	Add((*header).getRight(), add);
      } 
      // if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() == NULL){
  if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() == NULL){
    (*header).setRight(add);
  } // add it to the end
}

void Print(Node* header, int length, int count, int i){ // this funciton prints the tree where the parent and child relationship is clear
  //cout << "print" << endl;
   int left = 2*i;
  int right = 2*i+1;
  // if(right <= length && (*header).getRight() != NULL){ // right child exist so recurse
      if((*header).getRight() != NULL){ // right child exist so recurse
    Print((*header).getRight(), length, count+1, right);
  }
  int current = count;
  while(count > 0){ // add spaces
    cout << "    ";
    count--;
  }
  //textcolor(RED);
  //system("Color 7C");
  if((*header).getColor() == 1){
    cout << (*(*header).getData()) << "R" << endl;
  }
  else{
    cout << (*(*header).getData()) << "B" << endl;
  }
  //cout << sortedHeap[i-1 << endl; // print current with some number of idenetation
  // if(left <= length && (*header).getLeft() != NULL){ // left child exists so recurse
      if((*header).getLeft() != NULL){ // left child exists so recurse
    Print((*header).getLeft(), length, current + 1, left);
  }
}


void Search(Node* header, int* searchData, bool* exists){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*(*header).getData()) == (*searchData)){ // THIS IS THE NODE
	 (*exists) = true;
       }

  if((*header).getRight() != NULL && (*searchData) > (*(*header).getData())){ // not the node search rihgt
	 Search((*header).getRight(), searchData, exists);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
  if((*header).getLeft() != NULL && (*searchData) <= (*(*header).getData())){ // not the node so search left
	 Search((*header).getLeft(), searchData, exists);
       }
}
void maxSize(char* input, int* size){ // this function gets the size of the tree
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == ' '){ // every time there is a space there should be a new node
      (*size)++;
    }
  }
}
/*
void rotateLeft(Node *&header, Node *&pointer)
{
  cout << "RR" << endl;
  Node *pointer_right = pointer->getRight();
  
    pointer->setRight(pointer_right->getLeft());
    
    if (pointer->getRight() != NULL)
      
      pointer->getRight()->setParent(pointer);
  
    pointer_right->setParent(pointer->getParent());
    
    if (pointer->getParent() == NULL)
        header = pointer_right;
  
    else if (pointer == pointer->getParent()->getLeft())
      pointer->getParent()->setLeft(pointer_right);
  
    else
      pointer->getParent()->setRight(pointer_right);
  
    pointer_right->setLeft(pointer);
    pointer->setParent(pointer_right);
  
}
void rotateRight(Node *&header, Node *&pointer)
{
  cout << "RR" << endl;
    Node *pointer_left = pointer->getLeft();
  
    pointer->setLeft(pointer_left->getRight());
  
    if (pointer->getLeft() != NULL)
      pointer->getLeft()->setParent(pointer);
  
    pointer_left->setParent( pointer->getParent());
  
    if (pointer->getParent() == NULL)
        header = pointer_left;
  
    else if (pointer == pointer->getParent()->getLeft())
      pointer->getParent()->setLeft(pointer_left);
  
    else
      pointer->getParent()->setRight(pointer_left);
  
    pointer_left->setRight( pointer);
    pointer->setParent( pointer_left);
}

void fixViolation(Node* &header, Node* &pointer)
{
  cout << "h1" << endl;
    Node* parent_pointer = NULL;
    Node* grand_parent_pointer = NULL;
    cout << "h2" << endl;
    while ((pointer != header) && (pointer->getColor() != 0) &&
           ((pointer->getParent())->getColor() == 1))
      {
      cout << "h21" << endl;
        parent_pointer = pointer->getParent();
        grand_parent_pointer = pointer->getParent()->getParent();
	cout << "h2" << endl;
        /*  Case : A
            Parent of pointer is left child of Grand-parent of pointer */
/*
if (parent_pointer == grand_parent_pointer->getLeft())
        {
	  cout << "z1" << endl;
  
            Node *uncle_pointer = grand_parent_pointer->getRight();
	    cout << "h3" << endl;
  
            /* Case : 1
               The uncle of pointer is also red
               Only Recoloring required */
	/*
	if (uncle_pointer != NULL && uncle_pointer->getColor() != 0)
            {
	      cout << "z2" << endl;
	      grand_parent_pointer->setColor(0);
	      parent_pointer->setColor(1);
	      uncle_pointer->setColor(1);
                pointer = grand_parent_pointer;
            }
  
            else
            {
	      cout << "z3" << endl;
	      cout << "h4" << endl;
                /* Case : 2
                   pointer is right child of its parent
                   Left-rotation required */
	/*
	if (pointer == parent_pointer->getRight())
                {
		  cout << "z4" << endl;
                    rotateLeft(header, parent_pointer);
                    pointer = parent_pointer;
                    parent_pointer = pointer->getParent();
                }
		cout << "z5" << endl;
  
                /* Case : 3
                   pointer is left child of its parent
                   Right-rotation required */
	/*
	rotateRight(header, grand_parent_pointer);
		// swap(parent_pointer->getColor(), grand_parent_pointer->getColor());
		cout << "h5" << endl;
	      int parentColor = parent_pointer->getColor();
	parent_pointer->setColor(grand_parent_pointer->getColor());
	grand_parent_pointer->setColor(parentColor);
                pointer = parent_pointer;
            }
        }
 //cout << "h6" << endl;
        /* Case : B
           Parent of pointer is right child of Grand-parent of pointer */
	/*
	else
        {
            Node *uncle_pointer = grand_parent_pointer->getLeft();
  cout << "h7" << endl;
            /*  Case : 1
                The uncle of pointer is also red
                Only Recoloring required */
	/*
	if ((uncle_pointer != NULL) && (uncle_pointer->getColor() != 0))
            {
	      grand_parent_pointer->setColor(0);
	      parent_pointer->setColor(1);
                uncle_pointer->setColor(1);
                pointer = grand_parent_pointer;
            }
            else
            {
	      cout << "h8" << endl;
                /* Case : 2
                   pointer is left child of its parent
                   Right-rotation required */
	/*
	if (pointer == parent_pointer->getLeft())
                {
                    rotateRight(header, parent_pointer);
                    pointer = parent_pointer;
                    parent_pointer = pointer->getParent();
                }
		cout << "h9" << endl;
                /* Case : 3
                   pointer is right child of its parent
                   Left-rotation required */
	/*      rotateLeft(header, grand_parent_pointer);
		// swap(parent_pointer->getColor(), grand_parent_pointer->getColor());
		int ParentC2 = parent_pointer->getColor();
	parent_pointer->setColor(grand_parent_pointer->getColor());
	grand_parent_pointer->setColor(ParentC2);
                pointer = parent_pointer;
            }
        }
    }
  
    header->setColor(0);
}
void balance(Node* &head, Node* &curr) {
  Node* parent = NULL;
  Node* grandparent = NULL;
  while ((curr != head) && (curr->getColor() != 1) &&
	 ((curr->getParent())->getColor() == 0)) {
    parent = curr->getParent();
    grandparent = parent->getParent();
    //Case A: parent = left child of grandparent
    if (parent == grandparent->getLeft()) {
      Node* uncle = grandparent->getRight();
      //Case 1: uncle = red, then only recolor
      if (uncle != NULL && uncle->getColor() != 1) {
	grandparent->setColor(0);//red
	parent->setColor(1);//black
	uncle->setColor(1);//black
	curr = grandparent;
      }
      else {
	//Case 2: curr = right child of parent, then rotate left
	if (curr == parent->getRight()) {
	  rotateLeft(head, parent);
	  curr = parent;
	  parent =  curr->getParent();
	}
	//Case 3: curr - left child of parent, then rotate right
	rotateRight(head, grandparent);
	//swap colors of parent and grandparent
	int tempC = parent->getColor();
	parent->setColor(grandparent->getColor());
	grandparent->setColor(tempC);
	curr = parent;
      }
    }
    //Case B: parent = right child of grandparent
    else {
      Node* uncle = grandparent->getLeft();
      //Case 1: uncle = red, then onyl recolor
      if (uncle != NULL && uncle->getColor() != 1) {
	grandparent->setColor(0);//red
	parent->setColor(1);//black
	uncle->setColor(1);//black
	curr = grandparent;
      }
      else {
	//Case 2: curr = left child of parent, then rotate right
	if (curr == parent->getLeft()) {
	  rotateRight(head, parent);
	  curr = parent;
	  parent = curr->getParent();
	}
	//Case 3: curr = right child of parent, then rotate left
	rotateLeft(head, grandparent);
	//swap color of parent and grandparent
	int tempC = parent->getColor();
	parent->setColor(grandparent->getColor());
	grandparent->setColor(tempC);
	curr = parent;
      }
    }
  }
  head->setColor(1);
    }
void balance2(Node* &head, Node* &curr) {
  cout << "b2" << endl;
  Node* parent = NULL;
  Node* grandparent = NULL;
  cout << "h1" << endl;
  while ((curr != head) && (curr->getColor() != 0) &&
	 ((curr->getParent())->getColor() == 1)) {
      cout << "h2" << endl;
    parent = curr->getParent();
    grandparent = parent->getParent();
    //Case A: parent = left child of grandparent
    if (parent == grandparent->getLeft()) {
      Node* uncle = grandparent->getRight();
      //Case 1: uncle = red, then only recolor
      if (uncle != NULL && uncle->getColor() != 0) {
	grandparent->setColor(1);//red
	parent->setColor(0);//black
	uncle->setColor(0);//black
	curr = grandparent;
      }
      else {
	//Case 2: curr = right child of parent, then rotate left
	if (curr == parent->getRight()) {
	  rotateLeft(head, parent);
	  curr = parent;
	  parent =  curr->getParent();
	}
	//Case 3: curr - left child of parent, then rotate right
	rotateRight(head, grandparent);
	//swap colors of parent and grandparent
	int tempC = parent->getColor();
	parent->setColor(grandparent->getColor());
	grandparent->setColor(tempC);
	curr = parent;
      }
    }
    //Case B: parent = right child of grandparent
    else {
      Node* uncle = grandparent->getLeft();
      //Case 1: uncle = red, then onyl recolor
      if (uncle != NULL && uncle->getColor() != 0) {
	grandparent->setColor(1);//red
	parent->setColor(0);//black
	uncle->setColor(0);//black
	curr = grandparent;
      }
      else {
	//Case 2: curr = left child of parent, then rotate right
	if (curr == parent->getLeft()) {
	  rotateRight(head, parent);
	  curr = parent;
	  parent = curr->getParent();
	}
	//Case 3: curr = right child of parent, then rotate left
	rotateLeft(head, grandparent);
	//swap color of parent and grandparent
	int tempC = parent->getColor();
	parent->setColor(grandparent->getColor());
	grandparent->setColor(tempC);
	curr = parent;
      }
    }
  }
  cout << "here" << endl;
  head->setColor(0);
}

*/
