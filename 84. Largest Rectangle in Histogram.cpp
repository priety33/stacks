class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        int left[n], right[n];
        memset(left, -1, sizeof(left));
        memset(right, -1, sizeof(right));
        stack <int> lefts, rights;
        int area=0;
        for(int i=0;i<n;i++)
        {
            if(rights.empty() || heights[rights.top()]<heights[i]) rights.push(i);
            else 
            {
                while(!rights.empty() && heights[rights.top()]>heights[i] )
                {
                    right[rights.top()]=i;
                    rights.pop();
                }
                rights.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(right[i]==-1) right[i]=n;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(lefts.empty() || heights[lefts.top()]<heights[i]) lefts.push(i);
            else 
            {
                while(!lefts.empty() && heights[lefts.top()]>heights[i])
                {
                    left[lefts.top()]=i;
                    lefts.pop();
                }
                lefts.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            area=max(area,heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};
