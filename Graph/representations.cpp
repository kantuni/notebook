#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main() {
  const N = 5;
  
  // adjacency matrix
  vvi AM(N, vi(N, 0));
  AM[s - 1][t - 1] = 1; // ->
  AM[t - 1][s - 1] = 1; // <-
  
  // adjacency list
  vvii AL(N);
  AL[s - 1].push_back(make_pair(w, t - 1)); // ->
  AL[t - 1].push_back(make_pair(w, s - 1)); // <-
  
  // edge list
  vii EL;
  EL.push_back(make_pair(w, make_pair(s - 1, t - 1)); // ->
  EL.push_back(make_pair(w, make_pair(t - 1, s - 1)); // <-
  
  return 0;
}
