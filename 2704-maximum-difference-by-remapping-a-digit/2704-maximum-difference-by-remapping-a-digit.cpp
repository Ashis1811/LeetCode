class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string mini = s;
        char ch0 = mini[0];
        for(char& it : mini)
        {
            if(it == ch0)  it = '0';
        }
        int minVal = stoi(mini);

        string maxi = s;
        for(char& it : maxi)
        {
            if(it != '9')
            {
                char char9 = it;
                for(char& it2 : maxi)
                    if(it2 == char9) it2 = '9';
                    break;        
            }            
        }
        int maxVal = stoi(maxi);
        return maxVal - minVal;
        
    }
};