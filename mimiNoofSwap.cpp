#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string S){
        int ans=0;
        int close=0;
        int open=0;
        int fault=0;
        for(int i=0;i<S.length();i++){
            if(S[i]==']'){
                close++;
                fault=close-open;
            }
            else{
                open++;
                if(fault>0){
                    ans+=fault;
                    fault--;
                }
            }
        }
        
        return ans;
    }


int main(){
    
	string S="[[][][]]][]";
    cout<<minimumNumberOfSwaps(S)<<endl;
   
    return 0;
}