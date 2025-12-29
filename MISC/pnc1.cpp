#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
const int M = 998244353;

ll modPow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return modPow(x, M - 2);    
}

ll divide(ll x, ll y) {
    return (x * inv(y)) % M;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll ans = 1;
    for (int i = r; i >= 1; i--) {
        ans = (ans * divide(n + i - r, i)) % M;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    ll ans = nCr(n/3, n/6);
    for (int i = 0; i < n/3; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        if (a > b) std::swap(a, b);
        if (a > c) std::swap(a, c);
        if (b > c) std::swap(b, c);

        if (a == b && b == c) ans = (ans * 3) % M;
        else if (a == b) ans = (ans * 2) % M;
    }
    std::cout << ans << std::endl;
    return 0;
}