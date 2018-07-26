# Mathematics

Euclidean Algorithm

```c++
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
```


Sieve of Eratosthenes

```c++
const int MAX = 1000000;
vector<bool> primes(MAX, 1);
primes[0] = primes[1] = 0;
for (int i = 2; i * i <= MAX; i++) {
  if (primes[i]) {
    for (int j = 0; i * i + j * i <= MAX; j++) {
      primes[i * i + j * i] = 0;
    }
  }
}
```


Operations on sets

```c++
#include <algorithm>
#define all(c) (c).begin(), (c).end()

vector<int> s1 = {1, 2, 3, 4, 5};
vector<int> s2 = {3, 4, 5, 6, 7};

vector<int> OR(s1.size() + s2.size());
vector<int> AND(s1.size() + s2.size());
vector<int> DIFF(s1.size() + s2.size());
vector<int> XOR(s1.size() + s2.size());

OR.resize(set_union(all(s1), all(s2), OR.begin()) - OR.begin());
AND.resize(set_intersection(all(s1), all(s2), AND.begin()) - AND.begin());
DIFF.resize(set_difference(all(s1), all(s2), DIFF.begin()) - DIFF.begin());
XOR.resize(set_symmetric_difference(all(s1), all(s2), XOR.begin()) - XOR.begin());
```
