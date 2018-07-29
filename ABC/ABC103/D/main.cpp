#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    v.resize(m);

    for (int i=0; i<m; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    int res=0, endtime=0;
    for (int i=0; i<m; i++){
        if (v[i].first >= endtime) {
            endtime = v[i].second;
            res++;
        }
    }
    cout << res << endl;

}
