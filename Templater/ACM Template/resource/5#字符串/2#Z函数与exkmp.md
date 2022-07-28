## Z函数

字符串 $s[0\cdots n]$﻿ 的 Z 函数 $z[i]$﻿ 被定义为字符串 $s[0\cdots n]$﻿ 和 $s[i\cdots n]$﻿ 的 $LCP$

### 线性求解



## EXKMP

```cpp
struct EXKMP {
    int z[40004000]; // 这里大小开到 n+m+1 就可以
    int mx_n;
    void init(char *s, int n) {
        mx_n = n;
        int l = 0, r = 0;
        z[0] = n;
        for(int i=1; i<n; i++) {
            if(i <= r && z[i-l] < r-i+1) { z[i] = z[i-l]; }
            else {
                z[i] = max(0, r-i+1);
                while(i+z[i]<n && s[z[i]] == s[i+z[i]]) { ++z[i]; }
            }
            if(i+z[i]-1 > r) { r = i + z[i] - 1; l = i; }
        }
    }
    /*
        pattern + '#' + target
    */
    void init_kmp(char target[], char pattern[], char data[]) {
        int n1 = strlen(target), n2 = strlen(pattern);
        strcpy(data, pattern);
        strcpy(data+n2+1, target);
        data[n2] = '#';
        init(data, n1+n2+1);
    }
    int fd_nx(int i, int le) {
        while(i < mx_n) { if(z[i] == le) { return i; } ++i; }
        return -1;
    }
    vector<int> fd_all(int s, int le) {
        static vector<int> q;
        while(true) { s = fd_nx(s, le); if(s == -1) { break; } q.push_back(s); ++s;}
        return q;
    }
};
```

