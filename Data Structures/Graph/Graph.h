#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <exception>
#include <cstring>

/*********************************
*
* Declaration
*
*********************************/

/**
* Generic template Node (the graph vertex), Exception, and Graph Structure class
*/
template <typename T>
struct GraphVertex{
  T t;
  int index;
public:
  /**
  * Parameterized Constructor
  * @param index  The array index of the graph pointing to this vertex
  * @param t      The data attached to this vertex
  */
  GraphVertex(int index, T t);
  /** Destructor */
  virtual ~GraphVertex();
  /** 
  * Prints the index of the vertex
  * @return A c-string assigned index for the vertex
  */
  char* PrintVertex();
};

/*********************************
*
* Implementaion
*
*********************************/


/* ctor */
template <typename T>
GraphVertex<T>::GraphVertex(int index, T t){
  this->index = index;
  this->t = t;
}

/* dtor */
template <typename T>
GraphVertex<T>::~GraphVertex(){}

/* For the default generic template, PrintVertex() only prints the index assigned to the vertex */
template <typename T>
char* GraphVertex<T>::PrintVertex(){
  int div = index, count = 0;
  while(div > 10){
    div /= 10;
    count++;
  }
  count++;  //  Count final digit
  char* Num = new char[count+1];  //  digit count and \0 terminator
  return itoa(index, Num, 10);
}

/*********************************
*
* Declaration
*
*********************************/

/**
* int data type specialization of the template
*/
template <>
struct GraphVertex<int>{
  int data;
  int index;
public:
  /**
  * Parameterized Constructor
  * @param index  The array index of the graph pointing to this vertex
  * @param data   The data attached to this vertex, separate from assigned index
  */
  GraphVertex(int index, int data);
  /** Destructor */
  virtual ~GraphVertex();
  /** Prints the index of the vertex and its associated data */
  char* PrintVertex();
};

/*********************************
*
* Implementation
*
*********************************/

/* ctor */
GraphVertex<int>::GraphVertex(int index, int data){
  this->index = index;
  this->data = data;
}

/* dtor */
GraphVertex<int>::~GraphVertex(){}

/* Generates a formatted c-string from the index of the vertex and its associated data */
char* GraphVertex<int>::PrintVertex(){
  int div = index, count1 = 0, count2 = 0;
  // Count number of digits in index
  while(div > 10){
    div /= 10;
    count1++;
  }
  count1++; //  Count last digit
  char* Out, *ind, *dat;  
  ind = new char[count1+1];
  //  Convert index to c-string
  itoa(index, ind, 10);
  div = data;
  //  count number of digits in data
  while(div > 10){
    div /= 10;
    count2++;
  }
  count2++;
  dat = new char[count2+1];
  //  Convert data to c-string
  itoa(data, dat, 10);
  Out = new char[count1+count2+4];
  strcpy(Out, "[");
  strcat(Out, ind);
  strcat(Out, "]:");
  strcat(Out, dat);
  //  Return formatted string
  return Out;
}

/*********************************
*
* Declaration
*
*********************************/

/**
* float data type specialization of the template
*/
template <>
struct GraphVertex<float>{
  float data;
  int index;
public:
  /**
  * Parameterized Constructor
  * @param index  The array index of the graph pointing to this vertex
  * @param data   The data attached to this vertex, separate from assigned index
  */
  GraphVertex(int index, float data);
  /** Destructor */
  virtual ~GraphVertex();
  /** 
  * Prints the index of the vertex and its associated data 
  * @return A c-string with the formatted vertex information
  */
  char* PrintVertex();
};

/*********************************
*
* Implementation
*
*********************************/

/* ctor */
GraphVertex<float>::GraphVertex(int index, float data){
  this->index = index;
  this->data = data;
}

/* dtor */
GraphVertex<float>::~GraphVertex(){}

