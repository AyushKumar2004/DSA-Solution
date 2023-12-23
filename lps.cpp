#include<bits/stdc++.h>
using namespace std;

int lps(string s) {
	   int n=s.length();
	   vector<int> lps(n,0);
	   int pre=0;
	   int suff=1;
	   while(suff<n){
	       if(s[pre]==s[suff]){
	           lps[suff]=pre+1;
	           pre++;
	           suff++;
	       }
	       else{
	           if(pre==0){
	               lps[suff]=0;
	               suff++;
	           }
	           else{
	               pre=lps[pre-1];
	           }
	       }
	   }
	   
	   return lps[n-1];
	}

int main(){
    
	string s="abcabdabcabdabdab";

    int x=lps(s);

    cout<<x<<endl;

    return 0;
}