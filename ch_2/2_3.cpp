#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Node {
  char data;
  Node *next = NULL;
};

void insert_to_tail(Node *head, char data)
{
  Node *end = new Node;

  // insert data
  end->data = data;

  // place this new node on the tail of the list
  while (head->next != NULL) {
    head = head->next;
  }
  head->next = end;
}

void print_list(Node *head)
{
  while (head) {
    cout << head->data << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}

void deleteMiddleNode (Node *node)
{
  Node *input_loc = node;


  unsigned int cnt = 0;

  if (node == NULL || node->next == NULL) {
    cout << "This is NOT middle node!" << endl;
    return;
  }

  while (node->next != NULL) {
    node = node->next;
    cnt += 1;
  }

  if (cnt == 1) {
    cout << "This is NOT middle node!" << endl;
    return;
  }

  node = input_loc;

  Node * nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  //delete nextNode;
}

int main()
{
  unsigned int input_k = 0;

  Node *test_head = new Node;
  
  char test_list[5] = {'a' ,'b', 'c', 'd', 'e'};
  //char test_list[2] = {'a' ,'b'};

  test_head->data = test_list[0];

  for (int i = 1; i < 5; i++) {
    insert_to_tail(test_head, test_list[i]);
  }

  cout << "all list:" << endl;
  print_list(test_head);
  cout << "Deleting node containing data as 'c'\n";
  deleteMiddleNode(test_head->next->next);
  print_list(test_head);

  return 0;
}
