#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s;
    int K;
    vector<string> subs;

    cin >> s >> K;

    for (int i=0; i<s.size(); i++) {
        for (int j=1; j<=K; j++) {
            subs.push_back(s.substr(i, j));
        }
    }

    sort(subs.begin(), subs.end());
    subs.erase(unique(subs.begin(), subs.end()), subs.end());

    cout << subs[K-1] << endl;

}
