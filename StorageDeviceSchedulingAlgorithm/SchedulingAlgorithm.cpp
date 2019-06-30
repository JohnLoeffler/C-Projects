#include "SchedulingAlgorithm.h"
#include <iostream>
#include <cmath>

/* Basic swap function for ints */
void swap(int& a, int& b){
  b = a + b;
  a = b - a;
  b = b - a;
}

void SchedulingAlgorithm::Sort(std::vector<int>& Sequence, int start){
  bool isSwapped = true;
  int sorted = 0, pass = 0;
  while (isSwapped){
    pass++;
    isSwapped = false;
    for(auto itr = Sequence.begin(); itr != Sequence.end()-1; ++itr){
      if (!this->Compare(*itr , *(itr+1), start)){
        swap(*itr, *(itr+1));
        isSwapped = true;
      }
    }
  }
}

int SchedulingAlgorithm::CalculateHeadMovement(std::vector<int> sequence, int start){
  int count = 0;
  for(auto itr = sequence.begin(); itr != sequence.end()-1; ++itr){
    count += abs(*itr - *(itr+1));
  }
  return count;
}

/* Returns the lowest of the distance from current head position h and a or b */
bool SSTF::Compare(int a, int b, int h){
  return (abs(a-h) < abs(b-h));
}
/*
* Standard Sorting function, except that the new position of the disc head after
*   each movement must be tracked in real time for the sort to work properly
*/
void SSTF::Sort(std::vector<int> &Sequence, int start){
  bool isSwapped = true;
  int sorted = 0;
  int lastVisited = start;
  while (isSwapped){
    isSwapped = false;
    sorted++;
    for (int i = 0; i < Sequence.size() - sorted; i++){
      if (!this->Compare(Sequence[i] , Sequence[i+1], lastVisited)){
        swap(Sequence[i], Sequence[i+1]);
        isSwapped = true;
      }
      lastVisited = Sequence[i];
    }
  }
}

