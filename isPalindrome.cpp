#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string S)
	{
	    int i=0;
	    int j=S.length()-1;
	    while(i<=j){
	        if(S[i]!=S[j]){
	            return 0;
	        }
	        i++;
	        j--;
	    }
	    return 1;
	}

int main(){
    
    string s="roor";
    int z=isPalindrome(s);
    cout<<z<<endl;
    return 0;
}