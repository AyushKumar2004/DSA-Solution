#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
        int n=str.length();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
  
void solve(string S,int index,vector<vector<string>> &ans,vector<string> &curr){
        if(index==S.length()){
            ans.push_back(curr);
            return ;
        }
        string t;
        for(int i=index;i<S.length();i++){
            t+=S[i];
            if(isPalindrome(t)){
                curr.push_back(t);
                solve(S,i+1,ans,curr);
                curr.pop_back();
            }
        }
}
    
vector<vector<string>> allPalindromicPerms(string S) {
       vector<vector<string>> ans;
       vector<string> curr;
       solve(S,0,ans,curr);
       return ans;
}

int main(){

    string S="geeks";

    vector<vector<string>> ans=allPalindromicPerms(S);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }

	return 0;
}