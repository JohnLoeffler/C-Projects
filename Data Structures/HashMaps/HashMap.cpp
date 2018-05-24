#include "HashMap.h"

HashMap::~HashMap(){
  for(int i = 0; i < NumRows; i++){
    HNode<K, V> *Row = Map[i];
    while(Row != nullptr){
      HNode<K, V> *P = Row;
      Row = Row->GetNext();
      delete Row;
    }
    Row[i] = nullptr;
  }
  delete [] Map;
}

void HashMap::Add(const K& Key, const V& Value){
  unsigned hash = HashFunction(Key);
  HNode<H,V> *Row = Map[hash], *Q = nullptr;
  while(Row != nullptr && Row->GetKey() != Key){
    Q = Row;
    Row = Row->Next();
  }
  if(Row == nullptr){
    Row = new HNode<K,V>(Key, Value);
    if(Q == nullptr){
      Map[hash] = Row;
    }else{
      Q->SetNext(Row);
    }
    Size++; //  Only add to Size if we add a new node
  }else{
    Row->SetValue(Value);
  }
}
void HashMap::Remove(const K& Key){
  unsigned hash = HashFunction(Key);
  HNode<H,V> *Row = Map[hash], *Q = nullptr;
  while(Row != nullptr && Row->GetKey() != Key){
    Q = Row;
    Row = Row->Next();
  }
  if(Row == nullptr){ //  Key not in the table
      return;
  }else{
    if(Q == nullptr){
      Map[hash] = Row->GetNext();
    }else{
      Q->SetNext(Row->GetNext());
    }
    delete Row;
  }
  Size--;
}

bool HashMap::Get(const K& Key, V& Value){
  unsigned hash = HashFunction(Key);
  HNode<H,V> *Row = Map[hash];
  while(Row != nullptr){
    if(Row->GetKey() == Key){
      Value = Row->GetValue();
      return true
    }
    Row = Row->Next();
  }
  return false;
}
unsigned HashMap::HashFunction(const K& Key){
  return (Key % NumRows);
}
