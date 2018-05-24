#ifndef DLINKEDLIST_HPP
#define DLINKEDLIST_HPP
#include <string>
#include <sstream>
#include <iostream>

template <typename D>
struct DNode{
D Data;
DNode* Next, *Prev;

DNode(D d){
  Data = d;
  Next = nullptr;
  Prev = nullptr;
}

DNode(D d, DNode* p = nullptr, DNode* n = nullptr){
  Data = d;
  Next = n;
  Prev = p;
  }
};

/**
* Exception class for DLinkedList Specific exceptions
*/

class DListException : public std::runtime_error{
  std::string Message;
  const char* File;
  int         Line;
public:
  virtual const char* what() const throw(){
    return Message.c_str();
  }
  DListException(const char* msg, const char *file, int line) :
    std::runtime_error(msg){
        std::stringstream SS;
        SS << file << ":" << line << ": " << msg;
        Message = SS.str();

    }
    ~DListException() throw() {}
};
/** Macro for throwing exception with file and line information*/
#define THROW_DLEXP(msg) throw DListException(msg, __FILE__, __LINE__);

template <typename T>
class DLinkedList{

  DNode<T>* Head;

public:
  /** Default Constructor */
  DLinkedList(){Head = nullptr;}
  /**
  * Parameterized Constructor
  * @param T t The data to insert at the front of the DLinkedList
  */
  DLinkedList(T t){
    this->Head = this->CreateDNode(t);
  }

  /**
  * GetListHead
  * Gets the front node of the LinkedList
  * @param A Node<T> pointer to the front of the DLinkedList
  */
  DNode<T>* GetListHead(){return Head;}

  /**
  * PrintList
  * Produces a string object with the contents of the DLinkedList
  * @return A string object
  */
  std::string PrintList(){
    std::stringstream ss;
    DNode<T>* P = this->Head;
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
      this->Head = CreateDNode(t);
      return;
    }else{
      DNode<T>* P = CreateDNode(t);
      P->Next = Head;
      Head->Prev = P;
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
      this->Head = CreateDNode(t);
      return;
    }else{
      DNode<T>* P, *Q;
      Q = Head;
      P = Q->Next;
      while(P != nullptr){
        Q = P;
        P = P->Next;
      }
      P = CreateDNode(t);
      Q->Next = P;
      P->Prev = Q;
    }
  }

  /**
  * InsertAt
  * Pushes a Node onto the front of the list
  * @param Unsigned pos Index of the position where the data will be inserted
  * @param T t The data to insert into the list
  */
  void InsertAt(unsigned pos, T t){
    DNode<T>* P, *Q, *R;
    Q = Head;
    P = Q->Next;
    for(unsigned i = 1; i<pos; i++){
      Q=P;
      P=P->Next;
    }
    R = CreateDNode(t, Q, P);
    Q->Next = R;
    P->Prev = R;
  }

  /**
  * PopFront
  * Removes the data at the front of the list and returns the node containing the data
  * @return A node pointer containing the data at the front of the list
  */
  DNode<T>*  PopFront(){
    DNode<T>* P = this->Head;
    this->Head = P->Next;
    P->Prev = nullptr;
    P->Next = nullptr;
    return P;
  }
  /**
  * PopBack
  * Removes the data at the back of the list and returns the node containing the data
  * @return A node pointer containing the data at the back of the list
  */
  DNode<T>*  PopBack(){
    DNode<T>* Q = this->Head;
    DNode<T>* P = Q->Next;
    while(P->Next != nullptr){
      Q = P;
      P = P->Next;
    }
    Q->Next = nullptr;
    P->Prev = nullptr;
    return P;
  }
  /**
  * PopNodeAt
  * Removes the data at the indicated index of the list and returns the node containing the data
  * @return A node pointer containing the data at the back of the list
  */
  DNode<T>* PopNodeAt(unsigned pos){
    DNode<T>* P, *Q;
    Q = Head;
    P = Q->Next;
    for(unsigned i = 1; i<pos; i++){
      Q=P;
      P=P->Next;
    }
    Q->Next = P->Next;
    Q->Next->Prev = Q;
    P->Next = nullptr;
    P->Prev = nullptr;
    return P;
  }

  /**
  * Size
  * Counts the number of Nodes in the list
  * @return An unsigned int of size of the list
  */
  unsigned Size(){
    unsigned i = 0;
    DNode<T>* P = this->Head;
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
    DNode<T> *P, *Q = nullptr;
    P=this->Head;
    while(P->Next != nullptr){
      Q = this->PopBack();
      delete Q;
      Q = nullptr;
    }
    this->Head = nullptr;
    delete P;
  }
  /**
  * Overloads the [] operator to allow index referencing of the data held in the
  * node at that index, but not the node itself.
  */
  T operator[](unsigned index){
    T t;
    if(this->Size() <= index){
      std::stringstream SS;
      SS << "IndexOutOfBounds: index " << index << " was passed but "
            << "list has only " << this->Size() << " elements";
      THROW_DLEXP(SS.str().c_str());
    }

    DNode<T>* P = this->Head;
    int i = 0;
    while(i != index){
      P = P->Next;
      i++;
    }
    return P->Data;
  }

private:
  /**
  * CreateNode
  * Creates a new node containing the given data and Next set to null
  * @return A node pointer to the new node
  */
  DNode<T>* CreateDNode(T t){
    return new DNode<T>(t, nullptr, nullptr);
  }
};

#endif // DLINKEDLIST_HPP
