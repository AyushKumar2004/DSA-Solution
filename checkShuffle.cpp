#include<bits/stdc++.h>
using namespace std;

bool checkShuffle(string s1,string s2,string shuffle){
	unordered_map<char,int> mp;
	int n1=s1.length();
	for(int i=0;i<n1;i++){
		mp[s1[i]]=1;
		if(mp.find(s1[i])!=mp.end()){
			mp[s1[i]]++;
		}
	}
	int n2=s2.length();
	for(int i=0;i<n2;i++){
		mp[s2[i]]=1;
		if(mp.find(s2[i])!=mp.end()){
			mp[s2[i]]++;
		}
	}

	int n3=shuffle.length();
	for(int j=0;j<n3;j++){
		if(mp.find(shuffle[j])!=mp.end()){
			mp[shuffle[j]]--;
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
    
    string s1="ab";
	string s2="cd";
	string shuffle="cabed";

	bool z=checkShuffle(s1,s2,shuffle);
	cout<<z<<endl;
    return 0;
}