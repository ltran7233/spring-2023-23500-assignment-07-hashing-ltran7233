#include <iostream>
#include "Node.h"
#include "OList.h"
#include "Person.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
    Node *walker = head;
    Node *trailer = nullptr;
    while (walker != nullptr){
      trailer = walker;
      walker = walker->getNext();
      delete trailer;
    }
}

// insert at the "front" (head)
void OList::insert(Person data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  head = tmp;
}

int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

Person OList::find(std::string data){
  Node *walker = head;
  while (walker != nullptr && walker->getData().get_name() != data){
    walker = walker->getNext();
  }
  if (walker == nullptr){
    throw PERSON_ERR_NOTFOUND;
  } else {
    return walker->getData();
  }
}

std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData().get_name() + "|";
    tmp = tmp->getNext();
  }
  return result;
}

Person OList::get(Person p){
  Node *tmp = this->head;
  while(tmp != nullptr){
		if (tmp->getData().get_id()==p.get_id()){
				return tmp->getData();
		}  		
    tmp = tmp->getNext();
  }
	throw PERSON_ERR_NOTFOUND;
}
