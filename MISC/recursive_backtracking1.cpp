#include <iostream>
using ll = long long;

ll fact(int k) {
    ll ans = 1LL;
    for (int i = 2; i <= k; i++) ans *= i;
    return ans;
}

void solve(ll n, int k, ll temp, int cnt_fac, int& min_steps) {
    if (k > 14) {
        min_steps = std::min(min_steps, cnt_fac + __builtin_popcountll(n - temp));
        return;
    }

    // exclude
    solve(n, k+1, temp, cnt_fac, min_steps);

    // include
    ll f = fact(k);
    if (n >= temp + f) solve(n, k+1, temp + f, cnt_fac + 1, min_steps);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        ll n; std::cin >> n;
        int min_steps = INT_MAX;
        solve(n, 3, 0, 0, min_steps);
        std::cout << min_steps << std::endl;
    }
    return 0;
}