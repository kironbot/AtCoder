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
    int n, m;
    cin >> n >> m;
    vector<int> x;
    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());    

    vector<int> diff;
    for (int i=0; i<m-1; i++) {
        diff.push_back(x[i+1] - x[i]);
    }
    sort(diff.begin(), diff.end());

    int ans = 0;   
    for (int i=0; i<m-n; i++) {
        ans += diff[i];
    }
    if (n >= m) cout << 0 << endl;
    else cout << ans << endl;
}
