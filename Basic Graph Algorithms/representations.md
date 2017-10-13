# Basic Graph Algorithms

### Representations

Adjacency matrix

```c++
vvi Am(V, vi(V));
Am[s][t] = 1; // ->
Am[t][s] = 1; // <-
```

Adjacency list

```c++
vvii Al(V);
Al[s].push_back(ii(w1, t)); // ->
Al[t].push_back(ii(w2, s)); // <-
```

Edge list

```c++
vii El;
El.push_back(ii(w, ii(s, t)); // ->
El.push_back(ii(w, ii(t, s)); // <-
```

