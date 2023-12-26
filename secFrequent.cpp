#include<bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<int> store;
        for(auto i:mp) store.push_back(i.second);
        
        sort(store.begin(),store.end());
        
        int secFreq=store[store.size()-2];
        
        for(auto i:mp){
            if(secFreq==i.second) return i.first;
        }
        
        return "";
        
    }


int main(){
    
	string arr[6] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    int n=6;
    cout<<secFrequent(arr,n)<<endl;
   
    return 0;
}