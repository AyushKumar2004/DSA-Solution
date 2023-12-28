#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<string_list.size();i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
        }
        
        for(auto i: mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }

int main(){
    
	vector<string> string_list={"act","dog","tac","god","cat"};

    int n=string_list.size();

    vector<vector<string>> ans=Anagrams(string_list);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

   
    return 0;
}