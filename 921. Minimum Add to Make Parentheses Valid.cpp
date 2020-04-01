class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> c;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(') c.push(S[i]);
            else if(S[i]==')')
            {
                if(!c.empty() && c.top()=='(')
                {
                    c.pop();
                }
                else c.push(')');
            }
        }
    }
        return c.size();
    }
};
