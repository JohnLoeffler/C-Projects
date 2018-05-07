#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <sstream>
#include <iostream>

template <typename D>
struct Node{
D Data;
Node* Next;

Node(D d){
  Data = d;
}

Node(D d, Node* n){
  Data = d;
  Next = n;
  }
};

template <typename T>
class LinkedList{

  Node<T>* Head;

public:
  /** Default Constructor */
  LinkedList(){Head = nullptr;}
  /**
  * Parameterized Constructor
  * @param T t The data to insert at the front of the LinkedList
  */
  LinkedList(T t){
    this->Head = this->CreateNode(t);
  }
  /**
  * GetListHead
  * Gets the front node of the LinkedList
  * @param A Node<T> pointer to the front of the LinkedList
  */
  Node<T>* GetListHead(){return Head;}

  /**
  * PrintList
  * Produces a string object with the contents of the LinkedList
  * @return A string object
  */
  std::string PrintList(){
    std::stringstream ss;
    Node<T>* P = this->Head;
    while(P != nullptr){
      ss << P->Data << " ";
      P= P->Next;
    }
    return ss.str();
  }
  /**
  * Push_Front
  * Pushes a Node onto the front of the list
  * @param T t The data to push onto the list
  */
  void PushFront(T t){
    if(this->Head == nullptr){
      this->Head = CreateNode(t);
      return;
    }else{
      Node<T>* P = CreateNode(t);
      P->Next = Head;
      this->Head = P;
    }
  }
  /**
  * Push_Back
  * Pushes a Node onto the back of the list
  * @param T t The data to push onto the list
  */
  void PushBack(T t){
    if(this->Head == nullptr){
      this->Head = CreateNode(t);
      return;
    }else{
      Node<T>* P, *Q;
      Q = Head;
      P = Q->Next;
      while(P != nullptr){
        Q = P;
        P = P->Next;
      }
      P = CreateNode(t);
      Q->Next = P;
    }
  }

  /**
  * InsertAt
  * Pushes a Node onto the front of the list
  * @param Unsigned pos Index of the position where the data will be inserted
  * @param T t The data to insert into the list
  */
  void InsertAt(unsigned pos, T t){
    Node<T>* P, *Q, *R;
    Q = Head;
    P = Q->Next;
    for(unsigned i = 1; i<pos; i++){
      Q=P;
      P=P->Next;
    }
    R = CreateNode(t);
    Q->Next = R;
    R->Next = P;
  }

  /**
  * PopFront
  * Removes the data at the front of the list and returns the node containing the data
  * @return A node pointer containing the data at the front of the list
  */
  Node<T>*  PopFront(){
    Node<T>* P = this->Head;
    this->Head = P->Next;
    return P;
  }
  /**
  * PopBack
  * Removes the data at the back of the list and returns the node containing the data
  * @return A node pointer containing the data at the back of the list
  */
  Node<T>*  PopBack(){
    Node<T>* Q = this->Head;
    Node<T>* P = Q->Next;
    while(P->Next != nullptr){
      Q = P;
      P = P->Next;
    }
    Q->Next = nullptr;
    return P;
  }
  /**
  * PopNodeAt
  * Removes the data at the indicated index of the list and returns the node containing the data
  * @return A node pointer containing the data at the back of the list
  */
  Node<T>* PopNodeAt(unsigned pos){
    Node<T>* P, *Q;
    Q = Head;
    P = Q->Next;
    for(unsigned i = 1; i<pos; i++){
      Q=P;
      P=P->Next;
    }
    Q->Next = P->Next;
    return P;
  }

  /**
  * Size
  * Counts the number of Nodes in the list
  * @return An unsigned int of size of the list
  */
  unsigned Size(){
    unsigned i = 0;
    Node<T>* P = this->Head;
    while(P != nullptr){
      i++;
      P = P->Next;
    }
    return i;
  }

  /**
  * Clear
  * Clears the list of all values
  */
  void Clear(){
    Node<T> *P, *Q = nullptr;
    P=this->Head;
    while(P->Next != nullptr){
      Q = this->PopBack();
      delete Q;
      Q = nullptr;
    }
    this->Head = nullptr;
    delete P;
  }
private:
  /**
  * CreateNode
  * Creates a new node containing the given data and Next set to null
  * @return A node pointer to the new node
  */
  Node<T>* CreateNode(T t){
    return new Node<T>(t, nullptr);
  }
};

#endif // LINKEDLIST_H
