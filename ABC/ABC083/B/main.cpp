#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int res = 0;
    for (int i=1; i<=N; i++){
        int sum = 0;
        int x = i;
        while (x != 0){
           sum += x % 10;
           x /= 10;
        }
        if ((A <= sum) and (sum <= B) ) res += i;
    }
    cout << res << endl;
}
