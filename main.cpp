#include <iostream>

#include "array_list.hpp"
#include "linked_list.hpp"

using namespace itis;

int main(int argc, char **argv) {
  std::cout << "Hello, stranger!" << std::endl;
/*
  auto array_list = new ArrayList();

  delete array_list;*/
  
  LinkedList* linkedList = new LinkedList;
  linkedList->Add(Element::CHERRY_PIE);
  linkedList->Add(Element::SECRET_BOX);
  linkedList->Add(Element::BEAUTIFUL_FLOWERS);
  linkedList->Add(Element::SECRET_BOX);
  linkedList->Add(Element::BEAUTIFUL_FLOWERS);
  linkedList->Add(Element::SECRET_BOX);
  linkedList->Add(Element::SECRET_BOX);


  linkedList->Remove(2);
  std::cout << linkedList->IndexOf(Element :: BEAUTIFUL_FLOWERS);
  linkedList->Clear();
    //std::cout << linkedList->IndexOf(Element :: BEAUTIFUL_FLOWERS);

  return 0;
}