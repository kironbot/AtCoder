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

int main() {
    string s, t;
    cin >> s >> t;

    bool res=false;
    for(int i=0; i<s.size(); i++){
        string u = s.substr(i, s.size() - i) + s.substr(0, i);
        if(u == t) {
            res = true;
            break;
        }
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
}
