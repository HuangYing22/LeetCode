/* Count the number of prime numbers less than a non-negative number, n. */

// Time Limit Exceeded
/*
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> prime = {2};

        for(int i = 3; i < n; i ++) {
            bool tag = true;
            for(int j = 0; j < prime.size(); j ++) {
                if(i % prime[j] == 0) tag = false;
            }
            if(tag) prime.push_back(i);
        }
        return prime.size();
    }
}; */

// Time Limit Exceeded
/*
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> prime;
        
        for(int i = 2; i < n; i ++) {
            prime.push_back(i);
        }
        
        for(int i = 0; i < prime.size(); i ++) {
            for(int j = i + 1; j < prime.size(); j ++) {
                if(prime[j] % prime[i] == 0) {
                    prime.erase(prime.begin() + j);
                    j --;
                }
            }
        }
        
        return prime.size();
    }
}; */

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = false;
        isPrime[1] = false;
        int res = 0;
        
        for(int i = 2; i <n; i ++) {
            if(!isPrime[i]) continue;
            for(int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        
        for(int i = 0; i < n; i ++) {
            if(isPrime[i]) res ++;
        }
        
        return res;
    }
};
