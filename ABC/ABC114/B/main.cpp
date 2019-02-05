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
    string s;
    cin >> s;
    int ans = 753;
    for(int i=0; i<s.length()-2; i++) {
        int tmp = stoi(s.substr(i, 3));
        ans = min(ans, abs(tmp - 753));
    } 
    cout << ans << endl;
}
