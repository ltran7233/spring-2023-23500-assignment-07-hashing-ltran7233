#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"

#define PERSON_ERR_NOTFOUND 1

class OList{
 private:
  Node *head;
 public:
  OList();
  void insert(Person data);
  int length();
  Person find(std::string data);

  std::string toString(); // for testing purposes

  Person get(Person p);
  ~OList();
};
