# Mathematics

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