/* Generates a formatted c-string from the index of the vertex and its associated data */
char* GraphVertex<float>::PrintVertex(){
  long Div = data * 10000;  //  Precision to 4 decimal places
  int InDiv = index, Rem = 0, Count1 = 0, Count2 = 0;
  bool Digit = false;
  // Count digits in index
  while(InDiv > 10){
    InDiv /= 10;
    Count1++;
  }
  Count1++; 
  //  Count up to the four most significant digits after the decimal point
  for(int i = 0; i < 4; i++){
    Rem = Div %10;
    Div /= 10;
    if(Rem != 0 && !Digit)
      Digit = true;
    if(Digit) //  Only start counting once a significant digit is reached
      Count2++;
  }
  //If no significant digit found, count decimal point and a single trailing zero after decimal point
  if(Count2 == 0) 
    Count2 = 2;
  else
    Count2++; //  else, include the decimal point in count
  
  Div = (long) data; // remove decimal digits, leaving digits greater than or equal to one
  
  //  Count number of digits
  while(Div > 10){
    Div /= 10;
    Count2++;
  }
  Count2++; //  Capture final digit

  //  Convert index and data to c-strings
  char* Out, *ind, *dat;
  ind = new char[Count1+1];
  sprintf(ind, "%d", index);
  dat = new char[Count2+1];
  sprintf(dat, "%f", data*100);
  
  //  format and return output string
  Out = new char[Count1+Count2+4];
  strcpy(Out, "[");
  strcat(Out, ind);
  strcat(Out, "]:");
  strcat(Out, dat);
  return Out;
}

/*********************************
*
* Declaration
*
*********************************/

/**
*   char array specialization for the template
*/
template <>
struct GraphVertex<char*>{
  char* data;
  int index;
public:
  /**
  * Parameterized Constructor
  * @param index  The array index of the graph pointing to this vertex
  * @param data   The data attached to this vertex, separate from assigned index
  */
  GraphVertex(int index, const char* data);
  /** Destructor */
  virtual ~GraphVertex();
  /** 
  * Prints the index of the vertex and its associated data 
  * @return A c-string with the formatted vertex information
  */
  char* PrintVertex();
};

/*********************************
*
* Implementation
*
*********************************/

/* ctor */
GraphVertex<char*>::GraphVertex(int index, const char* dat){
  this->index = index;
  unsigned len = strlen(dat);
  this->data = new char[len+1];
  strcpy(this->data, dat);
}
/* dtor */
GraphVertex<char*>::~GraphVertex(){ if (data != nullptr) delete data; }

/* Generates a formatted c-string from the index of the vertex and its associated data */
char* GraphVertex<char*>::PrintVertex(){
  int div = index, count = 0;
  while(div > 10){
    div /= 10;
    count++;
  }
  count++;  //  Count final digit
  char* ind = new char[count+1];  //  digit count and \0 terminator
  char* Out = new char[(unsigned)count + strlen(data) + 4];
  itoa(index, ind, 10);
  strcpy(Out, "[");
  strcat(Out, ind);
  strcat(Out, "]:");
  strcat(Out, data);
  return Out;
}

/*********************************
*
* Declaration
*
*********************************/

/**
* A small, custom exception class for handling errors generated by graph
*/
class GraphException : public std::exception{
  char *What;
public:
  /**
  * Parameterized Constructor. Cannot throw exception without message, encourages proper error reporting
  * @param M A message explaining why exception is being thrown
  * @param L The Line number where the exception occured (*hint* Use __LINE__ macro)
  * @param F The Function that threw the exception (*hint* Use the __FUNCTION__ macro)
  */
  GraphException(const char* M, const char* L, const char* F);
  virtual ~GraphException();
  /**
  * Retreives the formatted c-string containing the error message from the thrown exception 
  * @return The formatted c-string constaining the error message
  */
  char* GetMessage() const;
};

/*********************************
*
* Implementation
*
*********************************/

/* ctor */
GraphException::GraphException(const char* M, const char* L, const char* F){
  unsigned size = strlen(M);
  size += strlen(L);
  size += strlen(F);
  size += 6; //  Space for formatting output (5) and \0 terminator

  What = new char[size];
  strcpy(What, F);
  strcat(What, " (");
  strcat(What, L);
  strcat(What, "):");
  strcat(What, M);
}

/* dtor */
virtual GraphException::~GraphException(){  delete What; }

/* returns cached message */
char* GraphException::GetMessage() const{   return What; }

/*********************************
*
* Declaration
*
*********************************/

