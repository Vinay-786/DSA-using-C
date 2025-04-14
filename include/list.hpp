#include <vector>

struct Node {
  int data;
  Node *link;
};

Node *LinkedList(const std::vector<int> &a);
void FreeList(Node *head);
