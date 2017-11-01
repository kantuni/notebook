# Basic Graph Algorithms

### Representation

```c++
#define UNVISITED -1
#define VISITED 1

struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
  };
  
  vector<Edge> edges;
  vvi cnn;
  vi color;
  
  Graph(int n) {
    cnn.assign(n, vi());
    color.assign(n, UNVISITED);
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
    // cnn[t].push_back(edges.size());
    // edges.push_back({t, s, w});
  }
};

int main() {
  Graph g(4);
  g.addEdge(0, 1, 1);
  g.addEdge(0, 2, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 0, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 3, 1);
  return 0;
}
```

### DFS using recursion

```c++
void Graph::DFS(int u) {
  color[u] = VISITED;
  for (auto ie: cnn[u]) {
    int v = edges[ie].to;
    if (color[v] == UNVISITED)
      DFS(v);
  }
}
```

### DFS using stack

```c++
void Graph::DFS(int u) {
  stack<int> s;
  color[u] = VISITED;
  s.push(u);

  while (!s.empty()) {
    bool found = false;
    for (auto ie: cnn[s.top()]) {
      int v = edges[ie].to;
      if (color[v] == UNVISITED) {
        found = true;
        color[v] = VISITED;
        s.push(v);
        break;
      }
    }
    if (!found) {
      s.pop();
    }
  }
}
```

### BFS

```c++
void Graph::BFS(int u) {
  queue<int> q;
  color[u] = VISITED;
  q.push(u);

  while (!q.empty()) {
    int front = q.front(); q.pop();
    for (auto ie: cnn[front]) {
      int v = edges[ie].to;
      if (color[v] == UNVISITED) {
        color[v] = VISITED;
        q.push(v);
      }
    }
  }
}
```

### Finding Connected Components (Undirected Graph)

```c++
int numCC = 0;
for (int i = 0; i < V; i++) {
  if (color[i] == UNVISITED) {
    g.DFS(i);
    numCC++;
  }
}
```

### Topological Sort (Directed Acyclic Graph)

```c++
void Graph::DFSM(int u) {
  color[u] = VISITED;
  for (auto ie: cnn[u]) {
    int v = edges[ie].to;
    if (color[v] == UNVISITED)
      DFSM(v);
  }
  ts.push_back(u);
}

vi Graph::TS() {
  for (int i = 0; i < cnn.size(); i++)
    if (color[i] == UNVISITED)
      DFSM(i);
  reverse(ts.begin(), ts.end());
  return ts;
}
```



# Minimum Spanning Trees

### Prim's Algorithm

```c++
struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (const Edge &a) const {
      // hack: invert sign
      return weight >= a.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  // MST
  priority_queue<Edge> pq;
  vi taken;
  
  Graph(int n) {
    cnn.assign(n, vi());
    taken.assign(n, 0);
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
    cnn[t].push_back(edges.size());
    edges.push_back({t, s, w});
  }
  
  void process(int u) {
    taken[u] = 1;
    for (auto ie: cnn[u]) {
      Edge e = edges[ie];
      if (!taken[e.to]) {
        pq.push(e);
      }
    }
  }
  
  int Prim() {
    int mstc = 0;
    process(0);
    while (!pq.empty()) {
      Edge top = pq.top(); pq.pop();
      if (!taken[top.to]) {
        process(top.to);
        mstc += top.weight;
      }
    }
    return mstc;
  }
};
```