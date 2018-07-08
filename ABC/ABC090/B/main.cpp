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
    int A, B;
    cin >> A >> B;
    
    int res=0;
    for (int i=A; i<=B; i++) {
        string s = to_string(i);
        bool flg=true;
        for (int j=0; j<s.size()/2; j++) {
            if (s[j] == s[s.size()-j-1]) flg = true && flg;
            else flg = false && flg;
        }
        if (flg == true) res++;
    }
    
    cout << res << endl;
}
