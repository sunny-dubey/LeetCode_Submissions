class Solution {
public:
    
    int check(int i, int j, string &x, string &y,vector<vector<int>> &dp)
    {
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i]==y[j])
            return dp[i][j] =  1 + check(i-1,j-1,x,y,dp);
        if(x[i]!=y[j])
            return  dp[i][j] = max(check(i-1,j,x,y,dp),check(i,j-1,x,y,dp));
        return 0;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),0));
        int n = text1.size();
        int m = text2.size();
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(text1[i]==text2[j]){
                    dp[i][j] =1;
                    if(i-1>=0 and j-1>=0)
                        dp[i][j]+=dp[i-1][j-1];
                        
                }
        
                else{
                    int x = 0;
                    int y = 0;
                    if(i-1>=0)
                        x = dp[i-1][j];
                    if(j-1>=0)
                        y = dp[i][j-1];
                    dp[i][j] = max(x,y);
                    
                }
                
            }
        }
        return dp[n-1][m-1];
        
        
    }
};