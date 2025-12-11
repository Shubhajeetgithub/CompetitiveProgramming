#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
int N = 2e5 + 10;
std::vector<bool> isPrime(N, true);
std::vector<int> hp(N);
std::vector<std::vector<int>> pf(N);
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}; 
// 2 * 3 * ... * 53 > 10^18

void solve() {
    int n; std::cin >> n;
    long long g = 0;
    for (int i = 0; i < n; i++) {
        long long x; std::cin >> x;
        g = std::__gcd(g, x);
    }
    for (int p : small_primes) {
        if (g % p != 0) {
            std::cout << p << std::endl;
            return;
        }
    }

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // isPrime[0] = isPrime[1] = false;
    // for (int i = 2; i < N; i++)  {
    //     if (isPrime[i]) {
    //         hp[i] = i;
    //         for (int j = 2 * i; j < N; j += i) {
    //             isPrime[j] = false;
    //             hp[j] = i;
    //         }
    //     }
    // }
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}