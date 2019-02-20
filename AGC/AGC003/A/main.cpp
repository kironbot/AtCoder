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
    int cnt[4] = {};
    rep(i, s.size()) {
        if (s[i] == 'N') cnt[0]++;
        if (s[i] == 'W') cnt[1]++;
        if (s[i] == 'S') cnt[2]++;
        if (s[i] == 'E') cnt[3]++;
    }
    if ( ((cnt[0]==0 && cnt[2]==0) || (cnt[0]>0 && cnt[2]>0)) && ((cnt[1]==0 && cnt[3]==0) || (cnt[1]>0 && cnt[3]>0)) ) cout << "Yes\n";
    else cout << "No\n";
}