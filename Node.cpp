#include <iostream>
#include "Node.h"
#include "Person.h"

Node::Node() {
  this->next = nullptr;
}

Node::Node(Person data){
  this->data = data;
  this->next = nullptr;
}

Node::Node(Person data, Node *next){
  this->data = data;
  this->next = next;
}

Node::Node(std::string f, std::string l, int n){
	Person p = Person(f, l, n);
	this->data = p;
}

void Node::setData(Person data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

Person Node::getData(){
  return this->data;
}

Node *Node::getNext(){
  return this->next;
}
