//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int x = str.size();
  int i = 0;
  while(i<x)
  {
      char temp = str[x-1];
      str[x-1] = str[i];
      str[i] = temp;
      i++;
      x--;
  }
  return str;
  
}