template<typename T>
class Graph{
  std::vector<T> *Adjacent;
  int       NumVertices;
public:
  /**
  * Parameterized Constructor
  * @param Num The number of Graph Nodes to initialize when constructed
  */
  Graph(int Num);
  /** Virtual Destructor */
  virtual ~Graph();
  /** Adds a vertex to the graph, unconnected to any other vertex */
  void AddVertex();
  /**
  * Adds a one directional edge between two vertices
  * @param  From The index of the vertex the edge is starting from
  * @param  To The index of the vertex at the other end of the edge being added
  */
  void AddDirectedEdge(int From, int To);
  /**
  * Adds a Bi-Graph edge between two vertices
  * @param  VertA The index of the first vertex
  * @param  VertB The index of the second vertex
  */
  void AddBiGraphEdge(int VertA, int VertB);
  /**
  * Iterates over the vertices of the graph and builds a formatted c-string listing the vertices, if any, that are connected to the current vertex by an edge.
  * @return A formatted C-String of the Graph
  */
  char* PrintGraph();
};

/*********************************
*
* Implementation
*
*********************************/

/* ctor */
template<typename T>
Graph<T>::Graph(int Num){
  this->NumVertices = Num;
  Num > 0 ? Adjacent = new std::vector<T>[Num] : Adjacent = nullptr;
}
/* dtor */
template<typename T>
Graph<T>::~Graph(){
  delete []Adjacent;
}

/* dynamically adds a new, unconnected vertex to the graph */
template<typename T>
void Graph<T>::AddVertex(){
  std::vector<T>* Tmp = Adjacent;
  NumVertices == 0 ? NumVertices = 1 : NumVertices++;
  Adjacent = new std::vector<T>[NumVertices];
  for(auto Itr : Tmp){
    Adjacent.push_back(*Itr);
  }
}

/* Adds an edge that moves in one direction from one vertex to another */
template<typename T>
void Graph<T>::AddDirectedEdge(int From, int To){
  if(Adjacent == nullptr){
    throw new GraphException("The graph contains no vertices to connect.\n",
                               __LINE__,
                               __FUNCTION__);
  } else if(From >= NumVertices || From < 0){
    char* Temp = new char[64];
    char* Num;
    strcpy(Temp, "The origin vertex for the edge, ");
    strcat(Temp, itoa(From, Num, 10));
    strcat(Temp, ", does not exist.\n");
    throw new GraphException(Temp, __LINE__, __FUNCTION__);
  } else if(To >= NumVertices || To < 0){
    char* Temp = new char[69];
    char* Num;
    strcpy(Temp, "The destination vertex for the edge, ");
    strcat(Temp, itoa(To, Num, 10));
    strcat(Temp, ", does not exist.\n");
    throw new GraphException(Temp, __LINE__, __FUNCTION__);
  }
  Adjacent[From].add(Adjacent[To]);
}

/* Adds a bidirectional edge between two vertices */
template<typename T>
void Graph<T>::AddBiGraphEdge(int VertA, int VertB){
  if(Adjacent == nullptr){
    throw new GraphException("The graph contains no vertices to connect.\n",
                               __LINE__,
                               __FUNCTION__);
  } else if(VertA >= NumVertices || VertA < 0){
    char* Temp = new char[64];
    char* Num;
    strcpy(Temp, "The first vertex for the edge, ");
    strcat(Temp, itoa(VertA, Num, 10));
    strcat(Temp, ", does not exist.\n");
    throw new GraphException(Temp, __LINE__, __FUNCTION__);
  } else if(VertB >= NumVertices || VertB < 0){
    char* Temp = new char[69];
    char* Num;
    strcpy(Temp, "The second vertex for the edge, ");
    strcat(Temp, itoa(VertB, Num, 10));
    strcat(Temp, ", does not exist.\n");
    throw new GraphException(Temp, __LINE__, __FUNCTION__);
  }
  Adjacent[VertA].add(Adjacent[VertB]);
  Adjacent[VertB].add(Adjacent[VertA]);
}

template<typename T>
char* Graph<T>::PrintGraph(){
  /* TODO: Implement PrintGraph() Function */
  return " ";
}
#endif // GRAPH_H
