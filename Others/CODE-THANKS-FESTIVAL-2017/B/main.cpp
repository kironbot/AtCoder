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
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s.substr(i, n-i) == t.substr(0, n-i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}
