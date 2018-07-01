#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;
    
    int a=-1, b=-1, c=-1;
    for (int i=0; i<=N; ++i) {
        for (int j=0; j<=N-i; ++j){
            int total = 10000*i + 5000*j + 1000*(N-i-j);
            if (total == Y) {
                a = i;
                b = j;
                c = N-i-j;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
}
