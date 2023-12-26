#include<bits/stdc++.h>
using namespace std;

int minFlips (string S)
{
    int n=S.length();
    int s0=0;
    int s1=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(S[i]=='1'){
                s0++;
            }
            else{
                s1++;
            }
        }
        else if(i%2==1){
            if(S[i]=='0'){
                s0++;
            }
            else{
                s1++;
            }
        }
    }
    
    return min(s0,s1);
    
}


int main(){
    
	string S="10101010001";

    cout<<minFlips(S)<<endl;
   
    return 0;
}