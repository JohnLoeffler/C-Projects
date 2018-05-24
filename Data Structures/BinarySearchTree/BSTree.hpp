#ifndef BSTREE_HPP
#define BSTREE_HPP
#include "Operation.hpp"

template <typename D>
struct TNode{
    /**Node Metadata**/
  int Depth, Side;
    /*****************/
  D Data;
  TNode *Left, *Right;

  /** Constructor */
  TNode(D d){
    this->Data = d;
    this->Left = nullptr;
    this->Right= nullptr;
  }
  /** Destructor */
  ~TNode(){
    delete Left;
    delete Right;
  };
};

/**
* Exception class designed for exceptions specific to the BSTree class
*/
/*
class BSTreeException : std::runtime_error{
  std::string Message;
public:
  virtual const char* what() const throw(){
    return Message.c_str();
  }
  BSTreeException(const char* msg, const char *file, int line) :
    std::runtime_error(msg){
        std::stringstream SS;
        SS << file << ":" << line << ": " << msg;
        Message = SS.str();
  }
  ~DListException() throw() {}
};
*/
/**
* Generic implementation of a Binary Search Tree
*/
template <typename T>
class BSTree{
  /** These fields are meta data for the structure for analysis **/
  int NodeCount, Depth;
  float Weight;//1.0 for Perfect balance, Weighted Left when < 1.0, Right when >
  /***************************************************************/

  TNode<T>*     Root;
  Operator<T>*  Optr;

public:

  BSTree(TNode<T>* root = nullptr){
    this->Root = root;

  }
/*
  BSTree(TNode<T>* root = nullptr, Operation<T> operation){
    this->Root = root;
    Operator = operation;
    this->NodeCount = 0;
    this->Depth = 0;
  }
*/
  Operator<T>*  Operator_Cast(Operator<T>* Op){ return Op;}

  /**
  * Set the operation to be performed on the tree
  * @param operation The operation type to be performed
  */
  void SetOperation(Operation operation){
    switch(operation){
    case Operation::PRINT:
      Optr = Operator_Cast(new Printer<T>());
      break;
    case Operation::ADD:
      Optr = Operator_Cast(new Adder<T>(0));
      break;
    case Operation::MULTIPLY:
      Optr = Operator_Cast(new Multiplier<T>(1));
      break;
    //case Operation::CONCAT:
    //  Optr = Operator_Cast(new Concatenator(""));
    //  break;
    }
  }

  /**
  * Gets the root of the tree
  * @return A pointer to a templated-type TNode
  */
  TNode<T>* GetRoot(){return this->Root;}

  /**
  * Gets the number of nodes in the tree
  * @return An int of the number of nodes
  */
  int GetNodeCount(){return this->NodeCount;}

  /**
  * Gets the depth of the longest branch of the tree
  * @return An int of the number of levels in the tree
  */
  int GetDepth(){return this->Depth;}

  /**
  *
  *
  */
  Operator<T>*  GetOperator(){return Optr;}
  /**
  * Traverse the tree in Preorder fashion and perform the desired operation
  * @param N The current node
  * @param O The Operation Object that will perform a desired task
  */
  void PreTraverse(TNode<T> *N){
    if(N == nullptr){
      return;

      /* Perform an operation with the current node's data */
      std::cout << "In PreTrav, output is : " << N->Data << std::endl;
      Optr->Operate(N->Data);

      PreTraverse(N->Left);
      PreTraverse(N->Right);
    }
  }

  /**
  * Traverse the tree in Inorder fashion and perform the desired operation
  * @param N The current node
  * @param O The Operation Object that will perform a desired task
  */
  void InTraverse(TNode<T> *N){
    if(N == nullptr){
      return;

      InTraverse(N->Left);

      /* Perform an operation with the current node's data */
      Optr->Operate(N->Data);

      InTraverse(N->Right);
    }
  }

  /**
  * Traverse the tree in Postorder fashion and perform the desired operation
  * @param N The current node
  * @param O The Operation Object that will perform a desired task
  */
  void PostTraverse(TNode<T> *N){
    if(N == nullptr){
      return;

      PostTraverse(N->Left);
      PostTraverse(N->Right);

      /* Perform an operation with the current node's data */
      Optr->Operate(N->Data);
    }
  }

  /**
  * Finds the Lowest value in a tree
  * @param N The current node
  * @return The lowest value found for the given tree
  */
  TNode<T>* MinimumValueNode(TNode<T>* N){
    TNode<T>* P = N;
    while(P->Left != nullptr){
      P = P->Left;
    }
    return P;
  }

  /**
  * Finds the Greatest value in a tree
  * @param N The current node
  * @return The lowest value found for the given tree
  */
  TNode<T>* MaximumValueNode(TNode<T>* N){
    TNode<T>* P = N;
    while(P->Right != nullptr){
      P = P->Right;
    }
    return P;
  }

  /**
  * Inserts the new Data into the tree in the proper order
  * @param N The parent node of the current node
  * @param N The current node of the traversal
  * @param D The data to insert into the tree
  * @return A pointer to the current node
  */
  TNode<T>* Insert(TNode<T>* N, T D){

    /* If Node is null, return a new Node using the parameter data */
    if(N == nullptr){
      return new TNode<T>(D);
    }
    /* Else keep traversing the tree until the proper position is found*/
    if(D < N->Data){
      N->Left = this->Insert(N->Left, D);
      std::cout << "Data to the Left of [" << N->Data << "] is (" << N->Left->Data << ")\n";
    }else if(D > N->Data){
      N->Right= this->Insert(N->Right, D);
      std::cout << "Data to the Right of [" << N->Data << "] is (" << N->Right->Data << ")\n";
    }
    return N;
  }

  /**
  * Deletes a value from the tree
  * @param N The current node
  * @param D The Data value to be deleted
  * @return The current node
  */
  TNode<T>* Delete(TNode<T>* N, T D){
    if(N == nullptr){
      return N;
    }
    /* Search through the tree for the node with the data */
    if(D < N->Data)
      N->Left = Delete(N->Left, D);
    else if(D > N->Data)
      N->Right= Delete(N->Right, D);
    else if(N->Data == D){  //  found it
      //  If there is only one or no child nodes
      if(N->Left == nullptr){
        TNode<T>* temp = N->Right;
        delete N;
        return temp;
      }else if(N->Right == nullptr){
        TNode<T>* temp = N->Left;
        delete N;
        return temp;
      }
      /*
      * If there are two child nodes, we need to swap the smallest value that is
      * larger than the value being deleted into the current node and delete
      * node that held the data we are swapping in, which is in the left most
      * leaf of the right child node
      */
      TNode<T>* temp = MinimumValueNode(N->Right);

      N->Data = temp->Data;
      N->Right = Delete(N->Right, temp->Data);
    }
    return N;
  }

};
#endif // BSTREE_HPP
