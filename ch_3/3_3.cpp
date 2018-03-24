#include <iostream>

using namespace std;

class stack {
public:
  // stack_capcity of each stack
  stack(int stack_capacity = 50) {
    stack_array = new int[stack_capacity]();
    top_idx = 0;
  }
  virtual ~stack() {
    delete [] stack_array;
  }

  void push(int value) {
      stack_array[top_idx] = value;
      top_idx++;
  }

  int top() {
    //cout << "top!" << endl;
    int ret_val = stack_array[top_idx - 1];
    return ret_val;
  }

  int pop() {
    int ret_val = stack_array[top_idx - 1];
    top_idx--;
    return ret_val;
  }
  
  bool is_empty() {
    return (top_idx == 0);
  }

private:
  int *stack_array;
  int top_idx;
};


class my_queue {
public:
  my_queue() {};
  virtual ~my_queue() {};

  void add(int value) {
    normal.push(value);
  }

  int top() {
    shift_stacks();
    return reversed.top();
  }

  int remove() {
    shift_stacks();
    return reversed.pop();
  }

private:
  stack normal, reversed;

  void shift_stacks() {
    if (reversed.is_empty()) {
      while (!normal.is_empty()) {
        reversed.push(normal.pop());
      }
    }
  }
};

int main()
{
  my_queue test_queue;

  for (int i = 0; i < 5; i++) {
    test_queue.add(i);
  }

  for (int i = 0; i < 3; i++) {
    cout << "remove in queue: " << test_queue.remove() << endl;
  }

  for (int i = 5; i < 10; i++) {
    test_queue.add(i);
  }

  for (int i = 0; i < 5; i++) {
    cout << "remove in queue: " << test_queue.remove() << endl;
  }

  return 0;
}
