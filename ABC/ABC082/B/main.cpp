#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    
    if (s < t) cout << "Yes" << endl;
    else cout << "No" << endl;
}
