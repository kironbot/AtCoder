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
    if (s.substr(5, 2) == "01" || s.substr(5, 2) == "02"|| s.substr(5, 2) == "03" || s.substr(5, 2) == "04") cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}
