#pragma once
#include <iostream>
#include "OList.h"
#include "Person.h"

class Dictionary {
private:
  OList *arr[10];
  
public:
  Dictionary();
  ~Dictionary();
  int fold(std::string name);
  void insert(Person p);
  Person get_p(std::string name);
  std::string get_keys();
};
