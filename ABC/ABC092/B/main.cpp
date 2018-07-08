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
    int N, D, X;
    int A[110];
    cin >> N >> D >> X;
    for (int i=0; i<N; i++) cin >> A[i];

    ll res=X;
    for (int i=0; i<N; i++){
        res += (D - 1) / A[i] + 1;
    }
    cout << res << endl;
}
