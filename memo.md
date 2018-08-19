# C++ 備忘録

## マップ
* マップ宣言
```c++:
#include <map>
map<int, int> mp;
for (auto p: mp){
    f = p.first;
    s = p.second;
}
```

## ビット演算
* 2^n 全探索
```c++:
for(int mask = 0; mask < (1 << n); mask++){
    for(int i = 0; i < n; i++) {
        if(mask >> i & 1) {
            // i ビット目が1の場合の処理
        }
    }
}
```

## 文字列

* 結合 
```c++:
str = str1 + str2;
```

* 抽出
```c++:
// i番目からj文字抽出
s = string.substr(i, j);
```

* ループ
```c++:
string s = "abc";
for (char c: s) cout << c; // a b c d
```

* 文字列 → 数値
```c++:
string s = "123";
int n = stoi(s); // 123
```

* 数値 → 文字列
```c++:
int n = 123;
string s = to_string(n); // "123"
```


## 数学

* Log
```c++:
double m;
m = log2(16); // 4
```

* 累乗
```c++:
double m;
m = pow(2, 3); // 8
```
