/**
 *     This source code was written by the Author on the stated
 *         date of creation. You may use this code for any
 *         non-Commercial purpose with credit given to the Author.
 *         For commercial use, contact the Author at the listed
 *         contact method.
 *
 *     CellNode.h
 *         Date Created:    December 1, 2017
 *         Type:            Data Structure
 *         Description:     A Structure for a traversable Cell in a
 *						   	  2D grid
 *         Dependencies:    Cell.h, <string>, <sstream>, <iostream>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#ifndef CELLNODE_H
#define CELLNODE_H

#include <string>
#include <sstream>
#include <iostream>
#include "Cell.h"

struct CellNode{
  Cell        cell;
  CellNode    *up, *down, *left, *right, *next;
  int         cell_ID;
  bool        visited, inQueue, waypoint, onPath;
    /*      Constructors        */
  /**
  *   Default Constructor
  */
  CellNode();
  /**
  *   Parameterized Constructor
  */
  CellNode(const Cell &c, int id);
  /**
  *   Copy Constructor  Copies data and node connections
  */
  CellNode(CellNode& cn);
  /** Destructor                */
  ~CellNode(){this->releaseLinkedNodes();}

    /*  Overloaded Operators    */
        /**     Assignment  */
  CellNode   operator= (CellNode &rhs);
  CellNode*  operator= (CellNode* rhs);
    /*      Member Methods     */
  /**
  *   releaseLinkedNodes()
  *     Decouples this node from any other nodes to prevent unintended recursive
  *       destructor calls to neighboring nodes.  As such, each cell MUST be
  *       deleted separately or as part of another function
  */
  inline void releaseLinkedNodes(){
    this->up        = nullptr;
    this->left      = nullptr;
    this->down      = nullptr;
    this->right     = nullptr;
  }
  /**
  *   transferNode(CellNode*)
  *     Transfers this node to another memory location
  *   @param node A pointer to the new memory to transfer this node to
  */
  void transferNode(CellNode *node);
  /**
  *   toString()
  *     Creates a string of the contents of this node
  *   @return A string of the node contents
  */
  std::string  toString();
  /**
  *   addToAdjacentCells()
  *     Changes the value of the node above, below, to the left, and to the
  *       right of the current node by the value of the parameter + 1 which,
  *		  when called recursively by the target cell you are trying to 
  *		  reach, will assign distance values to each cell in a waveform
  *		  pattern that can be used to find the shortest path to the target
  *   @param  value The Value of the current node
  */
  void addToAdjacentCells(int value);
};
#endif	//	CELLNODE_H
