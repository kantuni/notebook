# Mathematics

Euclidean Algorithm

```c++
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
```


Sieve of Eratosthenes

```c++
vector<int> sieve(int n) {
  vector<int> p(n, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (p[i] == 1) {
      for (int j = 0; i * i + i * j <= n; j++) {
        p[i * i + i * j] = 0;
      }
    }
  }
  return p;
}
```
