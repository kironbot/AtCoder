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
    int a;
    string s;
    cin >> a >> s;
    if (a == 0) {
        cout << "Yes\n";
        return 0;
    }
    rep(i, s.size()) {
        if (s[i] == '+') a++;
        else a--;
        if (a == 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
