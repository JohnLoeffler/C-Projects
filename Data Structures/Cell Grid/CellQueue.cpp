/**
 *     	CellQueue.cpp
 *         Date Created:    December 1, 2017
 *         Type:            Implementation file
 *         Description:     Defines the non-trivial functions in CellQueue.h
 *         Dependencies:    CellQueue.h, <cstdlib>, <iomanip>, <iostream>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#include "CellQueue.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
/**
*   CellQueue()
*     Default constructor
*   @param  c An int of the capacity of the CellQueue
*/
CellQueue::CellQueue(int c){
  this->qHeld     = new CellNode();
	this->initNumCells();
  this->queue     = new CellNode*[c];
  this->setQFront(nullptr);
	this->setQLast(nullptr);
  this->pathFound = false;
}
/** push() Pushes the passed node onto the back of the Queue	*/
void CellQueue::push(CellNode* node){
  if(node == nullptr){
    return;
  }
  int count = 0; //	Count the nodes we traverse
  if(node->inQueue){
    return;
  }
  if(node->visited){ // Prevents us getting caught in an infinite loop
    return;
  }
  if(this->qFront == nullptr){	//	If the queue is empty
    node->visited = false;
    this->queue[0] = node;
    this->qFront = queue[0];
    this->qLast = queue[0];
    this->incrementCellsInQueue();
  }else{
    node->visited = false;
    CellNode *s;
    s = qFront;
    while(s != this->qLast){//  Go to the last cell in queue
      count++;
      if(s == nullptr){
        return;
      }else{
        s = s->next;
      }
    }
    queue[count+1] = node;//  Place cell on the end of the queue
    queue[count]->next = queue[count+1];
    this->qLast = queue[count+1];
    this->incrementCellsInQueue();
  }
  node->inQueue = true;
}
/** pop() Removes the front element of the queue, shifts all values forward */
CellNode*	CellQueue::pop(){ 
  qFront->transferNode(qHeld);// Put node in reserved memory for access out of scope
  for(int i = 0; i < this->getNumCells()-1; i++){
    if(this->getNumCells()>1){
	  queue[i] = queue[i+1];  //  Shift all nodes left
	  queue[i]->next  = queue[i+1]->next;
    }
  }
  this->decrementCellsInQueue();
  if(this->numQCells == 0){
    this->qFront=   queue[0];
    this->qFront->next = nullptr;
  }else{
    this->qFront = queue[0];
    this->qFront->next = queue[1];

    this->qLast = queue[this->getNumCells()-1];
  }
  queue[this->getNumCells()]  = nullptr;
  this->qHeld->inQueue = false;

  return this->qHeld;
}
/**
*   processWavefront()
*     A four part function that takes a given target node and working outwards,
*       recursively assigns a value to each subsequent, adjacent cell that is 1
*       more than the previous cell if the adjacent cell has not been already
*       changed or is marked with a special value. Special values indicate that
*       the cell should not be unprocessed. First, function checks that the given
*       cell is valid and that the path to the end cell has not been found. When
*       n and start are the same, a path has been found. Second, it calls 
*		CellNode::addToAdjacentCells() on the n cell. Third, if an adjacent cell
*		has not been processed already, it adds that node to the CellQueue to be
*		processed. Fourth, takes the next node from the CellQueue and passes it to
*		a recursive call processWavefront() within an if-else, so that if the path
*		to the start cell is reached, the function returns true and the stack will
*		unwind. If the Queue is empty and the start cell hasn't been found after
*		all cells have been processed, this function will return false as it unwinds.
*/
bool  CellQueue::processWavefront(CellNode* n, CellNode* start){
  if(pathFound){
    return true;
  }
  if(n->cell.value < -1){  //  INVALID
    return false;
  }
  if(n->cell_ID == start->cell_ID){
    this->pathFound = true; //  SUCCESS CONDITION
  }
  if(n->visited){
      return false;
  }
  n->addToAdjacentCells(n->cell.value+1);
  /* After adding one to adjacent cells, adds unvisited cellnodes to the queue */
  if(n->up != nullptr && !n->up->visited){
    this->push(n->up);						
  }													
  if(n->left != nullptr && !n->left->visited){
    this->push(n->left);
  }
  if(n->down != nullptr && !n->down->visited){
    this->push(n->down);
  }
  if(n->right != nullptr && !n->right->visited){
    this->push(n->right);
  }
  n->visited = true;  //  Flags this cellnode as processed
  if(this->processWavefront(this->pop(), start)){
    return true;
  }else if(this->isEmpty()){
    return false;
  }else{
    return processWavefront(this->pop(), start);
  }
}
/**  cellsInQueue() Prints the cells that are currently in the queue */
std::string CellQueue::cellsInQueue(){
  std::stringstream ss;
  if(!this->isEmpty()){
    for(int i = 0; i < this->numQCells; i++){
      ss  << "[" << std::setw(3) << queue[i]->cell_ID << "]";
      if(i %16 == 15){
        ss  <<  "\n";
      }
    }
  }else{
    ss  <<  "The Queue is empty...\n";
  }
  return ss.str();
}
/**
*   emptyQueue()
*     Pops the Queue until empty and assigns nullptr to qFront, qLast, and qHeld
*/
void  CellQueue::emptyQueue(){
  while(!this->isEmpty()){
    this->pop()->visited=false;
  }
  this->qFront  = nullptr;
  this->qLast   = nullptr;
  this->qHeld   = nullptr;
}

