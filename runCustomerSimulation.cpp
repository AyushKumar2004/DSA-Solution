#include<bits/stdc++.h>
using namespace std;

const int maxChar=26;

int runCoustomerSimulation(int n, string pattern)
    {
        int count[maxChar]={0};
        int ind=0;
        int res=0;
        int occupied=0;
        for(int i=0;i<pattern.length();i++){
            ind=pattern[i]-'A';
            if(count[ind]==0){
                count[ind]=1;
                if(occupied<n){
                    count[ind]=2;
                    occupied++;
                }
                else res++;
            }
            else{
                if(count[ind]==2){
                count[ind]=0;
                occupied--;
                }
            }
        }
        return res;
    }


int main(){
    
	string pattern="ABCBCA";
    int n=1;

    cout<<runCoustomerSimulation(n,pattern);

    return 0;
}