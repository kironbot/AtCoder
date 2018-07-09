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
    ll N, M;
    cin >> N >> M;

    ll res=0;
    if (N == 1 && M == 1) res = 1;
    else if (N == 1 && M >= 2) res = M-2;
    else if (N >= 2 && M == 1) res = N-2;
    else res = (N-2) * (M-2);

    cout << res << endl;
}
