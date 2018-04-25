# Utilities

```c++
void fill (ForwardIterator first, ForwardIterator last, const T& val);
```

Assigns `val` to all the elements in the range `[first,last)`.

```c++
vector<int> v = {1, 2, 3, 4, 5};
fill(v.begin(), v.end(), 0); // [0, 0, 0, 0, 0]
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
vvi G(n, vi(m, 0));
```

Creates an `n x m` matrix with all 0s.



```c++
char a = '3';
int b = a - '0'; // b = 3
```

Converts `char` to `int`.



```c++
int a = 5;
char b = a + '0'; // b = '5'
```

Converts `int` to `char`.



```c++
vector<int> v = {3, 1, 2, 5, 4};
sort(v.begin(), v.end()); // [1, 2, 3, 4, 5]
sort(v.rbegin(), v.rend()); // [5, 4, 3, 2, 1]
```

Sorts the container in increasing / decreasing order.



```c++
iterator insert (iterator position, const value_type& val); // single element
void insert (iterator position, size_type n, const value_type& val); // fill
template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range
```

The vector is extended by inserting new elements before the element at the specified *position*, effectively increasing the container size by the number of elements inserted.

```c++
vector<int> v = {1, 2, 3};
v.insert(v.begin() + 1, 4); // [1, 4, 2, 3]

// use this for multiple inserts
vector<int> w = {4, 5};
v.insert(v.begin() + 1, w.begin(), w.end()); // [1, 4, 5, 2, 3]
```



```c++
iterator erase (iterator position);
iterator erase (iterator first, iterator last);
```

Removes from the vector either a single element (*position*) or a range of elements (`[first,last)`).

```c++
vector<int> v = {1, 2, 3, 4, 5};
v.erase(v.begin() + 1); // [1, 3, 4, 5]

// use this for multiple removals
v.erase(v.begin() + 1, v.begin() + 4); // [1, 5]
```



```c++
#include <algorithm>
vector<int> v = {1, 2, 3, 4, 5}; // must be sorted to get all permutations
do {
  // ...
} while (next_permutation(v.begin(), v.end()));
```

Rearranges the elements in the range `[first,last)` into the next *lexicographically greater* permutation.


```c++
const double EPS = 1e-7;
struct Point {
  double x, y;
  // bool operator < (const Point &p) const {
  bool operator < (Point p) const {
    // return true only for p1 < p2
    if (x < p.x - EPS) return true;
    if (x > p.x + EPS) return false;
    if (y < y.x - EPS) return true;
    if (y > y.x + EPS) return false;
    return false;
  }
}
```

Overload `<` operator to use `std::sort`.



```c++
cin >> N;
cin.ignore(); // ignores the rest of the line
while (getline(cin, line)) // ...
```

Don't forget to `cin.ignore()` before `getline()`.



```c++
#include <sstream>
string line, word;
istringsteam iss(line);
while (iss >> word) // ...
```

Simple string tokenizer (only space).



```c++
ios_base::sync_with_stdio(false);
```

Use this for large inputs. Don't use `cstdio` with it.



```c++
T hypot(T x, T y);
T hypot(T x, T y, T z);
```

Computes the square root of the sum of the squares of x and y (and z), without undue overflow or underflow at intermediate stages of the computation.



```c++
double a = 0.12345;
ostringstream stream;
stream << fixed << setprecision(3) << a;
string s = stream.str(); // "0.123"
```

Converts the floating point number to string with the given precision.



```c++
char c = 'a';
string cs = string(1, c); // "a"
```

Converts `char` to a `string`.



```c++
string s = "a,b,c";
stringstream ss(s);
vector<string> tokens;
string token;
while (getline(ss, token, ',')) {
  tokens.push_back(token); // ["a", "b", "c"]
}
```

This method is used to **split** a **string** into an array of substrings. (by a given delimiter)


```c++
#include <algorithm>

string s = "Abc";
transform(s.begin(), s.end(), s.begin(), ::tolower); // abc
transform(s.begin(), s.end(), s.begin(), ::toupper); // ABC
```

Converts a string to lowercase / uppercase letters.

```c++
#include <string>

string s = "hello, world";
s.find("el"); // 1
s.find("aaa"); // string::npos
```

Finds the first appereance of the given substring.

```c++
#include <string>

string s = "abc";
int pos = 2;
int count = 1;
s.replace(pos, count, "cd"); // abcd
```

Replaces the part of the string indicated by `[pos, pos + count)`.
