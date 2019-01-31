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
typedef long long LL;

int main() {
    int n;
    string s, t;
    set<string> se;
    cin >> n;
    cin >> s;
    se.insert(s);
    bool flg = true;
    for (int i = 1; i < n; i++) {
        cin >> t;
        if (s[s.length()-1] != t[0]) {
            flg = false;
            break;
        }
        if (se.count(t)) {
            flg = false;
            break;
        }
        s = t;
        se.insert(t);
    }
    if (flg) puts("Yes");
    else puts("No");
}
