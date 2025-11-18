class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while(i < n)
        {
            if(bits[i] == 1)
            {
                i = i + 2;
                if(i == n)
                {
                    return false;
                }
            }
            else
            {
                i++;
            }
        }
        return true;
    }
};