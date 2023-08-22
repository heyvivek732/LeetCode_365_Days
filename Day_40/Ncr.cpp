#include<bits/stdc++.h>
using namespace std;

// Math fact(n)/fact(n-r)*fact(r)
/*
    let n=6 r=4
    (6*5*4*3*2*1)/(2*1)*(4*3*2*1) => (6*5/2*1)

    Multiplicative Inverse


*/
int mod=1e9+7;
long long modInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) {
        x += m0;
    }

    return x;
}
    int nCr(int n, int r){
       long long res = 1;

      for (int i = 0; i < r; i++) {
        res = (res * (n - i)) % mod;
        res = (res * modInverse(i + 1, mod)) % mod;
    }

    return res;
    }