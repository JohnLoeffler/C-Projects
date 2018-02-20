/**
 *     This source code was written by the Author on the stated
 *         date of creation. You may use this code for any
 *         non-Commercial purpose with credit given to the Author.
 *         For commercial use, contact the Author at the listed
 *         contact method.
 *
 *     CellGrid.h
 *         Date Created:    December 1, 2017
 *         Type:            Data Structure
 *         Description:     A structure for the 2D grid that the iRobot
 *							  Create will navigate			
 *         Dependencies:    CellQueue.h, <iomanpi>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */

#ifndef CELLGRID_H
#define CELLGRID_H

#include "CellQueue.h"
#include <iomanip>
class CellGrid{
  int       xSide, ySide, numCells;
  CellNode  **cells;
  CellQueue *cq;
public:
  /**
  *   Parameterized Constructor
  *
  *   @param  x Width of the grid
  *   @param  y Height of the grid
  */
  CellGrid(int x, int y, CellNode **c){
    this->setXSide(x);
    this->setYSide(y);
    this->setNumberOfCells(x*y);
    this->setCells(c);
    this->mapCellsNoWrap();
    this->setQueue(new CellQueue(x*y));
  }
  /**
  *   Destructor
  */
  ~CellGrid(){
    if(this->getCells() != nullptr){
        delete[] this->cells;
    }
  }
  /*  Mutators    */
  /**
  *   setXSide(int)
  *     Sets the width of the grid
  *   @param  x An int of the Width
  */
  const void   setXSide(int x)          {this->xSide  = x;        }
  /**
  *   setYSide(int)
  *     Sets the height of the grid
  *   @param  y An int of the Height
  */
  const void   setYSide(int y)          {this->ySide  = y;        }
  /**
  *   setNumberOfCells(int)
  *     Sets the current number of cells
  *   @param  num The Maximum number of cells currently in the grid
  */
  const void   setNumberOfCells(int num){this->numCells   = num;  }
  /**
  *   setCells(CellNode**)
  *     Sets the CellNode grid
  *   @param  cells An array of pointers to CellNodes
  */
  const void   setCells(CellNode** c)   {this->cells      = c;    }
  /**
  *   setQueue()
  *     Sets the Cell Queue of the grid
  *   @param  cq  A pointer to an allocated CellQueue
  */
  const void  setQueue(CellQueue *q)    {this->cq = q;            }
  /**
  *   setStack()
  *     Sets a new Cellnode stack for use by other grid functions
  *   @param  s A Pointer to an allocated CellStack
  */
  /*  Accessors   */
  /**
  *   getXSide()
  *     Gets the width of the grid
  *   @return An int of the width of the grid
  */
  int         getXSide              ()  {return this->  xSide;    }
  /**
  *   getYSide()
  *     Gets the height of the grid
  *   @return An int of the height of the grid
  */
  int         getYSide              ()  {return this->  ySide;    }
  /**
  *   getCurrentNumberOfCells()
  *     Returns the total number of used cell locations in the grid
  *   @return An int of the grid occupancy
  */
  int         getNumberOfCells      ()  {return this->numCells;   }
  /**
  *   getCells()
  *     Gets the array containing the CellNodes
  *   @return A pointer to an Array of CellNodes
  */
  CellNode**  getCells              ()  {return this->  cells;    }
  /*  Utility Methods  */
  /**
  *   mapCellsNoWrap()
  *     Connects the cells in the array without wrapping around the edges to
  *       the other side of the map
  */
  void        mapCellsNoWrap        ();
  /**
  *   findCellByID(int)
  *     Find the location of a specific cell in the map by cell id number
  *   @return A Pointer to a CellNode
  */
  CellNode*   findCellByID          (int id);
  /**
  *   findCellByCoordinates(Coordinates)
  *     Find the location of a specific cell using it's coordinate value
  *   @return A Pointer to a CellNode
  */
  CellNode*   findCellByCoordinates (Coordinates c);
  /**
  *   findPath()
  *     Produces a map of the area between one node to the other, s to e
  *   @param  s The Coordinates of the starting location
  *   @param  e The Coordinates of the ending location
  *   @param  A string containing the map of the grid
  */
  void findPath                     (Coordinates s, Coordinates e);
  /**
  *   plotPath()
  *     Produces the shortest path between the given starting point the end of a
  *       filled in map as a series of coordinates to navigate by
  *   @param  s The Coordinates of the starting location
  */
  void plotPath(CellNode* n, int val, int direction,
                  int &count, std::stringstream &ss);
/**
  *   printCells_Value()
  *     Produces a formatted, multi-lined string of all the cells in the
  *       CellGrid with all of the values contained within each node
  *   @return A formatted string
  */
  inline std::string printCells_Value(){
    std::stringstream ss;
    for(int i = 0; i< this->getNumberOfCells(); i++){
      ss << std::setw(3)<< cells[i]->cell.value;
      if(i%xSide == xSide-1)
        ss << "\n";
    }
    ss << "\n";
    return ss.str();
  }
  /**
  *   printCellMaps()
  *     Produces a sequence of different formatted maps of the CellGrid showing
  *       the values produced by the wavefront function, the locations of the
  *       waypoints the robot will use to reach the target, and the path and
  *       waypoints between the starting location and the target cell.
  *   @return A formatted string
  */
  std::string printCellMaps();
};
#endif // CELLGRID_H
