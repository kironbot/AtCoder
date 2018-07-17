#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool connect(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool isSame(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
    UnionFind uf = UnionFind(500000);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        uf.connect(t, i+200000);
    }
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        uf.connect(200000+t1-1, 200000+t2-1);
    }

    int res=0;
    for(int i=0; i<n; i++){
        if(uf.isSame(i+1, 200000+i)) res++;
    }
    cout << res << endl;
    return 0;
}
