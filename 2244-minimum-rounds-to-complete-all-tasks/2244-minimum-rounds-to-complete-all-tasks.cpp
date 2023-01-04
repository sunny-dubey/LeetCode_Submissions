class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto x:tasks)
            mp[x]++;
        for(auto x:mp)
        {
            if(x.second==1)
              return -1;
        }
       
        vector<int>count(1e5+10,0);
        int x = 1;
        for(int i=1;i<=1e5;i+=3)
        {
            count[i]=x;
            count[i+1]=x;
            count[i+2]=x;
            x++;
        }
        int ans = 0;
        for(auto x:mp)
            ans+=count[x.second];
        
        return ans;
        
    }
};