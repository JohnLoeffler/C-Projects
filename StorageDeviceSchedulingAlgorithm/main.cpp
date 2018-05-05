#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include "Scheduler.h"
#include "Timer.h"
#define SINGLELINE "--------------------------------------------------"
#define DOUBLELINE "=================================================="

#define NUM_CYLINDERS 5000
#define REQUESTS 100
#define START (NUM_CYLINDERS/2)


int main(int argc , char *argv[])
{
  int start;
  Timer Time;
  //  If there is an initial position passed from the command line
  if(argc != 0){
    //  Make sure the argument is valid
    std::stringstream ss;

    ss << argv[1];  // using a stringstream does 2 things, it converts the char*
    ss >> start;    // into an int for us, but it also guards against a bad
                    // argument because if the value is not an int, it will spit
                    // out NULL, which will just be zero and so it will be valid

    start = abs(start); //  makes a negative positive

    if(start >= NUM_CYLINDERS || start < 0){ //  Make sure argument is in range
      start %= NUM_CYLINDERS;
    }
  }else{  //  ELSE no argument passed
    start = START;  //  Start in the middle of the disc
  }
  Scheduler *sch;

  for(int i = 0; i < 6; i++ ){
    int _st = (int) Time.GetElapsedTime();  //  used to
    std::cout << DOUBLELINE << "\n";
    std::cout << "Test number: " <<(i +1)<< "\n" << SINGLELINE << "\n";
    sch = new Scheduler(NUM_CYLINDERS, start, REQUESTS);
    switch(i){
        case 0:
          sch->SortSequence(Algorithm::FCFS);
          break;
        case 1:
          sch->SortSequence(Algorithm::SSTF);
          break;
        case 2:
          sch->SortSequence(Algorithm::SCAN);
          break;
        case 3:
          sch->SortSequence(Algorithm::CSCAN);
          break;
        case 4:
          sch->SortSequence(Algorithm::LOOK);
          break;
        case 5:
          sch->SortSequence(Algorithm::CLOOK);
          break;
      }
      /*
      * Uncomment to see a more concise report on the graphs operations without
      *   a graph. Best used for very large number sequences
      */
      //std::cout << sch->TestAlgorithmNoGraph();

      std::cout << sch->TestAlgorithm();

      /*
      * Allow a second to pass so program generates a more random sequence of
      *   numbers for next test
      */
      while((Time.GetElapsedTime() - _st) < 1000){

      }
    }
  return 0;
}
