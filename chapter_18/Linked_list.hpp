//* * * * * * * * * * * * * * * * * * * * * * * * *
//Project Name: Chapter 17 Assignment             *
//Project Description: Linked List implementation *
//Project Author: Wishart, Brent                  *
//Is this an extra credit Project: No             *
//Date completed: 04/09/2015                      *
//Operating system used: OSx 10.10.2              *
//IDE Used: Vi and terminal                       *
//* * * * * * * * * * * * * * * * * * * * * * * * *

//LINKED_LIST.HPP

#ifndef __LINKED__LIST__
#define __LINKED__LIST__

#include <iostream>
#include "cpp_utilities.hpp"

using namespace std;

template <class T>
class Linked_list {
  private:
    struct node {
      T *data;
      node *prev;
      node *next;
    };
    node *head;
    node *tail;
    node *current;

  public:
    Linked_list();
    ~Linked_list();
    T *get_current_data();
    void reset_current();
    void append(T *data);
    void insert(T *data);
    void remove(T *data);
    bool set_current_position(int);
    void print_current(void (*print)(T*));
    void print_all(void (*print)(T*));
    bool backward();
    bool forward();
    int get_num_nodes();
    int nodes_from_current();
};

/* * * * * * * * * * * * * * * * * * * * * * *
Constructor                                  *
Sets head, tail and current to NULL          *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
Linked_list<T>::Linked_list() {
  head = NULL;
  tail = NULL;
  current = NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Destructor                                   *
Increments through the linked list and       *
deletes each node as it goes.                *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
Linked_list<T>::~Linked_list() {
  node *position_node = head;
  node *temp_node;
  int count = 0;
  while (position_node != NULL) {
    temp_node = position_node->next;
    delete position_node->data;
    delete position_node;
    position_node = temp_node;
    count++;
  }
  cout << "List with " << count << " nodes deleted\n";
}

/* * * * * * * * * * * * * * * * * * * * * * *
get_current_data                             *
Returns the data from the current node       *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
T *Linked_list<T>::get_current_data() {

  if (!current) {
    return NULL;
  }

  else {
    return current->data;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
reset_current                                *
Sets the current node to head                *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::reset_current() {
  current = head;
}

/* * * * * * * * * * * * * * * * * * * * * * *
append                                       *
Allocates a new node in memory and sets its  *
data to the data passed to append.           *
Then, it checks if the tail node exists and  *
sets head, tail, and current to the new node *
if it doesn't. If tail does exist, then      *
append sets the new node to tail and sets    *
the old tail's "next" to the new tail node,  *
sets the new tail's "prev" to the the old    *
tail, and sets the new tail's "next" to NULL *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::append(T *data) {
  node *new_node = new node();
  new_node->data = data;

  if (!tail) {
    head = new_node;
    tail = new_node;
    current = new_node;
    head->prev = NULL;
    tail->next = NULL;
  }

  else {
    node *old_tail = tail;
    old_tail->next = new_node;
    new_node->prev = old_tail;
    tail = new_node;
    tail->next = NULL;
    current = new_node;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
insert                                       *
Allocates a new node in memory and sets its  *
data to the data passed to append.           *
If head does not exist, the function sets    *
head, tail, and current to the new node.     *
If head does exist, it check                 *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::insert(T *data) {
  node *new_node = new node();
  new_node->data = data;

  if (!head) {
    tail = new_node;
    head = new_node;
    current = new_node;
    head->prev = NULL;
    tail->next = NULL;
  }

  else {
    if (current == head) {
      node *old_head = head;
      old_head->prev = new_node;
      head = new_node;
      head->next = old_head;
      head->prev = NULL;
    }
    else {
      current->prev->next = new_node;
      new_node->prev = current->prev;
      current->prev = new_node;
      new_node->next = current;
      current = new_node;
    }
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
remove                                       *
This function removes the nodes with data    *
equal to the data passed. There are four     *
cases the function checks for to insure a    *
successful removal.                          *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::remove(T *data) {
  node *position_node = head;

  while (position_node != NULL) {
    if (position_node->data == data) {

      //Case 1: position node is head and next node exists
      if (position_node == head && position_node->next) {
        position_node->next->prev = NULL;
        head = position_node->next;
        current = position_node->next;
      }

      //Case 2: position node is head but next node does not exist
      else if (position_node == head && !position_node->next) {
        head = NULL;
        current = NULL;
        tail = NULL;
      }

      //Case 3: position node is tail
      else if (position_node == tail && position_node->prev) {
        position_node->prev->next = NULL;
        tail = position_node->prev;
        current = tail;
      }

      //Case 4: position node is in the middle
      else {
        position_node->next->prev = position_node->prev;
        position_node->prev->next = position_node->next;
        current = position_node->next;
      }
      delete position_node->data;
      delete position_node;
      break;
    }
    position_node = position_node->next;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
set_current_position                         *
Takes an int and sets current to be the node *
that is that many iterations away from head  *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
bool Linked_list<T>::set_current_position(int pos_num) {
  node *position_node = head;
  int count = 1;

  while (position_node != NULL) {
    if (count == pos_num) {
      current = position_node;
      return true;
    }
    position_node = position_node->next;
    count++;
  }

  return false;
}

/* * * * * * * * * * * * * * * * * * * * * * *
print_current                                *
Takes a function pointer and executes it if  *
current exists.                              *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::print_current(void (*print)(T*)) {

  if (current) {
    print(current->data);
  }

  else {
    cout << "No items to print\n";
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
print_all                                    *
Takes a function pointer and runs it on each *
node in the list if head exists.             *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
void Linked_list<T>::print_all(void (*print)(T*)) {
  node *position_node = head;

  if (!head) {
    cout << "No items to print\n";
  }

  else {
    while (position_node != NULL) {
      print(position_node->data); 
      position_node = position_node->next;
    }
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
backward                                     *
If current and its previous node exist,      *
backward sets current to be the previous     *
node and then returns true. If current is    *
already at head, function returns false      *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
bool Linked_list<T>::backward() {

  if (current && current->prev) {
    current = current->prev;
    return true;
  }
  else {
    return false;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
forward                                      *
If current and its next node exist,          *
forward sets current to be the next node and *
then returns true. If current is at tail,    *
function returns false.                      *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
bool Linked_list<T>::forward() {

  if (current && current->next) {
    current = current->next;
    return true;
  }
  else {
    return false;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * *
get_num_nodes                                *
Function interates through the whole list    *
and returns the number of times it iterated  *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
int Linked_list<T>::get_num_nodes() {
  node *position_node = head;
  int c = 0;

  while (position_node != NULL) {
    c++;
    position_node = position_node->next;
  }

  return c;
}

/* * * * * * * * * * * * * * * * * * * * * * *
nodes_from_current                           *
Returns the number of nodes between head and *
current.                                     *
* * * * * * * * * * * * * * * * * * * * * * */
template <class T>
int Linked_list<T>::nodes_from_current() {
  node *position_node = head;
  int c = 0;
  while (position_node != current) {
    c++;
    position_node = position_node->next;
  }

  return c;
}
#endif
