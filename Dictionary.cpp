#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
	for(int i = 0; i < 10; i++){
		arr[i] = new OList();
	}
}

Dictionary::~Dictionary() {
	for(int i = 0; i < 10; i++){
		delete arr[i];
	}
}

// adapted from https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html
int Dictionary::fold(std::string name){
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	sum += (int) name[i];
	return sum % 5;
}

void Dictionary::insert(Person p){
	int key = fold(p.get_name());
	arr[key]->insert(p); // method from OList
}

Person Dictionary::get_p(std::string name){
	int key = fold(name);
	return arr[key]->find(name);
}

std::string Dictionary::get_keys(){
	std::string keys = "";
	for (int i = 0; i < 10; i++){
		if (arr[i]->toString() != "") {
        keys += arr[i]->toString();
      }
   }
   return keys;
}

