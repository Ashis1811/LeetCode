class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    long long helper(string& word, int k)
    {
        int left = 0;
        int consonant = 0;
        long long ans = 0;
        unordered_map<char, int> vowelFreq;  

        for (int right = 0; right < word.size(); right++) {
            char ch = word[right];

            
            if (isVowel(ch)) {
                vowelFreq[ch]++;
            } else {
                consonant++;
            }

            while (vowelFreq.size() == 5 && consonant >= k) {
                ans += word.size() - right;
                if (isVowel(word[left])) {
                    vowelFreq[word[left]]--;
                    if (vowelFreq[word[left]] == 0) {
                        vowelFreq.erase(word[left]);
                    }
                } else {
                    consonant--;  // Reduce consonant count
                }
                left++;  // Move left pointer
            }

            }
            return ans;
    }
    long long countOfSubstrings(string word, int k) {
        
        return helper(word, k) - helper(word, k + 1);
    }
};