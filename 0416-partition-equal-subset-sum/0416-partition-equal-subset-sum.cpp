class Solution {
public:
    
    bool check(int n, int target,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(n==0)
            return nums[0]==target;
        if(target==0)
            return true;
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        bool take = false;
        if(target-nums[n]>=0)
            take = check(n-1,target-nums[n],nums,dp);
        bool not_take = check(n-1,target,nums,dp);
        
        return dp[n][target] = take or not_take;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums)
            sum+=x;
        if(sum%2)
            return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum +1,-1));
        return check(nums.size()-1,sum/2,nums,dp);
    }
};