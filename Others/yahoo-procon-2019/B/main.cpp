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
    int cnt[4];
    fill(cnt, cnt+4, 0);
    for(int i=0; i<3; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
    }
    sort(cnt, cnt+4);
    if(cnt[0]==1 && cnt[1]==1 && cnt[2]==2 && cnt[3]==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
