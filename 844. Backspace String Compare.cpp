class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> p1,p2;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!='#')
            {
                p1.push(S[i]);
            }
            else
            {
                if(!p1.empty()) p1.pop();
            }
        }
        for(int i=0;i<T.length();i++)
        {
            if(T[i]!='#')
            {
                p2.push(T[i]);
            }
            else
            {
                if(!p2.empty()) p2.pop();
            }
        }
        if(p1.size()!=p2.size()) return false;
        else
        {
            while(!p1.empty())
            {
                if(p1.top()!=p2.top()) return false;
                p1.pop();
                p2.pop();
            }
        }
        return true;
    }
};
