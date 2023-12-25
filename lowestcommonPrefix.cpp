#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string ans="";
        string first=strs[0];
        string last=strs[strs.size()-1];
        int n=min(first.size(),last.size());
        for(int i=0;i<n;i++){
            if(first[i]!=last[i]){
                break;
            }
            ans=ans+first[i];
        }
        return ans;
    }


int main(){
    
	vector<string> strs={"flower","flow","flight"};
    
    cout<<longestCommonPrefix(strs)<<endl;
   
    return 0;
}