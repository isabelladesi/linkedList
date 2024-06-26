#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const;

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const;

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front();

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back();

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum);

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front();

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back();

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear();

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

  List() : first(nullptr), last(nullptr) {}  // default constructor 
    List (const List<T> &other) : List(){ //copy constructor
     copy_all(other);
   }
  ~List() {      // destructor
    clear();
  }
  List &operator=(const List<T> & that){ //overload assignment operator
    if(this == &that){
      return *this;
    }
    else{
      clear();
      copy_all(that);
      return *this;
    }
  }

private:
  int sizeOf = 0;
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other);

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.
    //Iterator(); //default constructor
    Iterator()
      : node_ptr(nullptr) { }
    


    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    // T & operator*() const;
    // Iterator & operator++();
    // bool operator==(Iterator rhs) const;
    // bool operator!=(Iterator rhs) const;

    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

   T& operator*() const {
      assert(node_ptr);
      return node_ptr->datum;
    }

    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(Iterator rhs) const {
      return node_ptr == rhs.node_ptr;
    }

    bool operator!=(Iterator rhs) const {
      return node_ptr != rhs.node_ptr;
    }

    


  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;
    // construct an Iterator at a specific position
    // Iterator(Node *p);

    Iterator(Node *p)
      : node_ptr(p){}
      

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const;

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i);

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum);

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.

template <typename T>
bool List<T>::empty() const {
  return first == nullptr; 
}

template <typename T>
int List<T>::size() const {
  return sizeOf;
}

template <typename T>
T &  List<T>::front() {
  assert(!empty());
  return first->datum;
}

template <typename T>
T &  List<T>::back() {
  assert(!empty());
  return last->datum;
}

template <typename T>
void List<T>::push_front(const T &datum) {
  Node *new_node = new Node{first, nullptr, datum};
   if(empty()){ 
      last = new_node;
    } else {
      first->prev = new_node;
    }
  first = new_node;
  ++sizeOf;
}

template <typename T>
void List<T>::push_back(const T &datum) {
  Node *new_node = new Node{nullptr, last, datum};
  if (empty()) {
    first = last = new_node;
  } else {
    last = last->next = new_node;
  }
  ++sizeOf;
}

template <typename T>
void List<T>::pop_front() {
  assert(!empty());
  Node *new_first = first->next;  // temporary keeps track of new first
  delete first;
  first = new_first;
  --sizeOf;
  if (sizeOf == 0){
    first = nullptr;
    last = nullptr;
  }
  else{
    first->prev = nullptr;
  }
}

template <typename T>
void List<T>::pop_back() {
  assert(!empty());
  Node *new_last = last->prev;  // temporary keeps track of new first
  delete last;
  last = new_last;
  --sizeOf;
  if (sizeOf == 0){
    first = nullptr;
    last = nullptr;
  }
  else {
    last->next = nullptr;
  }
}

template <typename T>
void List<T>::clear() {
  while (!(empty())) {
    pop_front();
  }
  sizeOf = 0;
}

template <typename T>
void List<T>::copy_all(const List<T> &other) {
  assert(empty());
  for (Iterator i = other.begin(); i != other.end(); ++i) {
    push_back(*i);
  }
}

template <typename T>
typename List<T>::Iterator List<T>::end() const{

  return Iterator(nullptr);
}

//REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
template <typename T>
void List<T>::erase(Iterator i){
  Node *currentNode = i.node_ptr;
  Node *prevNode = i.node_ptr->prev;
  Node* nextNode = i.node_ptr->next;
  if (i.node_ptr->prev == nullptr){ 
    pop_front();
  }
  else if(currentNode->next == nullptr){
    pop_back();
  }
  else{
    prevNode->next = currentNode->next;
    nextNode->prev = currentNode->prev;
    delete currentNode;
    --sizeOf;
  }
}

//REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
template <typename T>
void List<T>::insert(Iterator i, const T &datum){

  if (i==begin()){
    push_front(datum);
  }
  else if(i == end()){
    push_back(datum);
  }
  else{
    Node *n = new Node;
    n->datum = datum;
    n->next = i.node_ptr; 
    Node *current = i.node_ptr;
    Node *previ = i.node_ptr->prev;
    current->prev = n;
    previ->next = n;
    ++sizeOf;
  }
}

#endif // Do not remove this. Write all your code above this line.
