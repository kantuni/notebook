# Mathematics

Sieve of Eratosthenes

```c++
const int P = 1000000;
vector<bool> primes(P, 1);
primes[0] = primes[1] = 0;
for (int i = 2; i * i <= P; i++) {
  if (primes[i]) {
    for (int j = 0; i * i + j * i <= P; j++) {
      primes[i * i + j * i] = 0;
    }
  }
}
```
