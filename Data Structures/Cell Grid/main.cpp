/**
 *     This source code was written by the Author on the stated
 *         date of creation. You may use this code for any
 *         non-Commercial purpose with credit given to the Author.
 *         For commercial use, contact the Author at the listed
 *         contact method.
 *
 *     main.cpp
 *         Date Created:    December 1, 2017
 *         Type:            A main function used to generate a map for a robot to navigate
 *         Description:     Program Main
 *         Dependencies:    CellGrid.h, CellQueue.h, <string>,<fstream>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#include "CellQueue.h"
#include "CellGrid.h"

#include <string>
#include <fstream>

/*  FUNCTION PROTOTYPES */
inline void printGrid(int **arr, const int ySide, const int xSide);
inline void processMap(int **map, int **plot, const int ySide, const int xSide);
inline void addBuffer(int **map, int **plot, const int ySide, const int xSide);
inline void readInMap(std::ifstream& in,int **map,
                      const int ySide, const int xSide);
inline void makeCells(Coordinates &coord, CellNode** cells,
                        int &id, int &r, int &c, Cell &tmp,
                        const int ySide, const int xSide);
inline void printCells(std::ofstream& out, CellNode **cells, CellNode *start,
                       const int ySide, const int xSide);
inline int rowColToInd(int row, int column, const int ySide);
inline void setCellValues(int **plot, CellNode **cells,
                          const int ySide, const int xSide);
inline void readMapDimensions(std::ifstream& in, float& sx, float& sy,
                              float& ex, float& ey, int& xSide, int& ySide);

