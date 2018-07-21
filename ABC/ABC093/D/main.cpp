#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ll Q, A, B;
    
    cin >> Q;
    while(Q--){
        cin >> A >> B;
        if (A > B) swap(A, B);
        ll res=2*(A-1);

        ll num=0;
        for(int i=29; i>=0; i--){
            num += 1<<i;
            if (A+num > B) {
                num -= 1<<i;
                continue;
            }
            int ng=0;
            for(int x=num/2-2; x<=num/2+2; x++){
                if(x <= 0 || x>num) continue;
                if((A+x)*(A+num-x)>=A*B) ng=1;
            }
            if(ng) num -= 1<<i;
        }
        res += num;
        cout << res << endl;
    }
}
