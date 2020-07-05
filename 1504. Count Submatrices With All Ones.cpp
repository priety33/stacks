class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        int n= mat.size(), m= mat[0].size();
        int dp[n][m];
        for(int i=0; i<n; i++) {
            for(int j=m-1; j>=0; j--) {
                dp[i][j]= mat[i][j];
                if(mat[i][j]==0 || j==m-1) continue;
                dp[i][j]+= dp[i][j+1];
            }
        }
        for(int j=0; j<m; j++) {
            int i= n-1, mycount=0; //mycount gives how many matrices can i form
            stack<pair<int,int>> s;
            while(i>=0) {
                int c= 0; //keeps count of elements greater than current below it in stack
                while(!s.empty() && s.top().first>dp[i][j]) {
                    int row= s.top().first-dp[i][j];
                    int col= s.top().second+1;
                    mycount-= (row)*(col); //deleting number of matrices which current 1 cannot be a part of
                    c+= col;
                    s.pop();
                }
                mycount+= dp[i][j];
                ans+= mycount;
                s.push({dp[i][j],c});
                i--;
            }
        }
        return ans;
    }
};
