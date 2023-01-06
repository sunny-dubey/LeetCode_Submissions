class Solution {
public:
    long long mostPoints(vector<vector<int>>& nums) {
        long long n = nums.size();
        
        vector<long long> dp(n,0);
        dp[n-1] = nums[n-1][0];
        for(int i=n-2;i>=0;i--)
        {
            dp[i] = nums[i][0];
           dp[i] = max(dp[i+1], dp[i]);
            if(i+nums[i][1] + 1 <n)
              dp[i] = max(dp[i], nums[i][0] + dp[i + nums[i][1]+1]);
        }
        return dp[0];
    }
};