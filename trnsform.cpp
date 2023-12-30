#include<bits/stdc++.h>
using namespace std;

int transform (string A, string B)
    {   
        if(A.length()!=B.length()) return -1;
        
        int n=A.length();
        int count[256];
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i++){
            count[A[i]]++;
        }
        for(int i=0;i<n;i++){
            count[B[i]]--;
        }
        for(int i=0;i<256;i++){
            if(count[i]){
                return -1;
            }
        }
        
        int i=n-1;
        int j=n-1;
        int res=0;
        while(i>=0&&j>=0){
            while(i>=0&&A[i]!=B[j]){
                i--;
                res++;
            }
            if(i>=0){
            i--;
            j--;
            }
        }
        return res;
    }


int main(){
    
	string pattern="ABD";
    string txt="BAD";

    cout<<transform(pattern,txt);

    return 0;
}