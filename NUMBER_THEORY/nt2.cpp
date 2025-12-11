#include <iostream>
#include <vector>
using ll = long long;
void solve() {
    int n; std::cin >> n;
    std::vector<bool> primes(n+1, true);
    primes[0] = false; primes[1] = false;
    std::vector<int> prime_num;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) primes[j] = false;
        }
    }
    prime_num.push_back(2);
    for (int i = 3; i <= n; i+=2) if (primes[i]) prime_num.push_back(i);

    ll cnt = 0;
    for (ll a = 1; a < n; a++) {
        if (a * 2 > n) break;
        else {
            for (int prime : prime_num) {
                if (a * prime > n) break;
                else cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}