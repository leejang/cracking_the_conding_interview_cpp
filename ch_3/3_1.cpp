#include <iostream>

using namespace std;

class stack_w_single_array {
public:
  // stack_capcity of each stack
  stack_w_single_array(int stack_capacity);
  virtual ~stack_w_single_array();

  void push(int stack_num, int value);
  int pop(int stack_num);
  int top(int stack_num);

  bool is_empty(int stack_num);
  int idx_of_top(int stack_num);

private:
  int num_of_stack = 3;
  int stack_capacity;
  int *stack_array;
  int *each_stack_idx;
};

stack_w_single_array::stack_w_single_array(int stack_capacity)
{
  this->stack_capacity = stack_capacity;
  // declare with initialization
  stack_array = new int[num_of_stack * stack_capacity]();
  each_stack_idx = new int[num_of_stack]();
}

stack_w_single_array::~stack_w_single_array()
{
  delete [] stack_array;
  delete [] each_stack_idx;
}

void stack_w_single_array::push(int stack_num, int value)
{
  each_stack_idx[stack_num]++;
  stack_array[idx_of_top(stack_num)] = value; 
}

int stack_w_single_array::pop(int stack_num)
{
  int return_value = -1;
  int top_idx = idx_of_top(stack_num);

  if (is_empty(stack_num)) {
    cout << "stack: " << stack_num << " is empty!" << endl;
  } else {
    return_value = stack_array[top_idx];
    stack_array[top_idx] = 0;
    each_stack_idx[stack_num]--;
  }

  return return_value;
}

int stack_w_single_array::top(int stack_num)
{
  if (is_empty(stack_num)) {
    cout << "stack: " << stack_num << " is empty!" << endl;
    return -1;
  } else {
    return stack_array[idx_of_top(stack_num)];
  }
}

bool stack_w_single_array::is_empty(int stack_num)
{
  if (each_stack_idx[stack_num] == 0)
    return true;
  else
    return false;
}

int stack_w_single_array::idx_of_top(int stack_num)
{
  int start_idx = stack_num * stack_capacity;
  int idx_in_stack = each_stack_idx[stack_num];

  return (start_idx + idx_in_stack - 1);
}

int main()
{
  stack_w_single_array test_stack(3);

  for (int i=0; i < 3; i++) {
    test_stack.push(0,i);
    test_stack.push(1,3 + i);
    test_stack.push(2,6 + i);
  }

  for (int i=0; i < 3; i++) {
    cout << "top in stack(" << i << "): " << test_stack.top(i) << endl;
  }

  for (int i=0; i < 3; i++) {
    cout << "pop in stack(" << i << "): " << test_stack.pop(i) << endl;
  }

  cout << "after pop:" << endl;
  for (int i=0; i < 3; i++) {
    cout << "top in stack(" << i << "): " << test_stack.top(i) << endl;
  }

  return 0;
}
