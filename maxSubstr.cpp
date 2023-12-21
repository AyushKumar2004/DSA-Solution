#include<bits/stdc++.h>
using namespace std;

int maxSubStr(string str){
        int cnt=0;
        int cnt1=0;
        int cnt0=0;
        int n=str.length();
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            if(cnt1==cnt0){
                cnt++;
            }
        }
        if(cnt1!=cnt0){
            return -1;
        }
        return cnt;
    }	

int main(){
    
	string str="00110011";
	int x=maxSubStr(str);
	cout<<x<<endl;
    return 0;
}