class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int limit = right + 1;
        vector<bool> isPrime(limit, true);

        //Checking prime numbers
        for(int i = 2; i*i <= right; i++)
        {
            if(isPrime[i])
            {
                for(int j = 2; i * j <= right; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }

        //Storing all prime numbers
        vector<int> prime;
        for(int i = max(2, left); i <= right; i++)
        {
            if(isPrime[i])
            {
                prime.push_back(i);
            }
        }

        if(prime.size() < 2) return {-1, -1};

    
        int maxi = INT_MAX;
        vector<int> ans = {-1, -1};
        //Storing the result with min difference
        for(int i = 1; i < prime.size(); i++)
        {
            int diff = prime[i] - prime[i - 1];
            if(diff < maxi)
            {
                maxi = diff;
                ans = {prime[i - 1], prime[i]};
            }
        }
        return ans;
    }
};