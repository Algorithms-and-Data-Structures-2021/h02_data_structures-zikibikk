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

    linkedList->Insert(5,Element::DRAGON_BALL);
    linkedList->Set(,Element::DRAGON_BALL);
  std::cout << linkedList->IndexOf(Element :: DRAGON_BALL);
  
  return 0;
}