#include<bits/stdc++.h>
using namespace std;

void subsequences(string str,string output,vector<string> &ans,int index){

	if(index>=str.length()){
		if(output.length()>0){
		ans.push_back(output);
		return;
		}
	}

	subsequences(str,output,ans,index+1);

	output.push_back(str[index]);
	subsequences(str,output,ans,index+1);
}

vector<string> subseq(string str){
	vector<string> ans;
	string output=" ";
	int index=0;
	subsequences(str,output,ans,index);
	return ans;
}	

int main(){
    
	string str="abc";
	vector<string> x=subseq(str);
	int n=x.size();
	for(int i=0;i<n;i++){
		cout<<x[i]<<endl;
	}
    return 0;
}