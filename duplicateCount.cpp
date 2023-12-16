#include<bits/stdc++.h>
using namespace std;

void duplicateCnt(string s){
	sort(s.begin(),s.end());

    for(int i=0;i<s.length();i++){

	int count=1;
	while(i<s.length()-1&&s[i]==s[i+1]){
		count++;
		i++;
	}

	if(count>1){
		cout<<"element:"<<s[i]<<" count:"<<count<<endl;
	}
  }	
}

int main(){
    
    string s="roooooooooor";
    duplicateCnt(s);
    return 0;
}