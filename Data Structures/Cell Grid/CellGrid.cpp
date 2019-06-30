/**
 *     CellGrid.cpp
 *         Date Created:    December 1, 2017
 *         Type:            Implementation file
 *         Description:     Defines non-trivial functions for CellGrid.h
 *         Dependencies:    CellGrid.h, <iostream>, <fstream>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#include "CellGrid.h"
#include <iostream>
#include <fstream>
/*
*  Loops through an array of CellNodes and checks the node against nine
*     specific conditions, then links the node to adjacent nodes accordingly.
*     It does not wrap the edges of the map to its opposite side and instead
*     assigns a nullptr to directional pointers that point beyond the map.
*/
void  CellGrid::mapCellsNoWrap  (){
  for(int i = 0; i< this->getNumberOfCells(); i++){
    if(i == 0){ //  TOP LEFT
      this->cells[i]->up = nullptr;
      this->cells[i]->left = nullptr;
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = cells[i+this->getYSide()];
    }else if(i == this->getYSide()-1){  //  TOP RIGHT
      this->cells[i]->up = nullptr;
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = nullptr;
      this->cells[i]->down = cells[i+this->getYSide()];
    }else if(i == this->getNumberOfCells() - this->getXSide()){  //  BOTTOM LEFT
      this->cells[i]->up = cells[i - this->getYSide()];
      this->cells[i]->left = nullptr;
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = nullptr;
    }else if(i == this->getNumberOfCells() - 1){ //  BOTTOM RIGHT
      this->cells[i]->up = cells[i - this->getYSide()];
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = nullptr;
      this->cells[i]->down = nullptr;
    }else if(i % this->getXSide() == 0){  //  LEFT EDGE
      this->cells[i]->up = cells[i - this->getYSide()];
      this->cells[i]->left = nullptr;
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = cells[i + this->getYSide() ];
    }else if(i % this->getXSide() == this->getXSide()-1){ //  RIGHT EDGE
      this->cells[i]->up = cells[i - this->getYSide()];
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = nullptr;
      this->cells[i]->down = cells[i + this->getYSide()];
    }else if(i < this->getXSide()){ //  TOP EDGE
      this->cells[i]->up = nullptr;
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = cells[i + this->getYSide()];
    }else if(i >= (this->getNumberOfCells() - this->getXSide())){ // BOTTOM EDGE
      this->cells[i]->up = cells[i - this->getYSide()];
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = nullptr;
    }else{  //  MIDDLE CELLS
      this->cells[i]->up = cells[i - this->getXSide()];
      this->cells[i]->left = cells[i-1];
      this->cells[i]->right = cells[i+1];
      this->cells[i]->down = cells[i + this->getXSide()];
    }
  }
}
/*      findCellByID()      */
CellNode*   CellGrid::findCellByID        (int id){
  return this->getCells()[id];
}
/*    findCellByRowColumn
CellNode*   CellGrid::findCellByRowColumn (int r, int c){
  return this->getCells()[((r*this->getXSide())+(c))];
}*/
/*    findCellByCoordinates */
CellNode*   CellGrid::findCellByCoordinates(Coordinates c){
  for(int i = 0; i<this->getNumberOfCells(); i++){
    if(this->getCells()[i]->cell.coord == c){
      return this->getCells()[i];
    }else{
      continue;
    }
  }
  return nullptr;
}
/*    printCellMaps()   */
std::string CellGrid::printCellMaps(){
  std::stringstream sw, sd, sp, sc;
  sd  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  sd  <<  std::setw(32) << std::left <<"|" <<"Wavefront Map"<<std::setw(36) <<
        std::right <<"|\n";
  sd  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  sd  <<  printCells_Value();
  sd  << "\n"  <<  "-------------------------------------"
      << "-------------------------------------------\n\n";

  sw  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  sw  <<  std::setw(33) <<std::left <<"|" <<"Waypoint Map"<<std::setw(36) <<
        std::right  <<"|\n";
  sw  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  for(int i = 0; i< this->getNumberOfCells(); i++){
    if(cells[i]->waypoint){
      sw << std::setw(3)<< " W ";
    }else if(cells[i]->cell.value == -2){
      sw << std::setw(3) << " - ";
    }else if(cells[i]->cell.value == -3){
      sw << std::setw(3) << " 1 ";
    }else{
      sw << std::setw(3)<< "";
    }
    if(i%xSide == xSide-1)
      sw << "\n";
  }
  sp << "\n"  <<  "-------------------------------------"
      << "-------------------------------------------\n\n";

  sp  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  sp  <<  std::setw(35) <<std::left <<"|" <<"Path Map"<<std::setw(38) <<
        std::right  <<"|\n";
  sp  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  for(int i = 0; i< this->getNumberOfCells(); i++){
    if(cells[i]->waypoint && cells[i]->onPath){
      sp <<  std::setw(2) << "W ";
    }else if(cells[i]->onPath){
      sp << std::setw(2)<< "+ ";
    }else{
      sp << std::setw(2)<< ". ";
    }
    if(i%xSide == xSide-1)
      sp << "\n";
  }
  sp << "\n";
  sp  <<  "-------------------------------------"
        << "-------------------------------------------\n";
  sc << sd.str() << sw.str() << sp.str();

  return sc.str();
}
/**
*   findPath()
*     A four part function that takes an unprocessed grid of CellNodes and
*     finds a path from a given start node to a given end node. First, it finds
*     the starting and ending nodes from the given pair of Coordinate objects
*     and marks the ending node. Second, it passes the nodes to
*     processWavefront() and if true is returned, proceeds to third step where
*     it calls plotPath(). If false is returned, reports that no path can be
*     found and returns. Fourth, after calling plotPath(),takes the stringstream
*     that was passed to the function and merges it with a second containing the
*     number of values the function fed into the returned stringstream which is
*     printed to the appropriate files.
*/
void CellGrid::findPath(Coordinates s, Coordinates e){
  std::stringstream sa, sb; //  STREAMS USED TO ASSEMBLE STRING OF COORDINATES
  findCellByCoordinates(e)->cell.value = 0; //  SETS END CELL TO SENTINEL VALUE
  if(this->cq->processWavefront(findCellByCoordinates(e),
                                findCellByCoordinates(s))){
    std::ofstream  plot("plan.txt");
    std::ofstream  maps("maps.txt");
    this->cq->emptyQueue(); //  CLEAR THE QUEUE OF EXTRANEOUS NODES
    int direction = 0, value = this->getNumberOfCells(),count = 0;
    //  PLOTS THE PATH FROM START TO FINISH //
    plotPath(findCellByCoordinates(s), value, direction, count, sa);

    sb  <<  (count * 2) << " "; //  ADD COUNT OF NAVIGATION VALUES TO STREAM
    sb  << sa.str();  //  COMBINE THE STREAMS (YES, WE MUST CROSS THE STREAMS!)
    plot << sb.str(); //  PRINTS COORDINATE PLAN FOR ROBOT NAVIGATION
    plot.close();
    maps << printCellMaps(); //  SEND MAPS TO FILE
    maps.close();
  }
}
/**
*   plotPath()
*     A four part recursive function used to navigate and extract waypoints from
*       a processed CellGrid. First, the function marks the given node as being
*       on the desired path and checks if the node is the target node. If yes,
*       marks it as the final waypoint, extracts the coordinates to a
*       stringstream and returns. If not, proceeds to Second where it checks
*       the eight cells around the given cell for the lowest navigable value.
*       Third, it checks for whether the direction of the lowest value is the
*       direction it is already moving in. If not, marks the node as a waypoint
*       and extracts the coordinates to the stringstream. Fourth, moves to the
*       next accessible node with the lowest value.
*/
void CellGrid::plotPath(CellNode* n,int val,int direction,
                        int &count,std::stringstream &sa){
  n->onPath = true;
  if(n->cell.value == 0){           //  REACHED THE TARGET CELL
    n->waypoint = true;
    count++;  //  INCREMENT TO FINAL NODE
    sa << n->cell.coord.printCoordinates() << "\n"; //
    return; //  END THE RECURSIVE LOOP
  }
  int   nDirection  = 0;  //  INITIALIZE THE DIRECTION TO TEST AS UP-LEFT
  if(n->up->left != nullptr   //  NODE TO CHECK IS NOT A NULL POINTER
      && n->up->left->cell.value < val    // CHECK THAT THE VALUE IS LESS THAN
        && n->up->left->cell.value  >= 0  // CURRENT CELL AND IS NO LESS THAN 0
            //  AND CHECK THAT THE CELLS ON EITHER SIDE ARE NOT BUFFER CELLS
            //    TO PREVENT THE ROBOT FROM GETTING HUNG UP ON A OBSTACLE CORNER
          && !(n->up->cell.value == -2 || n->left->cell.value == -2)){
    val = n->up->left->cell.value;  //  ASSIGN ITS VALUE TO COMPARE VARIABLE
    nDirection = 0;   //  SET TEMP DIRECTION TO UP-LEFT
  }
  if(n->up != nullptr && n->up->cell.value < val && n->up->cell.value >= 0){
    val = n->up->cell.value;
    nDirection = 1; //  SET TEMP DIRECTION TO UP
  }
  if(n->up->right != nullptr&& n->up->right->cell.value < val
      && n->up->right->cell.value >= 0 && !(n->up->cell.value == -2
                                              || n->right->cell.value == -2)){
    val = n->up->right->cell.value;
    nDirection = 2; //  SET TEMP DIRECTION TO UP-RIGHT
  }
  if(n->left != nullptr&& n->left->cell.value < val&& n->left->cell.value >= 0){
    val = n->left->cell.value;
    nDirection = 3; //  SET TEMP DIRECTION TO LEFT
  }
  if(n->right!=nullptr&& n->right->cell.value < val&& n->right->cell.value>= 0){
    val = n->right->cell.value;
    nDirection = 4; //  SET TEMP DIRECTION TO RIGHT
  }
  if(n->down->left!= nullptr && n->down->left->cell.value < val
        && n->down->left->cell.value >= 0 && !(n->left->cell.value == -2
                                                || n->down->cell.value == -2)){
    val = n->down->left->cell.value;
    nDirection = 5; //  SET TEMP DIRECTION TO DOWN-LEFT
  }
  if(n->down!=nullptr && n->down->cell.value < val && n->down->cell.value >= 0){
    val = n->down->cell.value;
    nDirection = 6; //  SET TEMP DIRECTION TO DOWN
  }
  if(n->down->right != nullptr && n->down->right->cell.value < val
      && n->down->right->cell.value >= 0 && !(n->down->cell.value == -2
                                              || n->right->cell.value == -2)){
    val = n->down->right->cell.value;
    nDirection = 7; //  SET TEMP DIRECTION TO DOWN RIGHT
  }
  if(nDirection != direction){  //  CURRENT DIRECTION VALUE SAME AS LOWEST?
    count++;  //  ADD TO NUMBER OF NODES TO PRINT OUT
    sa << n->cell.coord.printCoordinates() << " ";  //  ADD TO STREAM
    n->waypoint = true;
  }
  switch(nDirection){  //  DIRECTION OF LOWEST VALUE
    case 0: //  IF DIRECTION IS UP-LEFT
      return plotPath(n->up->left, val, nDirection, count, sa);
    case 1: //  IF DIRECTION IS UP
      return plotPath(n->up, val, nDirection, count, sa);
    case 2: //  IF DIRECTION IS UP-RIGHT
      return plotPath(n->up->right,  val, nDirection, count, sa);
    case 3: //  IF DIRECTION IS LEFT
      return plotPath(n->left, val, nDirection, count, sa);
    case 4: //  IF DIRECTION IS RIGHT
      return plotPath(n->right, val, nDirection, count, sa);
    case 5: //  IF DIRECTION IS DOWN-LEFT
      return plotPath(n->down->left, val, nDirection, count, sa);
    case 6: //  IF DIRECTION IS DOWN
      return plotPath(n->down, val, nDirection, count, sa);
    case 7: //  IF DIRECTION IS DOWN-RIGHT
      return plotPath(n->down->right, val, nDirection, count, sa);
    default:
      return;
  }
}
