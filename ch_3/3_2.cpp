#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_INT = ~(1<<31);

int random_number(int min, int max) {
  int return_val = rand() % max + min;

  //cout << "return_val: " << return_val << endl;

  return return_val;
}

class stack {
public:
  // stack_capcity of each stack
  stack(int stack_capacity = 10) {
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
    top_idx--;
  }
  
  bool empty() {
    return (top_idx == 0);
  }

private:
  int *stack_array;
  int top_idx;
};

class stack_min {
public:
  // stack_capcity of each stack
  stack_min(int stack_capacity);
  virtual ~stack_min();

  void push(int value);
  int pop();
  int top();
  int min();

private:
  int stack_capacity;
  int *stack_array;
  int top_idx;
  stack track_min;
};


stack_min::stack_min(int stack_capacity)
{
  this->stack_capacity = stack_capacity;
  // declare with initialization
  stack_array = new int[stack_capacity]();
  top_idx = 0;
}

stack_min::~stack_min()
{
  delete [] stack_array;
}

void stack_min::push(int value)
{
  stack_array[top_idx] = value;
  top_idx++;
 
  if (value <= min())
    track_min.push(value);
}

int stack_min::top()
{
  int ret_val = stack_array[top_idx - 1];

  return ret_val;
}

int stack_min::pop()
{
  //cout << "top_idx: " << top_idx << endl;
  int ret_val = stack_array[top_idx - 1];

  if (ret_val == min())
    track_min.pop();

  stack_array[top_idx - 1] = 0;
  top_idx--;

  return ret_val;
}

int stack_min::min()
{
  if (track_min.empty())
    return MAX_INT;
  else 
    return track_min.top();
}

int main()
{
  stack_min test_stack(50);

  for (int i = 0; i < 10; i++) {
    int pushing_value = random_number(1,100);
    cout << "pushing value: " << pushing_value << endl; 
    test_stack.push(pushing_value);
  }

  cout << "top in stack: " << test_stack.top() << endl;

  cout << "min in stack: " << test_stack.min() << endl;

  return 0;
}
