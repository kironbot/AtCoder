#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> vx(n), vy(m);
    for (int i = 0; i < n; i++) cin >> vx[i];
    for (int i = 0; i < m; i++) cin >> vy[i];

    int mx = x, my = y;
    for (int i = 0; i < n; i++) mx = max(mx, vx[i]);
    for (int i = 0; i < m; i++) my = min(my, vy[i]);
    if(mx < my) cout << "No War" << endl;
    else cout << "War" << endl;
}