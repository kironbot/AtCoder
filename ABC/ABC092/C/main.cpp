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
    int N;
    cin >> N;
    ll A[110000], B[110000];
    for (int i=0; i<=N; i++) {
        if (i==0) A[i] = 0;
        else cin >> A[i];
    }
    
    ll S=0;
    for (int i=0; i<=N; i++) {
        if (i == N) B[i] = A[i] - A[0];
        else B[i] = A[i] - A[i+1];
        S += abs(B[i]);
    }

    for (int i=1; i<=N; i++) {
        ll res=S;
        res += abs(A[i-1]-A[i+1]) - abs(B[i-1]) - abs(B[i]);
        cout << res << endl;
    }

}
