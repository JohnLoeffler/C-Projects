#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <sstream>
#include "Scheduler.h"
#include "Timer.h"  /* For Random Number Generator seed */

#define RATIO (NumCylinders/80 +1)
#define SINGLELINE "--------------------------------------------------"
#define DOUBLELINE "=================================================="

/* Constructor */
Scheduler::Scheduler(int num, int pos, int req){
  this->NumCylinders    = num;
  this->CurrentPosition = pos;
  this->HeadMovements   = 0;
  this->Sequence.push_back(pos);
  this->Requests = this->GenerateSequence(req);
  if(Requests   != Sequence.size()){ // Checks that sequence is initialized
    std::cerr << "Error generating sequence of requests." << std::endl;
    exit(1);
  }
}
/* Generates a random sequence of cylinder requests */
int Scheduler::GenerateSequence(int req){
  Timer Time; //  Used to seed generator with system time since epoch
  std::default_random_engine Generator(Time.GetStartTime());
  // Increase randomness by discarding first 500 values generated
  for(int i = 0; i < 500; i++){
    Generator();
  }
  for(int i = 0; i < req; i++){
    this->Sequence.push_back(Generator()%this->NumCylinders);
  }
  //  Return the size of the sequence to verify that sequence generated properly
  return Sequence.size();
}
/* Sorts the sequence based on its currently assigned algorithm */
void Scheduler::SortSequence(Algorithm _algorithm){
  switch(_algorithm){
    case Algorithm::SSTF:
      CurrentAlgorithm = new SSTF();
      break;
    case Algorithm::SCAN:
      CurrentAlgorithm = new SCAN();
      break;
    case Algorithm::CSCAN:
      CurrentAlgorithm = new CSCAN();
      break;
    case Algorithm::LOOK:
      CurrentAlgorithm = new LOOK();
      break;
    case Algorithm::CLOOK:
      CurrentAlgorithm = new CLOOK();
      break;
    case Algorithm::FCFS:
    default:
      CurrentAlgorithm = new FCFS();
      break;
  }
  this->algorithm = _algorithm; /* CACHE THE TYPE OF ALGORITHM USED */
  CurrentAlgorithm->Sort(Sequence, CurrentPosition);  /* SORT SEQUENCE */
}

/* Calculates the number of movements needed to process sequence of requests */
void Scheduler::CalculateTotalHeadMovements(){
  this->HeadMovements =
    CurrentAlgorithm->CalculateHeadMovement(Sequence, NumCylinders);
}
/*
* Tests the assigned algorithm against the sequence of number and prints a graph
*   of the operations as well as the total number of movements required to
*   process the requests
*/
std::string Scheduler::TestAlgorithm(){
  std::stringstream ss;
  ss  << std::endl << DOUBLELINE << std::endl;
  CalculateTotalHeadMovements();
  ss << PrintHeader(this->algorithm);
  ss << SINGLELINE << "\n" << PrintGraph() << "\n" << SINGLELINE << "\n";
  ss << "\n\n\tTotal Head Movements = " << this->HeadMovements << "\n";
  ss << SINGLELINE << "\n" << DOUBLELINE  << "\n";
  return ss.str();
}

/*
* Tests the assigned algorithm against the sequence of number and only reports
*   the total number of movements required to process the requests
*/
std::string Scheduler::TestAlgorithmNoGraph(){
  std::stringstream ss;
  ss  << std::endl << DOUBLELINE << std::endl;
  CalculateTotalHeadMovements();
  ss << PrintHeader(this->algorithm);
  ss << SINGLELINE << "\n\n\tTotal Head Movements = " << this->HeadMovements
        << "\n" << DOUBLELINE  << "\n";
  return ss.str();
}

/*
* Outputs a string containing a formatted hearer based on a given algorithm
*/
std::string Scheduler::PrintHeader(Algorithm algo){
  std::stringstream ss;
  ss << DOUBLELINE << "\n\tSequence processed using ";
  switch(algo){
    case Algorithm::SSTF:
      ss << "SSTF\n";
      break;
    case Algorithm::SCAN:
      ss << "SCAN\n";
      break;
    case Algorithm::CSCAN:
      ss << "CSCAN\n";
      break;
    case Algorithm::LOOK:
      ss << "LOOK\n";
      break;
    case Algorithm::CLOOK:
      ss << "CLOOK\n";
      break;
    case Algorithm::FCFS:
    default:
      ss << "FCFS\n";
      break;
  }
  ss << "\n" << SINGLELINE  <<  "\n\t    Number of cylinder requests: "
  /* Requests minus one removes the initial starting position from the count */
      << this->Requests-1   <<  "\n\t    Initial starting position: "
        << CurrentPosition  <<  "\n"  << SINGLELINE << "\n";
  return ss.str();
}

/*
* Prints a graph of the algorithms operation by printing the cylinder number on
*   on a line a proportional distance from the left margin as the cylinder is
*   distance from the first cylinder on a disc. Since this requires a new line
*   for each cylinder request, this is not recommended for a very large number
*   of requests
*/
std::string Scheduler::PrintGraph(){
  std::stringstream ss;
  ss << std::endl << SINGLELINE << std::endl;
  for(int i = 0; i < Sequence.size(); i++){
    int space = Sequence[i]/RATIO;
    for(int j = 0; j < space; j++)
      ss << " ";
    ss << Sequence[i] << "\n";
  }
  ss << std::endl << SINGLELINE << std::endl;
  return ss.str();
}
