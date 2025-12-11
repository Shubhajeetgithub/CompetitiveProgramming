#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
int N = 1e6 + 10;
std::vector<bool> isPrime(N, true);
// 1 * p * p <= 10^12 -> p <= 10^6
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}; 
// 2 * 3 * ... * 53 > 10^18

using ll = long long;
void solve() {
    ll x; std::cin >> x;
    ll a = sqrt(x);
    if (a * a == x && isPrime[a]) {
        std::cout << "YES\n";
        return;
    }
    std::cout << "NO\n";
    
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)  {
        if (isPrime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
   /*
    for (int i = 2; i < N; i++) {
        if (!pf[i].empty()) continue;
        for (int j = i; j < N; j += i) {
            pf[j].push_back(i);
        }
    }
    */
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}