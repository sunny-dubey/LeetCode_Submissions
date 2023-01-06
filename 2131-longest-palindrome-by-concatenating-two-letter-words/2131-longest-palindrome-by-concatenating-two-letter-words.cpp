class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto x:words)
        {
            mp[x]++;
        }
        bool flag = false;
        int ans = 0;
        for(auto x: mp)
        {
            string temp = x.first;
            string t = x.first;
            reverse(temp.begin(),temp.end());
            if(temp==t)
            {
                ans+=x.second/2;
                if(x.second%2)
                    flag = true;
            }
            else
            {
                if(mp.count(temp)){
                ans+=min(mp[temp], x.second);
                mp.erase(temp);
                }
            }
        }
        ans= ans * 4;
        if(flag)
            ans+=2;
        return ans;
    }
};