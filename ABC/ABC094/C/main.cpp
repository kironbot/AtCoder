#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int X[N], Y[N];
    for (int i=0; i<N; i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    
    int A, B;
    sort(Y, Y+N);
    A = Y[N/2-1];
    B = Y[N/2];

    for (int i=0; i<N; i++){
        if (X[i] <= A) cout << B << endl;
        else cout << A << endl;
    }


}
