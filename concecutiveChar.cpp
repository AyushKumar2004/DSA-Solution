#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string S)
    {
        string ans="";
        for(int i=0;i<S.length();i++){
            if(i==0||S[i-1]!=S[i]){
                ans+=S[i];
            }
        }
        
        return ans;
    }

int main(){
    
	string S="hellooo";

    cout<<removeConsecutiveCharacter(S)<<endl;
   
    return 0;
}