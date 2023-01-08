class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        bool flag = true;
        while(flag)
        {
            if(mp[original]){
                original*=2;
                flag = true;
            }
            else
                flag = false;
        }
        return original;
    }
};