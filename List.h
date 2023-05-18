#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"

class OList{
 private:
  Node *head;
 public:
  OList();
  void insert(std::string data);
  void insert(int loc, std::string data); //0 indexed
  int length();
  std::string find(std::string data);

  std::string toString(); // for testing purposes

  bool contains(std::string item);
  std::string get(int loc);
  void reverse();
  void remove(int loc);
  ~OList();
};
