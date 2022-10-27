class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> a;
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                    a.push_back({i,j});
                if(img2[i][j]==1)
                    b.push_back({i,j});
            }
        }
        int ans = 0;
        map<pair<int,int>,int> mp;
        for(auto x:a)
        {
            for(auto y:b)
            {
                mp[{x.first - y.first, x.second - y.second}]++;
                ans = max(ans,mp[{x.first - y.first, x.second - y.second}]);
                
            }
        }
        return ans;
    }
};