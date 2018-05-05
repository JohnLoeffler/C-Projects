#ifndef SCHEDULINGALGORITHM_H
#define SCHEDULINGALGORITHM_h
#include <iostream>
#include <vector>
/** Enum class with the name of each of the six scheduling algorithms */
enum class Algorithm{
  FCFS, SSTF, SCAN, CSCAN, LOOK, CLOOK
};

/** Abstract class interface for Scheduling Algorithm Strategy Design Pattern */
class SchedulingAlgorithm{
public:
  virtual bool Compare(int a = 0, int b = 0, int h = 0) = 0;
  virtual void Sort(std::vector<int>& sequence, int start);
  virtual int CalculateHeadMovement(std::vector<int> sequence, int start);
  virtual ~SchedulingAlgorithm(){}
};

/** First Come, First Serve implementation of the Scheduling Algorithm */
class FCFS : public SchedulingAlgorithm{
public:
  /** Implementation of the compare() function. Always returns true since the
  *     sequence is already set up in FCFS order
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The last cylinder the disc head visited
  * @return Always returns true
  */
  bool Compare(int a, int b, int h){
    return true;
  }
};

/** Shortest Seek Time First implementation of the Scheduling Algorithm */
class SSTF : public SchedulingAlgorithm{
public:
  /**
  * Compare
  * Implementation of the compare() function. Finds the smaller absolute value
  *   of the difference between the last visited cylinder, (h), and the current
  *   number in the Sequence, (a), or the next number in the sequence (b)
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The last cylinder the disc head visited
  * @return True if a has a shorter seek time than b, false otherwise
  */
  bool Compare(int a, int b, int h);

  /**
  * Sort
  * Implementation of the Sort function. Orders a vector of ints using the SSTF
  *   Compare funtion.
  * @param vector<int> sequence The sequence of numbers to sort
  * @param int start The number used as the sorting algorithm's starting point
  */
  void Sort(std::vector<int>& sequence, int start);
};

/** SCAN implementation of the Scheduling Algorithm */
class SCAN : public SchedulingAlgorithm{
public:
  /**
  * Compare
  * Compares a number against the next number in the sequence and reports
  *   whether they are in the proper order according to the SCAN algorithm,
  *   meaning whether the current number is larger than the next number and both
  *   are smaller than the initial head position h, or if the current number is
  *   smaller than the next number and both are larger than h, or that the
  *   current number is smaller than h and the next number is larger than h
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The initial starting disc head position
  * @return True if a and b are in the proper order, false otherwise
  */
  bool Compare(int a, int b, int h);

  /**
  * Sort
  * Implementation of the Sort function. Orders a vector of ints using the SCAN
  *   Compare funtion.
  * @param vector<int> sequence The sequence of numbers to sort
  * @param int start The number used as the sorting algorithm's starting point
  */
  //void Sort(std::vector<int>& sequence, int start);

  /**
  * CalculateHeadMovements
  * Calculates the total number of head movements needed to process the sequence
  * @param vector<int> sequence The ordered sequence of ints being processed
  * @param int start The number of the starting position of the sequence
  * @return int The number of head movements required to process all requests
  */
  int CalculateHeadMovement(std::vector<int> sequence, int start);
};

/** CSCAN implementation of the Scheduling Algorithm */
class CSCAN : public SchedulingAlgorithm{
public:
  /**
  * Compare
  * Compares a number against the next number in the sequence and reports
  *   whether they are in the proper order according to the CSCAN algorithm,
  *   meaning whether the current number is larger than the next number and both
  *   are smaller than the initial head position h, or if the current number is
  *   smaller than the next number and both are larger than h, or that the
  *   current number is smaller than h and the next number is larger than h
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The initial starting disc head position
  * @return True if a and b are in the proper order, false otherwise
  */
  bool Compare(int a, int b, int h);

  /**
  * Sort
  * Implementation of the Sort function. Orders a vector of ints using the CSCAN
  *   Compare funtion.
  * @param vector<int> sequence The sequence of numbers to sort
  * @param int start The number used as the sorting algorithm's starting point
  */
  void Sort(std::vector<int>& sequence, int start);

  /**
  * CalculateHeadMovements
  * Calculates the total number of head movements needed to process the sequence
  * @param vector<int> sequence The ordered sequence of ints being processed
  * @param int start The number of the starting position of the sequence
  * @return int The number of head movements required to process all requests
  */
  int CalculateHeadMovement(std::vector<int> sequence, int start);
};

/** LOOK implementation of the Scheduling Algorithm */
class LOOK : public SchedulingAlgorithm{
public:
  /**
  * Compare
  * Compares a number against the next number in the sequence and reports
  *   whether they are in the proper order according to the LOOK algorithm,
  *   meaning whether the current number is larger than the next number and both
  *   are smaller than the initial head position h, or if the current number is
  *   smaller than the next number and both are larger than h, or that the
  *   current number is smaller than h and the next number is larger than h
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The initial starting disc head position
  * @return True if a and b are in the proper order, false otherwise
  */
  bool Compare(int a, int b, int h);

  /**
  * Sort
  * Implementation of the Sort function. Orders a vector of ints using the LOOK
  *   Compare funtion.
  * @param vector<int> sequence The sequence of numbers to sort
  * @param int start The number used as the sorting algorithm's starting point
  */
  void Sort(std::vector<int>& sequence, int start);
  /**
  * CalculateHeadMovements
  * Calculates the total number of head movements needed to process the sequence
  * @param vector<int> sequence The ordered sequence of ints being processed
  * @param int start The number of the starting position of the sequence
  * @return int The number of head movements required to process all requests
  */
  int CalculateHeadMovement(std::vector<int> sequence, int start);
};

/** CLOOK implementation of the Scheduling Algorithm */
class CLOOK : public SchedulingAlgorithm{
public:
  /**
  * Compare
  * Compares a number against the next number in the sequence and reports
  *   whether they are in the proper order according to the CLOOK algorithm,
  *   meaning whether the current number is larger than the next number and both
  *   are smaller than the initial head position h, or if the current number is
  *   smaller than the next number and both are larger than h, or that the
  *   current number is smaller than h and the next number is larger than h
  * @param int a The number in the current position of the Sequence
  * @param int b The number in the next position of the Sequence
  * @param int h The initial starting disc head position
  * @return True if a and b are in the proper order, false otherwise
  */
  bool Compare(int a, int b, int h);

  /**
  * Sort
  * Implementation of the Sort function. Orders a vector of ints using the CLOOK
  *   Compare funtion.
  * @param vector<int> sequence The sequence of numbers to sort
  * @param int start The number used as the sorting algorithm's starting point
  */
  void Sort(std::vector<int> &sequence, int start);
  /**
  * CalculateHeadMovements
  * Calculates the total number of head movements needed to process the sequence
  * @param vector<int> sequence The ordered sequence of ints being processed
  * @param int start The number of the starting position of the sequence
  * @return int The number of head movements required to process all requests
  */
  int CalculateHeadMovement(std::vector<int> sequence, int start);
};

#endif // SCHEDULINGALGORITHM_H
