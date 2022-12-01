class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int> mp  = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        int x = 0;
        int y = 0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(mp[s[i]])
                x++;
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(mp[s[i]])
                y++;
        }
        return x==y;
    }
};