#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int M = max(max(A, B), C);
    int tmp = M;
    
    for (int i=0; i<K; i++) {
        M *= 2;
    }
    
    cout << M+A+B+C-tmp << endl;
}
