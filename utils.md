# Utils

```c++
void fill (ForwardIterator first, ForwardIterator last, const T& val);
```

Assigns `val` to all the elements in the range `[first,last)`.

```c++
vector<int> a = {1, 2, 3, 4, 5};
fill(a.begin(), a.end(), 0); // [0, 0, 0, 0, 0]
```

---

C++11 `to_string()` polyfill 

```c++
template <typename T>
string to_string(T n) {
  ostringstream oss;
  oss << n;
  return oss.str();
}
```

---

```c++
string substr (size_t pos = 0, size_t len = npos) const;
```

The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).

```c++
string a = "aabbcc";
string b = a.substr(0, 3); // aab
```

---

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

---

```c++
int a[2][2] = {{1, 2}, {3, 4}};
```

