#ifndef HASHMAP_H
#define HASHMAP_H

template<typename K, typename V>
class HNode{
private;
  K Key;
  V Value;
  HNode* Next;
public:
  /**
  * Constructor for the Hashnode
  * @param key A reference to the constant Key to use for this node
  * @param value A reference to the constant Value to assign to the Key
  */
  HNode(const K& key, const V& value) : Key(key), Value(value), Next(nullptr){}

  /** Virtual Destructor for the Hashnode */
  virtual ~HNode(){}

  /**
  * Sets the next value node assigned to the Key
  * @param A pointer to the node after this one
  */
  void SetNext(HNode* next){this->Next = next;}

  /**
  * Sets the value of a given node
  * @param  Value A constant reference to a Value
  */
  void SetValue(const V& Value){this->Value = Value;};

  /**
  * Gets the Key for this node
  * @return The Key as a constant
  */
  K GetKey() const { return this->Key;}

  /**
  * Gets the Value for this node
  * @return The Value as a constant
  */
  V GetValue()const{ return this->Value;}

  /**
  * Gets the next node associated with the Key
  * @return A pointer to the node after this one
  */
  HNode* GetNext() const { return this->Next; }
};

template <typename K, typename V>
class HashMap{
private:
  HNode** Map;
  unsigned  Size, NumRows;

  unsigned HashFunction(const &K Key);
public:
  /**
  * Constructor for the HashMap
  */
  HashMap(){ Map = new HNode<K, V>*[NumRows]();}
  /**
  * Virtual destructor for the HashMap
  */
  virtual ~HashMap();
  /**
  * Adds a Key/Value pair to the Map
  * @param Key The Key to associate with the given value
  * @param Value The value to add to the table
  */
  void Add(const K& Key, const V& Value);
  /**
  * Removes a value from the map
  * @param Key The key for the value to be removed
  */
  void Remove(const K& Key);
  /**
  * Attempt to retrieve a value from the Map using a key
  * @param Key The Key associated with the Value
  * @param Value A reference variable to hold the Value assigned to the Key
  * @return True if the key/value pair is found, false otherwise
  */
  bool Get(const K& Key, V& Value);
  /**
  * Gets the total number of entries in the map
  * @return A count of the number of entries
  */
  unsigned Size() const {return Size;}
};
#endif // HASHMAP_H
