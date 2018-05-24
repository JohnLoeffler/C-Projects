#include <iostream>
#include <fstream>

//#include "DLinkedList.hpp"
#include "Multiplier.hpp"
#include "Adder.hpp"
#include "Concatenator.hpp"
#include "Printer.h"
#include "BSTree.hpp"
#include <random>

int main(){

  srand(1);
  BSTree<int>* Tree = new BSTree<int>();
  for(int i = 1; i <= 20; i++){
    int j = rand()%10;
    Tree->Insert(Tree->GetRoot(), j);
  }
  Tree->SetOperation(Operation::ADD);
  Tree->PreTraverse(Tree->GetRoot());
  std::cout << Tree->GetOperator()->ReturnResults() << std::endl << std::endl;
  Printer<int>* printer = new Printer<int>();

  Tree->SetOperation(Operation::PRINT);
  std::cout << "====================================" << std:: endl;
  Tree->PreTraverse(Tree->GetRoot());
  std::cout << "====================================" << std:: endl;


  //infile.open("Words.txt");

  return 0;

}
