class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        if(n==0) return ans;
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || (s.top()<0 && asteroids[i]>0) || s.top()*asteroids[i]>0 ) s.push(asteroids[i]); //one going in -ve and other in +ve, or both going in saem direction => push
            else
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i])) s.pop(); //smaller -> burst
                
                if(!s.empty() && s.top()>0)
                {
                    if(s.top()==abs(asteroids[i])) s.pop(); //same size -> both will burst
                    continue;
                }
                
                s.push(asteroids[i]);
            }
        }
        while(!s.empty())
        {
            ans.insert(ans.begin(),s.top());
            s.pop();
        }
        return ans;
    }
};
