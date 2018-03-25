#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class graph
{
public:
  graph(int num_of_vertices);
  virtual ~graph();
  void add_edge(int node_x, int node_y);
  bool is_route(int node_x, int node_y);

private:
  int num_of_vertices;
  vector<int> *children;
};

graph::graph(int num_of_vertices)
{
  this->num_of_vertices = num_of_vertices;
  this->children = new vector<int>[num_of_vertices];
}

graph::~graph()
{
  delete [] children;
}

void graph::add_edge(int node_x, int node_y)
{
  children[node_x].push_back(node_y);
}

// BFS based ib queue
bool graph::is_route(int node_x, int node_y)
{
  vector<bool> visited(num_of_vertices, false);
  queue<int> visit_q;

  visit_q.push(node_x);

  while(!visit_q.empty()) {
    int cur_node = visit_q.front();

    if (cur_node == node_y) {
      return true;
    } else {

      for (int i = 0; i < children[cur_node].size(); i++) {

        if (visited[children[cur_node][i]] == false) {
          visit_q.push(children[cur_node][i]);
        }
      }
    }

    visited[cur_node] = true;
    visit_q.pop();
  }

  return false;
}

int main() {

  cout << "implementation of 4_1.cpp" << endl;

  graph test_graph(7);
  test_graph.add_edge(0, 1);
  test_graph.add_edge(0, 2);
  test_graph.add_edge(0, 3);
  test_graph.add_edge(2, 6);
  test_graph.add_edge(3, 4);
  test_graph.add_edge(4, 5);
  
  cout << test_graph.is_route(4, 5) << endl; // 1
  cout << test_graph.is_route(2, 5) << endl; // 0

  return 0;
}
