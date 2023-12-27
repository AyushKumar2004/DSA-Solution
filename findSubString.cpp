#include<bits/stdc++.h>
using namespace std;

int findSubString(string str)
    {   
        unordered_set<char> s;
        
        for(int i=0;i<str.length();i++) s.insert(str[i]);
        int n=s.size();
        unordered_map<char,int> mp;
        int c=0;
        int i=0;
        mp[str[i]]++;
        c++;
        int j=1;
        int ans=INT_MAX;
        while(i<=j&&j<str.length()){
            if(c<n){
            if(mp[str[j]]==0) c++;
            mp[str[j]]++;
            j++;
            }
            else if(c==n){
                ans=min(ans,j-i);
                if(mp[str[i]]==1) c--;
                mp[str[i]]--;
                i++;
            }
        }
        while(c==n){
            ans=min(ans,j-i);
            if(mp[str[i]]==1) c--;
            mp[str[i]]--;
            i++;
        }
        
        return ans;
    }

int main(){
    
	string str="AABBBCBBAC";

    cout<<findSubString(str);

   
    return 0;
}