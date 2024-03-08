#include <bits/stdc++.h>
using namespace std;

void solve(int n,unordered_set<string> &wordDict,string s,int i,string str,vector<string> &ans){
        if(i>=s.size()){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        string word="";
        for(int j=i;j<s.length();j++){
            word+=s[j];
            if(wordDict.find(word)!=wordDict.end()){
                solve(n,wordDict,s,j+1,str+word+" ",ans);
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> wordDict;
        for(auto i:dict) wordDict.insert(i);
        string str="";
        vector<string> ans;
        solve(n,wordDict,s,0,str,ans);
        return ans;
    }

int main(){

    string s="catsanddog";
    vector<string> dict={"cats", "cat", "and", "sand", "dog"};
    int n=5;
	vector<string> ans=wordBreak(n,dict,s);

    for(auto it:ans){
        cout<<it<<endl;
    }

	return 0;
}