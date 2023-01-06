class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& target) {
        
        unordered_map<string,int>mp;
        for(auto s:start)
        {
            sort(s.begin(),s.end());
            mp[s]++;
        }
        //cout<<start[0]<<endl;
        
        
        
        int ans = 0;
        for(auto s:target)
        {
           sort(s.begin(),s.end());
           int n = s.size();
	       for (int i = 0; i < n; i++)
	        {
		       string x;
		       for (int j = 0; j < n; j++)
		        {
			      if (j != i)
				   x += s[j];
		        }
		        if(mp[x]){
                    ans++;
                    break;
                }
               
                  
	        }
         }
        return ans;

    }
};