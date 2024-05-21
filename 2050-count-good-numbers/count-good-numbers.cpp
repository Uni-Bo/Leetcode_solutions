#define MOD 1000000007

class Solution {
public:
    // Function to perform modular exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // number of even-indexed positions
        long long odd = n / 2; // number of odd-indexed positions

        long long even_count = modPow(5, even, MOD); // 5 choices for even positions
        long long odd_count = modPow(4, odd, MOD); // 4 choices for odd positions

        return (even_count * odd_count) % MOD;
    }
};
