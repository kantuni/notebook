# Data Structures

Map

```c++
#include <map>
#include <utility> // std::pair
map<char, int> tree;
tree['a'] = 100;
// tree.insert(pair<char, int>('a', 100));
// tree.insert(make_pair('a', 100));
```



Set

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
