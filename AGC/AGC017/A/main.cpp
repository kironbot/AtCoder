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
    int n, p;
    cin >> n >> p;
    int cntodd = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 1) cntodd++;
    } 
    if (cntodd > 0) cout << (ll)pow(2, n-1) << endl;
    else if (p % 2 == 0) cout << (ll)pow(2, n) << endl;
    else cout << 0 << endl;
}
