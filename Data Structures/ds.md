# Data Structures

### Map

```c++
#include <map>
#include <utility> // std::pair
map<char, int> tree;
tree['a'] = 100;
tree.insert(pair<char, int>('b', 100));
tree.insert(make_pair('b', 100));
```



### Set

```c++
set<int> s = {1, 2};
vector<int> v = {4, 5};

s.insert(3); // {1, 2, 3}
s.insert(v.begin(), v.end()); // {1, 2, 3, 4, 5}

s.erase(1); // {2, 3, 4, 5}
s.erase(s.find(2), s.find(4)); // {4, 5}

s.count(element); // either 1 or 0
s.find(element); // either an iterator to that element or s.end()
```



### Priority Queue

```c++
priority_queue<int, vector<int>, greater<int> > pq; 
```

The third argument is comparator. Use `greater<int>` for min-heap.



### Union Find

```c++
struct UnionFind {
  vector<int> parent, rank;
  
  UnionFind(int n) {
    parent.assign(n, 0);
    rank.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);
  }
  
  int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[x] = y;
    }
    if (rank[x] == rank[y]) {
      rank[y]++;
    }
  }
};
```
