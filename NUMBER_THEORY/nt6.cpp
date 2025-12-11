#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
int N = 5e6 + 10;
std::vector<int> isPrime(N, true);
std::vector<int> hp(N);
std::vector<int> prime_fac_cnt(N, 0);
std::vector<int> pref(N);
using ll = long long;
void solve() {
    int a, b; std::cin >> a >> b;
    std::cout << pref[a] - pref[b] << std::endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i < N; i++)  {
        if (isPrime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
    prime_fac_cnt[1] = 0;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) prime_fac_cnt[i] = 1;
        else prime_fac_cnt[i] = 1 + prime_fac_cnt[i / hp[i]];
    }
    pref[0] = 0;
    for (int i = 1; i < N; i++) pref[i] = pref[i-1] + prime_fac_cnt[i];
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}