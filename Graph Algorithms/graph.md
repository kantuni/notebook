# Graph Algorithms

### Representation

```c++
struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  Graph(int n) {
    cnn.assign(n, vi());
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
    // cnn[t].push_back(edges.size());
    // edges.push_back({t, s, w});
  }
};

int main() {
  Graph G(4);
  G.addEdge(0, 1, 1);
  G.addEdge(0, 2, 1);
  G.addEdge(1, 2, 1);
  G.addEdge(2, 0, 1);
  G.addEdge(2, 3, 1);
  G.addEdge(3, 3, 1);
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
    G.DFS(i);
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



## Minimum Spanning Tree

### Prim's Algorithm

```c++
struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (Edge e) const {
      // hack: invert sign
      return weight > e.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
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
  
  // MST
  priority_queue<Edge> pq;
  vi taken;
  
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

### Kruskal's Algorithm

```c++
// requires Union Find
struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (Edge e) const {
      return weight < e.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  Graph(int n) {
    cnn.assign(n, vi());
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
    cnn[t].push_back(edges.size());
    edges.push_back({t, s, w});
  }
  
  int Kruskal() {
    int mstc = 0;
    UnionFind ufds(cnn.size());
    vector<Edge> all(edges);
    sort(all.begin(), all.end());
    for (auto e: all) {
      if (!ufds.same(e.from, e.to)) {
        mstc += e.weight;
        ufds.merge(e.from, e.to);
      }
    }
    return mstc;
  }
};
```

## SSSP on Weighted Graph

### Dijkstra's Algorithm

```c++
struct Graph {
  struct Edge {
    int from;
    int to;
    int weight;
    
    bool operator < (Edge e) const {
      // hack: invert sign
      return weight > e.weight;
    }
  };
  
  vector<Edge> edges;
  vvi cnn;
  
  // Dijkstra
  vi dist;
  
  Graph(int n) {
    cnn.assign(n, vi());
    dist.assign(n, INF);
  }
  
  void addEdge(int s, int t, int w) {
    cnn[s].push_back(edges.size());
    edges.push_back({s, t, w});
  }
  
  void Dijkstra(int s) {
    priority_queue<Edge> pq;
    dist[s] = 0;
    pq.push({s, s, 0});
    
    while (!pq.empty()) {
      Edge top = pq.top(); pq.pop();
      int u = top.to;
      int d = top.weight;
      
      if (d > dist[u]) continue;
      for (auto ie: cnn[u]) {
        int v = edges[ie].to;
        int w = edges[ie].weight;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push({u, v, dist[v]});
        }
      }
    }
  }
};
```

### Bellman-Ford's Algorithm

```c++
void BellmanFord(int s) {
  dist[s] = 0;
  for (int i = 0; i < cnn.size() - 1; i++) {
    for (int j = 0; j < cnn.size(); j++) {
      for (auto ie: cnn[j]) {
        int v = edges[ie].to;
        dist[v] = min(dist[v], dist[j] + edges[ie].weight);
      }
    }
  }
}
```

