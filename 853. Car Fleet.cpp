class Solution {
public:
    
    static bool compare(pair<int,double> a, pair<int,double>b){
        return a.first>b.first;
    }
   
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> t;
        for(int i=0; i<speed.size(); i++)
        {
            t.push_back({position[i], (target-position[i])/(double)speed[i]});
        }
        sort(t.begin(), t.end(), compare);
        stack<int> s;
        for(int i=0; i<speed.size(); i++)
        {
            if(s.empty() || t[s.top()].second < t[i].second) s.push(i);
        }
        return s.size();
    }
};
