#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
	std::cerr << "Calling the destructor";
    Node *walker = head;
    Node *trailer = nullptr;
    while (walker != nullptr){
      trailer = walker;
      walker = walker->getNext();
      delete trailer;
    }
}

// insert at the "front" (head)
void OList::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

/*
  insert at loc
  We need a pointer to the node BEFORE
  the location where we want to insert 
  Piggybacking 
 */
void OList::insert(int loc, std::string data){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }

  // At this point, trailer points to the Node
  // BEFORE where we want to insert


  // test to see if we're trying to
  // insert past the end 
  if (loc > 0){
    // do something to indicate this is invalid
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  // Inserting at true location 0
  // will have trailer == nullptr
  // - we have to treat that as a special case
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    // do the regular case 
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
}

/*
  Alternate solution:
    make a private variable to store the length
    and just return it here.
    Change all the insert/delete/remove type
    routines to upate that variable 
 */
int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

std::string OList::find(std::string data){
  Node *walker = head;
  while (walker != nullptr && walker->getData() != data){
    walker = walker->getNext();
  }
  if (walker == nullptr){
    return "";
  } else {
    return walker->getData();
  }
}

std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

bool OList::contains(std::string item){
  Node *walker = this->head;
  while(walker != nullptr){
    if(walker->getData() == item){
      return true;
    }
    walker = walker->getNext();
  }
  return false;
}

std::string OList::get(int loc){
  Node *tmp = this->head;
  while(loc > 0 && tmp != nullptr){
    loc--;
    tmp = tmp->getNext();
  }

  if (tmp == nullptr){ 	// tmp never got to loc
    throw std::out_of_range("Index out of bounds!");
  }
  return tmp->getData();
}

void OList::reverse(){
  Node *curr = head;
  Node *prev = nullptr;
  Node *next = nullptr;

  while(curr != nullptr){
    next = curr->getNext();
    curr->setNext(prev);
    prev = curr;
    curr = next;
  }
  head = prev;
}

void OList::remove(int loc){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
       loc--;
       /* trailer will always be one node
       behind walker */
       trailer = walker;
       walker = walker->getNext();
  }

  // test to see if we're trying to remove past the end 
  if (walker == nullptr){
    throw std::out_of_range("Index out of bounds!");
  }

  if (trailer == nullptr){ // removing at 0
    head = walker->getNext();
    delete walker;
  } 
  else{
    trailer->setNext(walker->getNext());
    delete walker;
  }
}
