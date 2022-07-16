// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function template for C++


//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) 
{
    //code here
    unordered_map<char,char> h;
    // for()
    h['a']='2';
    h['b']='2';
    h['c']='2';
    h['d']='3';
    h['e']='3';
    h['f']='3';
    h['g']='4';
    h['h']='4';
    h['i']='4';
    h['j']='5';
    h['k']='5';
    h['l']='5';
    h['m']='6';
    h['n']='6';
    h['o']='6';
    h['p']='7';
    h['q']='7';
    h['r']='7';
    h['s']='7';
    h['t']='8';
    h['u']='8';
    h['v']='8';
    h['w']='9';
    h['x']='9';
    h['y']='9';
    h['z']='9';
    string ans="";
    for(int i=0;i<s.size();i++){
        ans+=h[s[i]];
    }
    return ans;
}
