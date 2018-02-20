/**
 *     This source code was written by the Author on the stated
 *         date of creation. You may use this code for any
 *         non-Commercial purpose with credit given to the Author.
 *         For commercial use, contact the Author at the listed
 *         contact method.
 *
 *     Cell.h
 *         Date Created:    December 1, 2017
 *         Type:            A Data type representing the contents of a CellNode
 *         Description:     Data type
 *         Dependencies:    Coordinates.h
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#ifndef CELL_H
#define CELL_H

#include "Coordinates.h"

struct	Cell{
  Coordinates	  coord;
  int		        value;
  int		        row, column;

  /*      Constructors        */
      /**     Default     */
  Cell(){};
  /**
  *  Parameterized constructor
  *
  *  @param  cr  A Coordinate of the Cell
  *  @param  val An int
  *  @param  r   An int of the row of the cell in relation to a grid map
  *  @param  cm  An int of the column of the cell in relation to a grid map
  */
  Cell(Coordinates cr, int val, int r, int cm){
	this->coord	  =	cr;
	this->value	  =	val;
	this->row		  =	r;
	this->column  =	cm;
  }
  /**
  *  Copy constructor
  *
  *  @param  cell    A Cell providing the values to build a new Cell from
  */
  Cell(const Cell &cell){
    this->coord     =   cell.coord;
    this->value     =   cell.value;
    this->row       =   cell.row;
    this->column    =   cell.column;
  }
  /*  Overloaded Operators    */
      /** Assignment      */
  Cell& operator= (const Cell &rhs){
    this->coord     =   rhs.coord;
    this->value     =   rhs.value;
    this->row       =   rhs.row;
    this->column    =   rhs.column;
    return *this;
  }
};
#endif	//	CELL_H
