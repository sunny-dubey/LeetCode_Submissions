class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i] = nums[i] + prefix[i-1];
        vector<int> ans;
        for(auto x: queries)
        {
           auto it = upper_bound(prefix.begin(),prefix.end(),x) - prefix.begin();
            ans.push_back(it);
        }
        return ans;
    }
};