/*
* This implementation is identical to LOOK implementation and also the basis for
*   modified implementations in CSCAN/CLOOK. Orders numbers as follows:
*   [N][N-1][N-2]...[N-(N-1)][0][N+1][N+2]...[SEQUENCE.END()-1][SEQUENCE.END()]
*/
bool SCAN::Compare(int a, int b, int h){
  //  IF current number is less than or equal to initial position
  if(a <= h){
    //  IF next number is less than or equal to initial position
    if(b <= h){
      //  IF next number is less than or equal to current number
      if( b <= a){
        //  numbers are in proper order, return true
        return true;
      //  ELSE next number is greater than current number
      }else{
        //  numbers are not in proper order, return false
        return false;
      }
    //  ELSE next number is greater than initial position
    }else{
      //  May or may not be properly ordered, but cannot tell this pass, so
      //    treat them as if properly ordered for now, return true
      return true;
    }
  //  ELSE current number is greater than initial position
  }else{
    //  IF next number is less than initial position
    if(b <= h){
      //  numbers are not properly ordered, return false
      return false;
    //  ELSE next number is greater than initial position
    }else{
      //  IF next number is greater than or equal to current number
      if( b >= a){
        //  numbers are properly ordered, return true
        return true;
      //  ELSE next number is less than current number
      }else{
        //  numbers aren't properly ordered, return false;1
        return false;
      }
    }
  }
}
/*
* ONLY DIFFERENCE BETWEEN SCAN/CSCAN AND LOOK/CLOOK IMPLEMENTATIONS OF
*   CALCULATEHEADMOVEMENT IS THAT SCAN/CSCAN FACTOR IN THE MOVEMENT TO ZERO AND
*   FROM LAST REQUEST AND THE LAST CYLINDER ON THE DISC INTO THEIR COUNT.
*   OTHERWISE, THE IMPLEMENTATIONS ARE NEARLY IDENTICAL
*/
int SCAN::CalculateHeadMovement(std::vector<int> sequence, int MaxCylinderNum){
  /*  DIF(INT M, INT N) DEFINED AS 'abs(m-n)', WHERE N != ZERO||SEQUENCE.END  */
  //  DECLARE MOVEMENTCOUNTER AND SET EQUAL TO ZERO
  int counter = 0, Dif = 0;
  bool reachedZero = false;
  //  FOR EACH NUMBER 'n' IN SEQUENCE
  for(auto itr = sequence.begin(); itr != sequence.end()-1; ++itr){
    //  IF 'n' IS LESS THAN 'n+1'
    if(*itr < *(itr+1) && !reachedZero){  /*REACHED THE LOWEST SCHEDULED VALUE*/
        //  ADD 'n','(n+1)*' TO COVER DISTANCE TO ZERO, THEN TO 'n+1'
      counter += *itr;
      ++itr;
      counter += *itr;
      reachedZero = true;
    }
    //  ADD DIF(N, N-1) TO MOVEMENTCOUNTER
    Dif = abs(*itr - *(itr+1));
    counter += Dif;
  }
  //  ADD DIF(MAX_CYLINDER_NUMBER, SEQUENCE.END)
  counter += (MaxCylinderNum - sequence.back());
  return counter;
}
/*
* ONLY DIFFERENCE BETWEEN THIS AND SCAN IMPLEMENTATION IS WHEN A ND B ARE BOTH
*   BIGGER THAN H, FOR CSCAN THE ORDER IS CORRECT IF A IS BIGGER THAN OR EQUAL
*   TO B, WHERE AS SCAN HAS THE OPPOSITE. ORDERS NUMBERS AS FOLLOWS:
*   [N][N-1][N-2]...[N-(N-1)][0][SEQUENCE.END()][SEQUENCE.END()-1]...[N+2][N+1]
*/
bool CSCAN::Compare(int a, int b, int h){
  if(a <= h){
    if(b <= h){
      if( b <= a){
        return true;
      }else{
        return false;
      }
    }else{
      return true;
    }
  }else{
    if(b <= h){
      return false;
    }else{
      if( b <= a){
        return true;
      }else{
        return false;
      }
    }
  }
}
/* Standard Sorting function */
void CSCAN::Sort(std::vector<int> &Sequence, int start){
  bool isSwapped = true;
  while (isSwapped){
    isSwapped = false;
    for(auto itr = Sequence.begin(); itr != Sequence.end()-1; ++itr){
      if (!this->Compare(*itr , *(itr+1), start)){
        swap(*itr, *(itr+1));
        isSwapped = true;
      }
    }
  }
}
/* Same as for SCAN */
int CSCAN::CalculateHeadMovement(std::vector<int> sequence, int MaxNumCylinder){
  /*  DIF(INT M, INT N) DEFINED AS 'abs(m-n)', WHERE N != ZERO||SEQUENCE.END  */
  //  DECLARE MOVEMENTCOUNTER AND SET EQUAL TO ZERO
  int counter = 0, Dif = 0;
  //  WHILE 'n' IS LESS THAN SEQUENCE SIZE)
  bool reachedZero = false;
  for(auto itr = sequence.begin(); itr != sequence.end()-1; ++itr){
    //  IF 'n' IS LESS THAN 'n+1'
    if(*itr < *(itr+1) && !reachedZero){  /*REACHED THE LOWEST SCHEDULED VALUE*/
        //  ADD DIF('n','((n+1)*-1)') TO COVER DISTANCE TO ZERO, THEN TO 'n+1'
      counter += *itr;
      ++itr;
      counter += *itr;
      reachedZero = true;
    }
    //  ADD DIF(N, N-1) TO MOVEMENTCOUNTER
    Dif = abs(*itr - *(itr+1));
    counter += Dif;
  }
  //  ADD DIF(MAX_CYLINDER_NUMBER, SEQUENCE.END)
  counter += (MaxNumCylinder - sequence.back());
  return counter;
}
/*
* Identical to SCAN Algorithm, the difference is not in the comparison or the
*   sorting, but in how movements are counted after sequence has been sorted at
*   the low and high ends of the sequence range
*/
bool LOOK::Compare(int a, int b, int h){
  if(a <= h){
    if(b <= h){
      if( b <= a){
        return true;
      }else{
        return false;
      }
    }else{
      return true;
    }
  }else{
    if(b <= h){
      return false;
    }else{
      if( b > a){
        return true;
      }else{
        return false;
      }
    }
  }
}
/* Standard sorting algorithm */
void LOOK::Sort(std::vector<int> &Sequence, int start){
  bool isSwapped = true;
  int sorted = 0;
  while (isSwapped){
    isSwapped = false;
    sorted++;
	  for (int i = 0; i < Sequence.size() - sorted; i++){
      if (!this->Compare(Sequence[i] , Sequence[i+1], start)){
        swap(Sequence[i], Sequence[i+1]);
        isSwapped = true;
      }
    }
  }
}
/*
* Only difference between this and SCAN is that LOOK does not count the movement
*   from lowest value to zero or highest value to the final cylinder
*/
int LOOK::CalculateHeadMovement(std::vector<int> sequence, int start){
  /*  DIF(INT M, INT N) DEFINED AS 'abs(m-n)', WHERE N != ZERO||SEQUENCE.END  */
  //  DECLARE MOVEMENTCOUNTER AND SET EQUAL TO ZERO
  int counter = 0, Dif = 0;
  //  WHILE 'n' IS LESS THAN SEQUENCE SIZE)
  for(auto itr = sequence.begin(); itr != sequence.end()-1; ++itr){
    //  ADD DIF(N, N-1) TO MOVEMENTCOUNTER
    Dif = abs(*itr - *(itr+1));
    counter += Dif;
  }
  return counter;
}
/* Identical to CSCAN algorithm */
bool CLOOK::Compare(int a, int b, int h){
  if(a <= h){
    if(b <= h){
      if( b <= a){
        return true;
      }else{
        return false;
      }
    }else{
      return true;
    }
  }else{
    if(b <= h){
      return false;
    }else{
      if( b <= a){
        return true;
      }else{
        return false;
      }
    }
  }
}
/* Standard sorting function */
void CLOOK::Sort(std::vector<int> &Sequence, int start){
  bool isSwapped = true;
  int sorted = 0;
  while (isSwapped)
	{
    isSwapped = false;
    sorted++;
	  for (int i = 0; i < Sequence.size() - sorted; i++){
      if (!this->Compare(Sequence[i] , Sequence[i+1], start)){
        swap(Sequence[i], Sequence[i+1]);
        isSwapped = true;
      }
    }
  }
}
/*
* Only difference between this and CSCAN is that CLOOK does not count the
*   movement from lowest value to zero or highest value to the final cylinder
*/
int CLOOK::CalculateHeadMovement(std::vector<int> sequence, int start){
  /*  DIF(INT M, INT N) DEFINED AS 'abs(m-n)', WHERE N != ZERO||SEQUENCE.END  */
  //  DECLARE MOVEMENTCOUNTER AND SET EQUAL TO ZERO
  int counter = 0, Dif = 0;
  //  WHILE 'n' IS LESS THAN SEQUENCE SIZE)
  for(auto itr = sequence.begin(); itr != sequence.end()-1; ++itr){
    //  ADD DIF(N, N-1) TO MOVEMENTCOUNTER
    Dif = abs(*itr - *(itr+1));
    counter += Dif;
  }
  return counter;
}
