#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;
   
    long long A=X, ans=0;
    while (A <= Y){
        A *= 2;
        ans++;
    }
    
    cout << ans << endl;
}
