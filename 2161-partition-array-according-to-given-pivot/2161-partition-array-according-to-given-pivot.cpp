class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> a,b,c;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
                a.push_back(nums[i]);
            else if(nums[i]>pivot)
                b.push_back(nums[i]);
            else
                c.push_back(nums[i]);
        }
        vector<int> ans;
        for(auto x:a)
            ans.push_back(x);
        for(auto x:c)
            ans.push_back(x);
        for(auto x:b)
            ans.push_back(x);
        return ans;
        
    }
};