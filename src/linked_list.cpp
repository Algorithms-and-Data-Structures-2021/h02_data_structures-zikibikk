#include "linked_list.hpp"

#include <cassert>    // assert
#include <stdexcept>  // out_of_range

#include "private/internal.hpp"  // это не тот приват, о котором вы могли подумать

namespace itis {

    // Tip 1: создайте узел в куче со переданным значением
    // Tip 2: есть 2 случая - список пустой и непустой
    // Tip 3: не забудьте обновить поля head и tail
    // напишите свой код здесь ...
void LinkedList::Add(Element e) {

  Node* element = new Node(e, nullptr);

  if(head_ == nullptr){
      assert(tail_ == nullptr && size_ == 0);
      head_ = element;
      tail_ = element;
  }
  else{
      tail_->next = element;
      tail_ = element;
  }

  size_++;

}

    // Tip 1: вставка элементов на позицию size эквивалентно операции добавления в конец
    // Tip 2: рассмотрите несколько случаев:
    //        (1) список пустой //список пустой если size = 0, тогда вызовем add
    //        (2) добавляем в начало списка,
    //        (3) добавляем в конец списка //тогда добавим хвост через add
    //        (4) все остальное

    // напишите свой код здесь ...
void LinkedList::Insert(int index, Element e) {
  internal::check_out_of_range(index, 0, size_ + 1);//?почему +1

  if(index == size_)
      Add(e);

  else{
      Node* newNode;
      if(index==0){
          newNode = new Node(e,head_);
          head_=newNode;
      } else if(index==size_-1){
          newNode = new Node(e,tail_);
          tail_=newNode;
      } else{
          Node *oldNode = find_node(index-1);
          newNode = new Node(e, oldNode->next);
          oldNode->next = newNode;
      }
  }
}

    // Tip 1: используйте функцию find_node(index)
    // напишите свой код здесь ...
void LinkedList::Set(int index, Element e) {
  internal::check_out_of_range(index, 0, size_);
    Node *newNode = find_node(index);
    newNode->data = e;
}

    // Tip 1: рассмотрите случай, когда удаляется элемент в начале списка
    // Tip 2: используйте функцию find_node(index)
    // напишите свой код здесь ...
Element LinkedList::Remove(int index) {
  internal::check_out_of_range(index, 0, size_);
  Node *result;
  if (index==0){
      result = head_;
      head_=head_->next;
  } else{
      Node* previous = find_node(index-1);
      result = find_node(index);
      previous->next = result->next;
  }
  Element  elem = result->data;
  size_--;
  delete(result);
  return elem;
}

    // Tip 1: люди в черном (MIB) пришли стереть вам память
    // напишите свой код здесь ...
void LinkedList::Clear() {
    for (int i = 0; i < size_; ++i) {
        Remove(0);
    }
    size_=0;
    head_= nullptr;
    tail_= nullptr;
}

    // напишите свой код здесь ...
Element LinkedList::Get(int index) const {
  internal::check_out_of_range(index, 0, size_);

  Node* result = find_node(index);
  return result->data;
}

    // напишите свой код здесь ...
int LinkedList::IndexOf(Element e) const {
    Node* result = head_;
    for (int i = 0; i < size_; i++) {
        if(result->data==e)
            return i;
        result = result->next;
    }

    return kNotFoundElementIndex;
}

    // Tip 1: можете сразу обработать случаи поиска начала и конца списка
    // напишите свой код здесь ...
Node *LinkedList::find_node(int index) const {
  assert(index >= 0 && index < size_);
    if(index==0)
        return head_;
    if(index == size_-1)
        return tail_;

    Node* result = head_;
    for (int i = 1; i < index+1; i++) {
        result = result->next;
    }
    return result;
}

// РЕАЛИЗОВАНО

LinkedList::~LinkedList() {
  Clear();
}

bool LinkedList::Contains(Element e) const {
  // если индекс не найден, значит и элемента нет
  return IndexOf(e) == kNotFoundElementIndex;
}

int LinkedList::GetSize() const {
  return size_;
}

bool LinkedList::IsEmpty() const {
  return size_ == 0;
}

Element LinkedList::tail() const {
  // вместо выброса ошибки в случае nullptr, римским парламентов было решено возвращать "специальное" значение
  return tail_ ? tail_->data : Element::UNINITIALIZED;
}

Element LinkedList::head() const {
  return head_ ? head_->data : Element::UNINITIALIZED;
}

// === RESTRICTED AREA: необходимо для тестирования ===

LinkedList::LinkedList(const std::vector<Element> &elements) {
  assert(!elements.empty());

  size_ = elements.size();
  head_ = new Node(elements[0], nullptr);

  auto current_node = head_;

  for (int index = 1; index < static_cast<int>(elements.size()); index++) {
    current_node->next = new Node(elements[index], nullptr);
    current_node = current_node->next;
  }
  tail_ = current_node;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
  if (list.head_ != nullptr && list.tail_ != nullptr) {
    os << "{ ";
    for (auto current_node = list.head_; current_node != list.tail_; current_node = current_node->next) {
      os << internal::elem_to_str(current_node->data) << ", ";
    }
    os << internal::elem_to_str(list.tail_->data) << " }";
  } else {
    os << "{ nullptr }";
  }
  return os;
}

bool operator==(const LinkedList &list, const std::vector<Element> &elements) {
  if (list.size_ != static_cast<int>(elements.size())) return false;
  Node *current_node = list.head_;

  for (const auto e : elements) {
    if (current_node == nullptr) return false;
    if (current_node->data != e) return false;
    current_node = current_node->next;
  }
  return true;
}

}  // namespace itis