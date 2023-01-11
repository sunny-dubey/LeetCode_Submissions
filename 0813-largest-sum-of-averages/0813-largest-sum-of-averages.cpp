class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k+1,0));
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = nums[i] + prefix[i-1];
        for(int i=0;i<n;i++)
           dp[i][1] = (double)prefix[i]/(i+1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                double sum = 0;
                for(int x=i;x>=0;x--)
                {
                    sum+=nums[x];
                    if(i - (i-x+1)>=0)
                    dp[i][j] = max(dp[i][j], sum/((double)(i-x+1)) + dp[i-(i-x+1)][j-1]);
                }
            }
        }
        return (double)dp[n-1][k];
    }
};