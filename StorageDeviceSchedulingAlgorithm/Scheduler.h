#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "SchedulingAlgorithm.h"

class Scheduler{
  /* Member Variables */
  /** Number of cylinders on the disc */
  int NumCylinders;
  /** Current position of the Disk Head */
  int CurrentPosition;
  /** Sequence of cylinder requests used to test the scheduling algorithms */
  std::vector<int> Sequence;
  /** Number of cylinders requests in the sequence */
  int Requests;
  /** Number of head movements performed for the current algorithm */
  int HeadMovements;
  /** An instance of the algorithm being tested */
  SchedulingAlgorithm* CurrentAlgorithm;

  /**
  * GenerateSequence()
  * Generates a psuedo random sequence of ints representing cylinder requests
  * @param int req Number of requests to generate
  * @return The number of requests entered into the sequence (for verification)
  */
  int GenerateSequence(int req);

  /**
  * CalculateTotalHeadMovements
  * Counts the total number of head movements required to process the Sequence
  *   as scheduled by the current algorithm
  */
  void CalculateTotalHeadMovements();

public:

  /** A pointer to the current Scheduling Algorithm being tested */
  Algorithm algorithm;

  /**
  * Constructor
  * @param int num The number of cylinders on the disc
  * @param int pos The initial position of the disc head
  *	@param int req The number of requests to generate in order to test an algorithm
  */
  Scheduler(int num, int pos, int req);
  /**
  * SortSequence
  * Sorts the Sequence vector according to the provided Scheduling Algorithm
  * @param Algorithm algo An enum of the Scheduling Algorithm being tested
  */
  void SortSequence(Algorithm _algorithm);
  /**
  * TestAlgorithm
  * Initiates test of the scheduling algorithm currently set in the Scheduler
  * @return A string object containing the formatted results of the test
  */
  std::string TestAlgorithm();

  /**
  * TestAlgorithmNoGraph
  * Initiates test of the scheduling algorithm currently set in the Scheduler
  *   without producing a graph of the algorithms operation
  * @return A string object containing the formatted results of the test
  */
  std::string TestAlgorithmNoGraph();
  /**
  * PrintHeader
  * Prints a formatted header for test output for the given Algorithm
  * @param Algorithm algo The enum for the Algorithm being tested
  * @return A string object containing the formatted header
  */
  std::string PrintHeader(Algorithm algo);
  /**
  * PrintChart
  * Produces a string object containing a chart of all head movements performed
  *   and the distance traveled per operation
  * @return A string object with the chart of the algorithms performance
  */
  std::string PrintChart();
  /**
  * PrintGraph
  * Produces a string object containing a proportional graph of all head
  *   movements performed
  * @return A string object with a graph of the algorithms performance
  */
  std::string PrintGraph();
};
#endif // SCHEDULER_H
