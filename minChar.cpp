#include<bits/stdc++.h>
using namespace std;

vector<int> computeZarray(string &concat){
        vector<int> Z(concat.size(),0);
        int l=0;
        int r=0;
        for(int i=1;i<concat.size();i++){
            if(i<=r){
                Z[i]=min(Z[i-l],r-i+1);
            }
            
            while(concat[0+Z[i]]==concat[i+Z[i]]){
                Z[i]++;
            }
            
            if(i+Z[i]-1>r){
                l=i;
                r=i+Z[i]-1;
            }
        }
        return Z;
    }

    int minChar(string str){
        int n=str.length();
        string revStr=str;
        reverse(begin(revStr),end(revStr));
        string concat=str+'$'+revStr;
        
        int ans=INT_MIN;
        vector<int> Z=computeZarray(concat);
        
        for(int i=0;i<Z.size();i++){
            if(Z[i]==concat.size()-i) ans=max(ans,Z[i]);
        }
        
        return n-ans;
    }

int main(){
    
	string str="AABBBCBBAC";

    cout<<minChar(str);

   
    return 0;
}