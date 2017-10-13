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

###  Recursive DFS

```c++
const int UNVISITED = -1;
const int VISITED = 1;
vvii AdjList;
vi color;

void dfs(int u) {
  color[u] = VISITED;
  for (int j = 0; j < AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (color[v.second] == UNVISITED) {
      dfs(v.second);
    }
  }
}
```

### DFS using Stack

```c++
const int UNVISITED = -1;
const int VISITED = 1;
vvii AdjList;
vi color;
stack<int> s;

void dfs(int u) {
  color[u] = VISITED;
  s.push(u);
  while (!s.empty()) {
    bool adj = false;
    for (int j = 0; j < AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (color[v.second] == UNVISITED) {
        color[v.second] = VISITED;
        s.push(v.second);
        adj = true;
        break;
      }
    }
    if (!adj) s.pop();
  }
}
```

