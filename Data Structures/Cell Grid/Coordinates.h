/**
 *     	This source code was written by the Author on the stated
 *      	date of creation. You may use this code for any
 *       	non-Commercial purpose with credit given to the Author.
 *       	For commercial use, contact the Author at the listed
 *     		contact method.
 *
 *     	Coordinates.h
 *         Date Created:    December 1, 2017
 *         Type:            Data Structure
 *         Description:     Simple structure for holding 2d coordinates
 *         Dependencies:    <string>
 *         @version         1.0
 *         @author          John Loeffler
 *         Email:           John.Loeffler@gmail.com
 *         Twitter:         @ThisDotJohn
 *         LinkedIn:        linkedin.com/in/johnloeffler
 *         Github:          github.com/JohnLoeffler
 */
#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
struct	Coordinates{
  float	x;
  float	y;
  /*		Constructors		*/
	/**			Default		  */
  Coordinates(){}
	/**		Parameterized	  */
  Coordinates(float _x, float _y){
    x = _x;
	y = _y;
  }
	/**		Copy 		*/
  Coordinates(const Coordinates &cr){
	this->x	=	cr.x;
	this->y	=	cr.y;
  }
  /*	    Utility Methods		*/
  inline std::string   printCoordinates(){
    std::stringstream ss;
    ss << this->x << " " << this->y;
    return (ss.str());
  }
  /*	Overloaded Operators	*/
		/**	Assignment 	*/
  inline Coordinates operator=(const Coordinates &rhs){
	this->x	=	rhs.x;
	this->y	=	rhs.y;
	return (*this);
  }
  inline bool  operator==(const Coordinates &rhs){
    return  (this->x == rhs.x && this->y == rhs.y);
  }
};

#endif	//	COORDINATES_H
