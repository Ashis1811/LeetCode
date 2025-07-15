class Solution {
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int consonant = 0, vowel = 0;
        for(auto it : word)
        {
            if(! isalnum(it))
            {
                return false;
            }
            if(isalpha(it))
            {
                if(isVowel(it))
                {
                    vowel++;
                }
                else
                {
                    consonant++;
                }
            }
        }
        return vowel > 0 && consonant > 0;
    }
};