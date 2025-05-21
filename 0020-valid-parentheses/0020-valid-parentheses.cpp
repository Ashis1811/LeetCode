// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         int n = s.size();
//         for(int i = 0; i < n; i++)
//         {
//             if(st.empty())
//             {
//                 st.push(s[i]);
//             }
//             else if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))
//             {
//                 st.pop();
//             }
//             else
//             {
//                 st.push(s[i]);
//             }
//         }
//         if(st.empty()) 
//         {
//             return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char top = st.top();
                if((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};