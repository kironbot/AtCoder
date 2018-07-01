#include <iostream>
using namespace std;

int main() {
    int N;
    int A[2][110];
    cin >> N;
    for (int i=0; i<2; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }
    
    int res=0;
    for (int k=0; k<N; k++){
        int tmp=0;
        for (int i=0; i<N; i++) {
            if (i <= k) tmp += A[0][i];
            if (k <= i) tmp += A[1][i];
        }
        res = max(res, tmp);
    }
    
    cout << res << endl;

}

