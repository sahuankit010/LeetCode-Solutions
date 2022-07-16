// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.

void fillLPS(string str, int *lps){
    int n=str.length(), len=0, i=1;
    lps[0]=0;
    while(i<n){
        if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
        } else{
            if(len==0){
                lps[i]=0;
                i++;
            } else{
                len=lps[len-1];
            }
        }
    }
}

int strstr(string s, string x)
{
     //Your code here
     
     //KMP Algo
    int n=s.length(), m=x.length();
    int lps[m];
    fillLPS(x,lps);
    int i=0,j=0;
    while(i<n){
        if(x[j]==s[i]){
            i++;
            j++;
        }
        if(j==m) return i-j;
        else if(i<n and x[j]!=s[i]){
            if(j==0) i++;
            else j= lps[j-1];
        }
    }
    
    return -1;
}