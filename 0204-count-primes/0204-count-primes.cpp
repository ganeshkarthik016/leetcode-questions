class Solution {
public:
vector<int> primes(int n) {
    vector<bool> prime(n + 1, true);
    vector<int> ans;

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            ans.push_back(i);
        }
    }

    return ans;
}
    int countPrimes(int n) {
        return primes(n).size();
    }
};