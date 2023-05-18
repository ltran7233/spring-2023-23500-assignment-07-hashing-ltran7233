#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"

class List{
 private:
  Node *head;
 public:
  List();
  void insert(Person data);
  void insert(int loc, Person data); //0 indexed
  int length();

  std::string toString(); // for testing purposes

  bool contains(Person item);
  Person get(int loc);
  void remove(int loc);
  ~List();
};
