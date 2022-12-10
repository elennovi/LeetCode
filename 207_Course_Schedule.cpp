#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// visited vector:
// 0 -> not visited
// 1 -> touched
// 2 -> already visited

// returns true if there is any cycle
bool dfs(int curr, vector<vector<int>> const& adjacencyList, vector<int>& visited) {
  visited[curr] = 1; // we are visiting this node
  
  // loop through all adjacent nodes
  for(int next: adjacencyList[curr]){
    if (visited[next] == 1)  // there is a cycle
      return true;
    else if(visited[next] == 2 && dfs(next, adjacencyList, visited)) // if we found a cycle in the following nodes
      return true; 
  }

  visited[curr] = 2;  // already visited
  return false;
}

int main() {
  // test cases
  vector<vector<int>> adjacencyList{ {1},
                                     {0},
                                     {3},
                                     {}};
  // visited
  vector<int> visited(adjacencyList.size(), 0); // init to 0 (not visited)
  
  // show solution
  bool cycles = false;
  // loop through every connected components
  for (int i = 0; i < adjacencyList.size(); i++)
    if (!visited[i])
      cycles = cycles || dfs(i, adjacencyList, visited);
  
  // solution
  cout << cycles << endl;
  
  return 0;
}
