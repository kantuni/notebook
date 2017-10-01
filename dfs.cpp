#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vi color;

void rDFS(vvi &G, int u) {
  cout << u << " ";
  color[u] = 1;
  for (int v = 0; v < G[u].size(); v++) {
    /*
    // adjacency matrix
    if (G[u][v] != 0 && color[v] == 0) {
      rDFS(G, v);
    }
    */
    
    // adjacency list
    if (color[G[u][v]] == 0) {
      rDFS(G, G[u][v]);
    }
  }
}

void sDFS(vvi &G, int u) {
  stack<int> s;
  cout << u << " ";
  color[u] = 1;
  s.push(u);
  
  while (!s.empty()) {
    bool adj = false;
    for (int v = 0; v < G[s.top()].size(); v++) {
      /*
      // adjacency matrix
      if (G[s.top()][v] != 0 && color[v] == 0) {
        cout << v << " ";
        color[v] = 1;
        s.push(v);
        adj = true;
        break;
      }
      */
      
      // adjacency list
      if (color[G[s.top()][v]] == 0) {
        cout << G[s.top()][v] << " ";
        color[G[s.top()][v]] = 1;
        s.push(G[s.top()][v]);
        adj = true;
        break;
      }
    }
    
    if (!adj) {
      s.pop();
    }
  }
}

void BFS(vvi &G, int u) {
  queue<int> q;
  cout << u << " ";
  color[u] = 1;
  q.push(u);
  
  while (!q.empty()) {
    int front = q.front();
    for (int v = 0; v < G[front].size(); v++) {
      /*
      // adjacency matrix
      if (G[front][v] != 0 && color[v] == 0) {
        cout << v << " ";
        color[v] = 1;
        q.push(v);
      }
      */

      // adjacency list
      if (color[G[front][v]] == 0) {
        cout << G[front][v] << " ";
        color[G[front][v]] = 1;
        q.push(G[front][v]);
      }
    }
    q.pop();
  }
}

int main() {
  cin >> N;
  color.resize(N);
  
  /*
  vvi G(N, vi(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> G[i][j];
    }
  }
  */
  
  vvi G(N);
  G[0] = {1, 2, 3};
  G[1] = {3};
  G[2] = {3};
  G[3] = {4};
  
  rDFS(G, 0);
  fill(color.begin(), color.end(), 0);
  cout << "\n";
  
  sDFS(G, 0);
  fill(color.begin(), color.end(), 0);
  cout << "\n";
  
  BFS(G, 0);
  fill(color.begin(), color.end(), 0);
  cout << "\n";
  
  return 0;
}
