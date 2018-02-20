/**
 *     	This source code was written by the Author on the stated
 *      	date of creation. You may use this code for any
 *       	non-Commercial purpose with credit given to the Author.
 *       	For commercial use, contact the Author at the listed
 *     		contact method.
 *
 *     	CellQueue.h
 *         Date Created:    December 1, 2017
 *         Type:            Data Structure
 *         Description:     A queue for CellNodes
 *         Dependencies:    CellNode.h
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#ifndef CELLQUEUE_H
#define CELLQUEUE_H
#include "CellNode.h"
class CellQueue{
  CellNode *qFront, *qLast, *qHeld, **queue;
  int      numQCells, capacity;
  bool     pathFound, planFound;
public:
  //  		Constructors  		//
	/**  Default Constructor  */
  CellQueue(int c);

  // 		Destructor   		//
	/**   	~CellQueue()	*/
  ~CellQueue(){
	this->emptyQueue();
	delete [] this->queue;
	delete [] this->qFront;
	delete [] this->qLast;
	delete [] this->qHeld;
  }

    /*  Mutators  */
private:
  /**
  *   incrementCellsInQueue()
  *     Increments the number of cells the queue currently has
  */
  inline const void incrementCellsInQueue()   {this->numQCells++;	}
  /**
  *   deccrementCellsInQueue()
  *     Decrements the number of cells the queue currently has
  */
  inline const void decrementCellsInQueue()   {this->numQCells--;   }
  /**
  *   initNumCells()
  *     Initialized the number of cells in the queue to zero
  */
  inline const void initNumCells()            {this->numQCells = 0; }
  /**
  *   setQFront()
  *     Sets the pointer to the front of the queue
  */
  inline const void setQFront(CellNode* cell) {this->qFront = cell; }
  /**
  *   setQLast()
  *     Sets the pointer to the back of the queue
  */
  inline const void setQLast(CellNode* cell)  {this->qLast = cell;  }
  /**
  *   setQHeld()
  *     Sets the pointer to the working memory of the queue
  */
  inline const void setQHeld(CellNode* cell)  {cell->transferNode(qHeld);}
  /**
  *   setCapacity()
  *     Sets the maximum capacity of the queue
  */
  inline const void setCapacity(int c)        {this->capacity   = c;}
	/*  Accessors */
  /**
  *   getFront()
  *     Gets a pointer to the node at the front of the queue, does not remove it
  *   @return A pointer to a CellNode
  */
	inline CellNode*  getFront()              {return qFront;       }
  /**
  *   getFront()
  *     Gets a pointer to the node at the front of the queue; does not remove it
  *   @return A pointer to a CellNode
  */
	inline CellNode*  getLast()               {return qLast;        }
  /**
  *   getHeld()
  *     Gets a pointer to the node in queue's working memory; does not remove it
  *   @return A pointer to a CellNode
  */
	inline CellNode*  getHeld()               {return qHeld;        }
public:
  /**
  *   peek()
  *     Gets a constant pointer to the node at the front of the queue
  *   @return A const pointer to a CellNode as a constant
  */
  const CellNode*   peek()                    {return qFront;       }const
  /**
  *   getNumCells()
  *     Gets the number of cells currently in the queue
  *   @return An int of the number of cells
  */
	inline int        getNumCells()           {return numQCells;    }
  /**
  *   isEmpty()
  *     Queries whether the queue is empty
  *   @return A bool, true if queue is empty
  */
	inline bool       isEmpty()               {return numQCells==0; }
	  /* Data Manipulation */
  /**
  *   pop()
  *     Removes the front element of the queue, shifts all
  *       values forward
  *   @return A pointer to the cell popped from queue
  */
  CellNode*	pop();
  /**
  *   push()
  *     Adds cell pointer to back of the Queue
  *   @param node A pointer to the CellNode to add to the queue
  */
  void	push(CellNode* node);
  /**
  *   emptyQueue()
  *     Empties the queue of any nodes it contains
  */
  void  emptyQueue();
  /**
  *   processWavefront
  *     Takes a given node and, using a wavefront method, moves to any adjacent
  *     nodes and marks the distance from the initial node in current node's,
  *     cell, in the cell data member 'value', until it reaches some target cell
  *     or has moved through the entire array of cells. Access node distance via
  *     CellNodeArray[index]->cell.value
  *   @param  n - A CellNode from which the wavefront propogates.
  *                 On first call, this is the target cell the node distances
  *                 reference.
  *   @param  s - A CellNode that, once reached by the wavefront, will stop the
  *                 processing of other nodes & return control to initial caller
  */
	bool  processWavefront(CellNode* n, CellNode* s);
  /**
  *   cellsInQueue()
  *     produces a formatted string of all the cells within the Queue or a message
  *       if the Queue is empty.
  *   @return A formatted string
  */
	std::string cellsInQueue();
};

#endif	//	CELLQUEUE_H
