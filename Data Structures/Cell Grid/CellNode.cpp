/**
 *     This source code was written by the Author on the stated
 *         date of creation. You may use this code for any
 *         non-Commercial purpose with credit given to the Author.
 *         For commercial use, contact the Author at the listed
 *         contact method.
 *
 *     CellNode.cpp
 *         Date Created:    December 1, 2017
 *         Type:            Implementation file
 *         Description:     Defines non-trivial functions 
 *							  for CellNode.h
 *         Dependencies:    CellNode.h
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#include "CellNode.h"
  /*  DEFAULT CONSTRUCTOR         */
CellNode::CellNode(){
  this->cell_ID   = -1;
  this->cell      = *(new Cell());
  this->visited   = false;
  this->inQueue   = false;
  this->releaseLinkedNodes();
}
/*  PARAMETERIZED CONSTRUCTOR     */
CellNode::CellNode(const Cell &c, int id){
  this->cell_ID   = id;
  this->cell      = c;
  this->visited   = false;
  this->inQueue   = false;
  this->releaseLinkedNodes();
}
/*  COPY CONSTRUCTOR              */
CellNode::CellNode(CellNode& cn){
  this->cell_ID   = cn.cell_ID;
  this->cell      = cn.cell;
  this->up        = cn.up;
  this->left      = cn.left;
  this->down      = cn.down;
  this->right     = cn.right;
  this->visited   = cn.visited;
  this->inQueue   = cn.inQueue;
}
/*  ASSIGNMENT OPERATOR (VALUE)   */
CellNode CellNode::operator=(CellNode &rhs){
  this->cell_ID   = rhs.cell_ID;
  this->cell      = rhs.cell;
  this->up        = rhs.up;
  this->down      = rhs.down;
  this->left      = rhs.left;
  this->right     = rhs.right;
  this->next      = rhs.next;
  return(*this);
}
/*  ASSIGNMENT OPERATOR (POINTER) */
CellNode* CellNode::operator=(CellNode* rhs){
  this->cell_ID   = rhs->cell_ID;
  this->cell      = rhs->cell;
  this->up        = rhs->up;
  this->down      = rhs->down;
  this->left      = rhs->left;
  this->right     = rhs->right;
  this->next      = rhs->next;
  return this;
}
/*  TRANSFER NODE TO NEW MEMORY LOCATION  */
/*    'node' is the already allocated     */
/*    memory location 'this' will move to */
void CellNode::transferNode(CellNode *node){
  node->cell_ID   = cell_ID;
  node->cell      = cell;
  node->up        = up;
  node->left      = left;
  node->down      = down;
  node->right     = right;
  node->next      = next;
  node->visited   = visited;
  node->inQueue   = inQueue;
}
/*  CREATES A STRING WITH NODE VALUES  */
std::string  CellNode::toString(){
  std::stringstream ss;
  ss << "Cell ID: " << this->cell_ID
     << "\n  Cell Data: " << this->cell.value;
    if(this->up != nullptr)
      ss  << "\n       Up Node: " << this->up->cell_ID;
    else
      ss  << "\n       Up Node: NULLPTR";
    if(this->left != nullptr)
      ss  << "\n     Left Node: " << this->left->cell_ID;
    else
      ss  << "\n     Left Node: NULLPTR";
    if(this->down != nullptr)
      ss << "\n      Down Node: " << this->down->cell_ID;
    else
      ss << "\n      Down Node: NULLPTR";
    if(this->right != nullptr)
      ss << "\n     Right Node: " << this->right->cell_ID;
    else
      ss << "\n     Right Node: NULLPTR";
    ss  << "\n       Visited: " << ((this->visited)? "Yes":"No")
      << "\n      in Queue: " << ((this->inQueue)? "Yes":"No")
      << std::endl;;
  return ss.str();
}
/*  ADDS '1' TO ADJACENT CELL VALUES    */
void CellNode::addToAdjacentCells(int dist){
  if(this->up != nullptr && this->up->cell.value == -1
     && !this->up->visited){
    this->up->cell.value = dist;
  }
  if(this->left != nullptr && this->left->cell.value == -1
     && !this->left->visited){
    this->left->cell.value = dist;
  }
  if(this->down != nullptr && this->down->cell.value == -1
     && !this->down->visited){
    this->down->cell.value = dist;
  }
  if(this->right != nullptr && this->right->cell.value == -1
     && !this->right->visited){
    this->right->cell.value = dist;
  }
}

