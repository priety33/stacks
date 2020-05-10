class Solution {
public:
    int calPoints(vector<string>& ops) {
        if(ops.size()==0) return 0;
        stack<int> s;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
                if(!s.empty()) s.pop();
            }
            else if(ops[i]=="D")
            {
                if(!s.empty()) s.push(2*s.top());
            }
            else if(ops[i]=="+")
            {
                int a=s.top(); s.pop();
                int b=a+s.top();
                s.push(a);
                s.push(b);
            }
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
