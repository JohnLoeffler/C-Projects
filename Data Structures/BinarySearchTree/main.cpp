#include <iostream>
#include <fstream>

#include "Operation.hpp"
#include "BSTree.hpp"
#include <random>

int main(){

  srand(1);
  BSTree<int>* Tree = new BSTree<int>(50);
  for(int i = 1; i <= 25; i++){
    int j = rand()%100;
    Tree->Insert(Tree->GetRoot(), 1, j);
  }
  Tree->SetOperation(Operation::ADD);
  Tree->PreTraverse(Tree->GetRoot());
  Tree->InTraverse(Tree->GetRoot());
  Tree->PostTraverse(Tree->GetRoot());

  std::cout << Tree->GetCurrentOperator()->ReturnResults_int() << std::endl << std::endl;

  Tree->SetOperation(Operation::MULTIPLY);
  Tree->PreTraverse(Tree->GetRoot());
  Tree->InTraverse(Tree->GetRoot());
  Tree->PostTraverse(Tree->GetRoot());

  Tree->SetOperation(Operation::PRINT);
  std::cout << "====================================" << std:: endl;
  Tree->PreTraverse(Tree->GetRoot());
  Tree->InTraverse(Tree->GetRoot());
  Tree->PostTraverse(Tree->GetRoot());
  std::cout << "====================================" << std:: endl;

  for(int i = 0; i < 25; i++){
    int j = rand()%100;
    Tree->Delete(Tree->GetRoot(), j);
  }

  std::cout << "====================================" << std:: endl;
  Tree->PreTraverse(Tree->GetRoot());
  Tree->InTraverse(Tree->GetRoot());
  Tree->PostTraverse(Tree->GetRoot());
  std::cout << "====================================" << std:: endl;

  Tree->DeleteTree(Tree->GetRoot());
  Tree->Delete(Tree->GetRoot(), Tree->GetRoot()->Data);
  delete Tree;

  BSTree<std::string> *StrTree = new BSTree<std::string>("Mayor");
  std::ifstream infile("Words.txt");
  std::string in;
  while(!infile.eof()){
    infile >> in;
    StrTree->Insert(StrTree->GetRoot(), 1, in);
  }

  StrTree->SetOperation(Operation::ADD);
  StrTree->PreTraverse(StrTree->GetRoot());
  StrTree->InTraverse(StrTree->GetRoot());
  StrTree->PostTraverse(StrTree->GetRoot());


  return 0;

}
