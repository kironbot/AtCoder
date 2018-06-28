#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    int res=0;
    for (int i=1; i<N; i++){
        int cnt=0;
        for (char c='a'; c<='z'; c++) {
            bool left=false, right=false;

            for (int j=0; j<i; j++) {
                if (s[j] == c) left=true;
            }

            for (int j=i; j<N; j++) {
                if (s[j] == c) right=true;
            }
            
            if (left && right) cnt++;
        }
        res = max(res, cnt);
    }
    cout << res << endl;


}
