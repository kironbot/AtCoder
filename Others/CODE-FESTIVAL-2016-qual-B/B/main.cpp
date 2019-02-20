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
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int cnt1 = 0, cnt2 = 0;
    bool pass = false;
    for (int i = 0; i <s.size(); i++) {
        if (s[i] == 'a' && cnt1 < a + b) {
            pass = true;
            cnt1++;
        }
        else if (s[i] == 'b' && cnt1 < a + b && cnt2 < b) {
            pass = true;
            cnt1++;
            cnt2++;
        }
        else pass = false;

        if (pass) cout << "Yes\n";
        else cout << "No\n";
    }
}
