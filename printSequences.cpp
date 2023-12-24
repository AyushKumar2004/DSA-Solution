#include<bits/stdc++.h>
using namespace std;

string printSequences(string &S,string str[]){
	string output="";
	int n1=S.length();
	for(int i=0;i<n1;i++){
		if(S[i]==' '){
			output=output+"0";
		}
		else{
			int index=S[i]-'a';
			output=output+str[index];
		}
	}
	return output;
}

int main(){
    
	string str[]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777",
	"8","88","888","9","99","999","9999"};

	string S="geeksforgeeeks";
	cout<<printSequences(S,str);

	

    return 0;
}