#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Node {
  int data = 0;
  Node *next = NULL;
};

void insert_to_tail(Node *head, int data)
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

int random_number(int min, int max) {
  int return_val = rand() % max + min;

  //cout << "return_val: " << return_val << endl;

  return return_val;
}

int find_k_th_value(Node *head, int k)
{
  vector<int> value_table;
  int idx = 0;

  while (head) {
    value_table.push_back(head->data);
    head = head->next;
  }

  //cout << value_table.size() << endli;
  
  idx = value_table.size() - k;

  return value_table[idx];
}

// i - an index for keeping track of current node
Node * find_k_th_value(Node *head, int k, unsigned int &i)
{
  if (head == NULL)
    return NULL;

  Node *node = find_k_th_value(head->next, k, i);
  i = i + 1;

  if (i == k)
    return head;
  else
    return node;
}

Node * find_k_th_value_w_recursive(Node *head, int k)
{
  // index
  unsigned int i = 0;

  return find_k_th_value(head, k, i);
}

Node * find_k_th_iterative(Node * head, int k)
{
  if (head == NULL)
    return head;

  Node *ptr1 = head;
  Node *ptr2 = head;

  int idx = 0;
  while (idx < k && ptr1) {
    ptr1 = ptr1->next;
    idx++;
  }

  // out of bounds
  if (idx < k)
    return NULL;
  
  // when ptr1 hits the end, ptr2 will be at the right element
  while (ptr1 != NULL) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return ptr2;
}

int main()
{
  unsigned int input_k = 0;
  int k_th_data = 0;

  Node *test_head = new Node;
  
  // the value of the fisrt head
  test_head->data = random_number(1,5);

  for (int i = 0; i < 9; i++) {
    insert_to_tail(test_head, random_number(1,5));
  }

  cout << "all list:" << endl;
  print_list(test_head);

  cout << "enter the number K that node number from last to see data:";
  cin >> input_k;

  cout << input_k << "th value of the list (from the tail) is: " << endl;

  k_th_data = find_k_th_value(test_head, input_k);
  cout << k_th_data << endl;

  cout << "using recursive function: " << endl;
  Node *k_th_node = find_k_th_value_w_recursive(test_head, input_k);
  cout << k_th_node->data << endl;

  cout << "using two pointers: " << endl;
  Node *k_th_node_2 = find_k_th_iterative(test_head, input_k);
  cout << k_th_node_2->data << endl;

}
