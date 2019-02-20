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
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    for(ll n = 0; n <= N; n++) {
        for (ll m = 0; m <= M; m++) {
            if (n*M + m*N - 2*n*m == K) {
                cout << "Yes\n" ;
                return 0;
            }
        }
    }
    cout << "No\n";
}
