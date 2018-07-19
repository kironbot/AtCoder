#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;
    
    double s = sqrt(n);
    for(int i=3; i<=s; i+=2){
        if(n % i == 0) return false;
    }

    return true;
}


int main() {
    int N;
    cin >> N;
    
    int cnt=0, n=11;
    while(cnt < N){
        if(isPrime(n) && (n % 5 == 1)) {
            cout << n << " ";
            cnt++;
        }
        n+=2;
    }
    cout << endl;
}
