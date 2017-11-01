# Basic Graph Algorithms

### Representations

Adjacency matrix

```c++
vvi AdjMatrix(V, vi(V));
AdjMatrix[s][t] = 1; // ->
AdjMatrix[t][s] = 1; // <-
```

Adjacency list

```c++
vvii AdjList(V);
AdjList[s].push_back(ii(w1, t)); // ->
AdjList[t].push_back(ii(w2, s)); // <-
```

Edge list

```c++
vii EdgeList;
EdgeList.push_back(ii(w, ii(s, t)); // ->
EdgeList.push_back(ii(w, ii(t, s)); // <-
```



### DFS using recursion

```c++
const int UNVISITED = -1;
const int VISITED = 1;
vvii AdjList(V);
vi color(V, UNVISITED);

void dfs(int u) {
  color[u] = VISITED;
  for (int j = 0; j < AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (color[v.second] == UNVISITED)
      dfs(v.second);
  }
}
```

### DFS using stack

```c++
const int UNVISITED = -1;
const int VISITED = 1;
vvii AdjList(V);
vi color(V, UNVISITED);
stack<int> s;

void dfs(int u) {
  color[u] = VISITED; s.push(u);
  while (!s.empty()) {
    bool adj = false;
    for (int j = 0; j < AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (color[v.second] == UNVISITED) {
        color[v.second] = VISITED; s.push(v.second);
        adj = true; break;
      }
    }
    if (!adj) s.pop();
  }
}
```

### BFS

```c++
const int UNVISITED = -1;
const int VISITED = 1;
vvii AdjList(V);
vi color(V, UNVISITED);
queue<int> q;

void bfs(int u) {
  color[u] = VISITED; q.push(u);
  while (!q.empty()) {
    int front = q.front(); q.pop();
    for (int j = 0; j < AdjList[front].size(); j++) {
      ii v = AdjList[front][j];
      if (color[v.second] == UNVISITED) {
        color[v.second] = VISITED; q.push(v.second);
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
    dfs(i);
    numCC++;
  }
}
```

### Topological Sort (Directed Acyclic Graph)

```c++
vi ts;
void dfsm(int u) {
  color[u] = VISITED;
  for (int j = 0; j < AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (color[v.second] == UNVISITED) {
      color[v.second] = VISITED;
      dfs(v.second);
    }
  }
  ts.push_back(u);
}

for (int i = 0; i < 4; i++)
  if (color[i] == UNVISITED)
    dfs(i);

reverse(all(ts));
```

