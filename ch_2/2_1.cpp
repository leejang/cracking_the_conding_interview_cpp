#include <iostream>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

// define singly linked list

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

// space complexity O(1)
// time complexity O(n^2)
void remove_duplicates(Node *head)
{
  if (head == NULL || head->next == NULL) {
    return;
  } else {

    Node *cur_head = head;

    while (cur_head) {
      Node *runner  = cur_head;
      while (runner->next != NULL) {
        if (runner->next->data == cur_head->data) {
          runner->next = runner->next->next;
        } else {
          runner = runner->next;
        }
      }
      cur_head = cur_head->next;
    }
  }
}

# if 0
// using hash table
void remove_duplicates(Node *head)
{
  unordered_map<int, int> hash_table;

  if (head == NULL || head->next == NULL) {
    return;
  } else {

    Node *cur_head = head;
    Node *next_head = head->next;
    hash_table[cur_head->data] = 1;

    while (next_head) {
      unordered_map<int,int>::const_iterator got = hash_table.find(next_head->data);

      if (got == hash_table.end()) {
        hash_table[next_head->data] = 1;
        cur_head = cur_head->next;
      } else {
        //cout << "found duplicates: " << next_head->data << endl;
        cur_head->next = next_head->next;
        cur_head = next_head;
      }
      next_head = next_head->next;
    }
  }
}
#endif

// space complexity - O(n)
// time complexity - O(n)
void remove_duplicates1(Node *head)
{
  unordered_map<int, int> hash_table;

  if (head == NULL || head->next == NULL) {
    return;
  } else {
    Node *cur_head = head;
    Node *next_head = head->next;
    hash_table[cur_head->data] = 1;

    while (next_head) {
      while (next_head && hash_table.find(next_head->data) != hash_table.end()) {
        //cout << "next_head->data: " << next_head->data << endl;
        next_head = next_head->next;
      }
      cur_head->next = next_head;
      cur_head = next_head;

      if (next_head) {
        hash_table[next_head->data] = 1;
        next_head = next_head->next;
      }
    }
  }
}

// space complexity - O(n)
// time complexity - O(n)
void remove_duplicates2(Node *start)
{
  unordered_map<int, int> hash_table;

  if (start == NULL || start->next == NULL) {
    return;
  } else {
    Node *curr = start;
    Node *prev = NULL;

    while (curr) {
      // check if the current data is seen before
      if (hash_table.find(curr->data) != hash_table.end()) {
        prev->next = curr->next;
      } else {
        hash_table[curr->data] = 1;
        prev = curr;
      }
      curr = prev->next;
    }
  }
}

int main()
{
  Node *test_head = new Node;

  // the value of the fisrt head
  test_head->data = random_number(1,3);

  for (int i = 0; i < 9; i++) {
    insert_to_tail(test_head, random_number(1,3));
  }

  cout << "before:" << endl;
  print_list(test_head);
  remove_duplicates(test_head);
  cout << "after method1:" << endl;
  print_list(test_head);
  remove_duplicates1(test_head);
  cout << "after method2:" << endl;
  print_list(test_head);
  remove_duplicates2(test_head);
  cout << "after method3:" << endl;
  print_list(test_head);
}
