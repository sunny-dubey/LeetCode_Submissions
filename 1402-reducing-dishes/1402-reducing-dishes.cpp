class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        vector<vector<int>> dp(n+2, vector<int>(n+2,-1));
        
       for(int i=n-1;i>=0;i--)
       {
           for(int j=1;j<=n;j++)
           {
               if(i==n-1)
               {
                   dp[i][j] = arr[i]*j;
               }
               else
               {
                   dp[i][j] = max(dp[i+1][j], arr[i]*j + dp[i+1][j+1]);
               }
           }
       }
        return max(0,dp[0][1]);
        
        
       
    }
};