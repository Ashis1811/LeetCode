class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto curr : expression)
        {
            if(curr == ',' || curr == '(') continue;
            else if(curr == 't' || curr == 'f' || curr == '!' || curr == '&' || curr == '|')
            {
                st.push(curr);
            }
            else if(curr == ')')
            {
                bool hashTrue = false, hashFalse = true;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|')
                {
                    char value = st.top();
                    st.pop();
                    if(value == 't') hashTrue = true;
                    if(value == 'f') hashFalse = false;
                }
                    char op = st.top();
                    st.pop();
                    if(op == '!') st.push(hashTrue ? 'f' : 't');
                    else if(op == '&') st.push(hashFalse ? 't' : 'f');
                    else st.push(hashTrue ? 't' : 'f');              
            }
        }
        return st.top() == 't';
    }
};