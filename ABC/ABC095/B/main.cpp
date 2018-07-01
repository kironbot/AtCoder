#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, X, mm=1000;
    int m[110];

    cin >> N >> X;
    int Y = X;
    for (int i=0; i<N; i++){
        cin >> m[i];
        Y -= m[i];
        mm = min (mm, m[i]);
    }

    int cnt = N + Y / mm;
    cout << cnt << endl;
    
}
