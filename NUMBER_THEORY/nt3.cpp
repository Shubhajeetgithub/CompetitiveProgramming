#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
int N = 2e5 + 10;
// std::vector<bool> isPrime(N, true);
// std::vector<int> hp(N);
std::vector<std::vector<int>> pf(N);
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}; 
// 2 * 3 * ... * 53 > 10^18

void solve() {
    int n; std::cin >> n;
    std::map<int, int> hsh;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        hsh[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
    }
    std::map<int, int> distinct_prime_cnt;
    for (auto& [i, freq] : hsh) {
        if (i > 1 && freq > 0) {
            for (int x : pf[i]) {
                distinct_prime_cnt[x] += hsh[i];
                if (distinct_prime_cnt[x] >= 2) {
                    std::cout << 0 << std::endl;
                    return;
                }
            }
        }
    }
    for (auto& [i, freq] : hsh) {
        if (freq > 0) {
            for (int x : pf[i+1]) {
                if (distinct_prime_cnt[x] >= 1) {
                    std::cout << 1 << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << 2 << std::endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)  {
        if (isPrime[i]) {
            hp[i] = i;
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
    */
    for (int i = 2; i < N; i++) {
        if (!pf[i].empty()) continue;
        for (int j = i; j < N; j += i) {
            pf[j].push_back(i);
        }
    }
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}