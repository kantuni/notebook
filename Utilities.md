# Utilities

```c++
void fill (ForwardIterator first, ForwardIterator last, const T& val);
```

Assigns `val` to all the elements in the range `[first,last)`.

```c++
vector<int> a = {1, 2, 3, 4, 5};
fill(a.begin(), a.end(), 0); // [0, 0, 0, 0, 0]
```



C++11 `to_string()` polyfill 

```c++
#include <sstream>
template <typename T>
string to_string(T n) {
  ostringstream oss;
  oss << n;
  return oss.str();
}
```



```c++
string substr (size_t pos = 0, size_t len = npos) const;
```

The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).

```c++
string a = "aabbcc";
string b = a.substr(0, 3); // aab
```



```c++
void resize (size_t n, char c);
```

Resizes the string to a length of *n* characters.

If *n* is smaller than the current string length, the current value is shortened to its first *n* character, removing the characters beyond the *n*th.

If *n* is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of *n*. If *c* is specified, the new elements are initialized as copies of *c*, otherwise, they are *value-initialized characters* (null characters).

```c++
string a = "aabbcc";
a.resize(3); // aab
a.resize(4, 'a'); // aaba
```



```c++
int a[2][2] = {{1, 2}, {3, 4}};
```

Declares and initializes a 2D array.



```c++
int islower (int c);
```

Checks whether *c* is a lowercase letter.



```c++
pair<T1,T2> make_pair (T1 x, T2 y);
```

Constructs a pair object with its first element set to x and its second element set to y.

```c++
#include <utility> // std::pair
pair<int, int> foo;
foo = make_pair(10, 20);
foo.first = 1;
foo.second = 2;
```



```c++
void reverse (BidirectionalIterator first, BidirectionalIterator last);
```

Reverses the order of the elements in the range `[first,last)`.

``` c++
#include <algorithm> // std::reverse
string a = "123abc";
reverse(a.begin(), a.end()); // a = cba321
```



```c++
#include <vector>
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi A(n, vi(m, 0));
```

Creates an `n x m` matrix with all 0s.



```c++
char a = '3';
int b = a - '0'; // b = 3
```

Converts `char` to `int`



```c++
vector<int> a = {3, 1, 2, 5, 4};
sort(a.begin(), a.end()); // [1, 2, 3, 4, 5]
sort(a.rbegin(), a.rend()); // [5, 4, 3, 2, 1]
```

Sorts the container in increasing / decreasing order.



```c++
iterator insert (iterator position, const value_type& val); // single element
void insert (iterator position, size_type n, const value_type& val); // fill
template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range
```

The vector is extended by inserting new elements before the element at the specified *position*, effectively increasing the container size by the number of elements inserted.

```c++
vector<int> a = {1, 2, 3};
a.insert(1, 4); // [1, 4, 2, 3]

// use this for multiple inserts
vector<int> b = {4, 5};
a.insert(1, b.begin(), b.end()); // [1, 4, 5, 2, 3]
```



