#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, Q;
  cin >> N >> M >> Q;
  int imos[N+1][N+1];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      imos[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    imos[l][r]++;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      imos[i][j+1] += imos[i][j];
    }
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = 0;
    for (int j = l; j <= r; j++) {
      ans += imos[j][r];
    }
    cout << ans << endl;
  }

}
