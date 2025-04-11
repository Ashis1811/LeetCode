class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++)
        {
            string st = to_string(i);
            int len = st.size();
            if(len % 2 == 0 && accumulate(st.begin(), st.begin() + len / 2, 0) == 
            accumulate(st.begin() + len / 2, st.end(), 0))
            {
                count++;
            }         
        }
        return count;
    }
};