# C++ 備忘録

## マップ
```c++:
#include <map>
map<int, int> mp;

for (auto p: mp){
    f = p.first;
    s = p.second;
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

