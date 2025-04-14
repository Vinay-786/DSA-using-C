#include <iostream>
#include <vector>
#include "list.hpp"

Node *LinkedList(const std::vector<int> &a) {
  Node *head = nullptr;
  Node *tail = nullptr;

  for (int val : a) {
    Node *temp = new Node();
    temp->data = val;
    temp->link = nullptr;

    if (head == nullptr) {
      head = temp;
      tail = temp;
    } else {
      tail->link = temp;
      tail = temp;
    }
  }
  return head;
}

void FreeList(Node *head) {
  while (head != nullptr) {
    Node *next = head->link;
    delete head;
    head = next;
  }
}