int main()
{
  std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  std::cout.precision(1);
  int   **map, **plot, xSide, ySide;
  float sx, sy, ex, ey;
  std::ifstream  in    ("map.txt");
    //  READ IN MAP PARAMETERS  //
  readMapDimensions(in, sx, sy, ex, ey, xSide, ySide);
  map = new int*[ySide];  //
  plot= new int*[xSide];
  for(int i = 0; i < ySide; i++){
    map[i]  = new int[xSide];
  }

    //  READ MAP
  readInMap(in, map, ySide, xSide);
  in.close();
    //  CREATE PARALLEL ARRAY TO CREATE BUFFERS AROUND OBSTACLES FOR BETTER
    //    ROBOT NAVIGATION
  for(int i = 0; i < ySide; i++){
    plot[i]  = new int[xSide];
  }
  processMap(map, plot, ySide, xSide);

    //  CREATE THE CELLS THAT WILL MAKE UP THE GRIB FOR THE ROBOT TO NAVIGATE
  Coordinates starting (sx,sy), ending(ex,ey);
  CellNode **cells = new CellNode*[ySide*xSide];
  Coordinates coord;
  int id = 0, row = 0, column = 0;
  Cell cell;
  makeCells(coord, cells, id, row, column, cell, ySide, xSide);
  setCellValues(plot, cells, ySide, xSide);

    //  CREATE THE ACTUAL GRID  //
  CellGrid cg(xSide, ySide, cells);

    //  FIND THE PATH FOR THE ROBOT TO NAVIGATE, PRINT DATA TO FILE, AND EXIT
  cg.findPath(starting, ending);
  return 0;
}
/*
*   setCellValues()
*     Sets the cell values with data from the plots array
*   @param  plot  An array of ints with detailed data about the area to navigate
*   @param  cells An interconnected array of nodes to navigate
*   @param  ySide An int with how many rows are in the grid
*   @param  xSide An int with how many columns are in the grid.
*/
inline void setCellValues(int **plot, CellNode **cells, const int ySide, const int xSide){
  for(int i = 0; i < ySide; i++){
    for(int j = 0; j < xSide; j++){
      cells[rowColToInd(i,j,ySide)]->cell.value = plot[i][j];
    }
  }
}
/*
*   rowColToInd
*     Converts a row and column pair to it's index equivalent
*   @param  row     An int of the row of the node
*   @param  column  An int of the column of the node
*   @param  ySide   An int of the nomber of rows in the grid
*/
inline int rowColToInd(int row, int column, const int ySide){
  return ((row*ySide)+column);
}
/*
*   makeCells()
*     Populates the cells array with new cells generated from data read in from
*       the provided map
*   @param  coord   An address of a Coordinates variable
*   @param  cells   A pointer to an array of CellNodes
*   @param  id      An address of an int variable
*   @param  r       An address of an int variable
*   @param  c       An address of an int variable
*   @param  cell    An address of a cell variable
*   @param  ySide   A const int of the number of rows to build
*   @param  xSide   A const int of the number of columns to build
*
*
*
*/
inline void makeCells(Coordinates &coord, CellNode** cells,
               int &id, int &r, int &c, Cell &tmp, const int ySide, const int xSide){
  for(float i = ((float)ySide/4); i > -((float)ySide/4); i -= 0.5 ){
    for(float j = -((float)xSide/4); j < ((float)xSide/4); j += 0.5){
      coord.x = j; coord.y = i;
      tmp.coord = coord;
      tmp.column = c;
      tmp.row = r;
      tmp.value = -1;
      cells[id] = new CellNode(tmp, id);
      id++;
      c++;
      r++;
    }
  }
}
/*
*   readMapDimensions()
*     Reads in map dimensions from the map file
*   @param  in    An ifstream of the map file
*   @param  sx    A float of the starting X coordinate
*   @param  sy    A float of the starting Y coordinate
*   @param  ex    A float of the ending X coordinate
*   @param  ey    A float of the ending Y coordinate
*   @param  xSide An int of the width of the grid map
*   @param  ySide An int of the height of the grid map
*/
inline void readMapDimensions(std::ifstream& in, float& sx, float& sy,float& ex,
                              float& ey, int& xSide, int& ySide){
  in >> xSide >> ySide >> sx >> sy >> ex >> ey;
  return;
}
/*
*   readInMap()
*     Reads in the map data from the map file
*   @param  in    An ifstream of the map file
*   @param  map   A pointer to an array of ints
*   @param  ySide A constant int of the number of rows
*   @param  xSide A constant int of the number of columns
*/
inline void readInMap(std::ifstream &in, int **map,
                      const int ySide, const int xSide){
  for(int i = 0; i< ySide; i++){
    for(int j = 0; j < xSide; j++){
      in >> map[i][j];
    }
  }
}
/*
*   processMap()
*     Processes the map after it's been read in and assign values to plot array
*       based on values read from the map file
*   @param  map   The map of the area
*   @param  plot  The array that will hold the processed map data
*   @param  ySide A const int of the number of rows in the plot map
*   @param  xSide A const int of the number of columns in the plot map
*/
inline void processMap(int **map, int **plot, const int ySide, const int xSide){
  for(int i = 0; i< ySide; i++)
    for(int j = 0; j < xSide; j++){
      if(map[i][j] == 1)
        plot[i][j] = -3;
      else
        plot[i][j] = -1;
    }
    addBuffer(map, plot, ySide, xSide);
}
/*
*   addBuffer()
*     Analyzes the map data and surrounds obstructions with a one cell buffer to
*       prevent the robot from accidentally collisions
*   @param  map   The map of the area
*   @param  plot  The array that will hold the processed map data
*   @param  ySide A const int of the number of rows in the plot map
*   @param  xSide A const int of the number of columns in the plot map
*/
inline void addBuffer(int **map, int **plot, const int ySide, const int xSide){
  for ( int i = 0; i < ySide; i++ ){
    for ( int j = 0; j < xSide; j++ ){
      if(i > 0 && i < ySide-1){
        if(j > 0 && j < xSide - 1){
          if(plot[i][j] == -3){
            if(plot[i-1][j] != -3)  //  i is the trailing pointer n->up
              plot[i-1][j] = -2;
            if(plot[i+1][j] != -3)  //  j is the trailing pointer n->down
              plot[i+1][j] = -2;
            if(plot[i][j-1] != -3)  //  j is the trailing pointer n->left
              plot[i][j-1] = -2;
            if(plot[i][j+1] != -3)  //  i is the trailing pointer n->right
              plot[i][j+1] = -2;
          }
            //<!-------------------------------->
          if(plot[i][j] == -1)
            if((plot[i-1][j] || plot[i+1][j] == -2) &&
               (plot[i][j-1] == -2 || plot[i][j+1] == -2)
               && ((plot[i-1][j-1]) == -3 || (plot[i-1][j+1]) == -3
                   || (plot[i+1][j-1]) == -3 || (plot[i+1][j+1]) == -3 ))
              plot[i][j] = -2;
          }
        }
      }
    }

}
