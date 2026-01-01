#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        std::vector<ll> a(n+1), b(n+1), pref(n+1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        for (int i = 1; i <= n; i++) {
            std::cin >> b[i];
            pref[i] = pref[i-1] + b[i];
        }
        std::vector<ll> complete(n+2, 0), partial(n+2, 0), total(n+1, 0);
        for (int i = 1; i <= n; i++) {
            ll target = pref[i - 1] + a[i];
            auto it = std::lower_bound(pref.begin() + i, pref.end(), target);
            int j = it - pref.begin();
            int finish_full = std::min(j - 1, n);
            if (finish_full >= i) {
                complete[finish_full]++;
                complete[i - 1]--;
            }
            if (j <= n) {
                ll covered = pref[j - 1] - pref[i - 1];
                ll remainder = a[i] - covered;
                partial[j] += remainder;
            }
        }
        for (int i = n-1; i >= 1; i--) complete[i] += complete[i+1];
        for (int i = 1; i <= n; i++) total[i] = complete[i] * b[i] + partial[i];
        for (int i = 1; i <= n; i++) std::cout << total[i] << " ";
        std::cout << '\n';
    }
    return 0;
}