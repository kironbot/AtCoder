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
    int s, n=1000000;
    cin >> s;
    int ans, a=s;
    set<int> se;
    se.insert(s);
    for(int i=2; i<=n; i++) {
        if(a % 2 == 0) a = a / 2; 
        else a = 3 * a + 1;
        if(se.count(a) > 0) {
            ans = i;
            cout << ans << endl;
            return 0;
        }
        se.insert(a);
    }
}
