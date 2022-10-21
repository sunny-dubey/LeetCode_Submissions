class Solution {
public:
    
    bool check(int n, int sum,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(n==0)
            return nums[0]==sum;
        if(sum==0)
            return true;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        bool x = false;
        if(sum-nums[n]>=0)
           x = check(n-1,sum-nums[n],nums,dp);
        bool y = check(n-1,sum,nums,dp);
        
        return dp[n][sum] = x or y;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum + 1,-1));
        return check(n-1,sum/2,nums,dp);
        
    }
};