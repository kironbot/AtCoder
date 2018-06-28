#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;
    
    int res = (N - 2) / (K - 1) + 1;
    
    cout << res << endl;
}
