class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            {
                if(mp[nums[i]+1]==0 and mp[nums[i]-1]==0)
                    ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};