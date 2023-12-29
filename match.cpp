#include<bits/stdc++.h>
using namespace std;


bool match(string wild, string pattern)
    {
        int n=wild.length();
        int m=pattern.length();
        vector<bool> prev(m+1,false) ,curr(m+1,false);
        
        prev[0]=true;
        
        for(int j=1;j<=m;j++){
            prev[j]=false;
        }
        
        
        for(int i=1;i<=n;i++){
            
            bool flag=true;
            for(int i1=1;i1<=i;i1++){
                if(wild[i1-1]!='*'){
                    flag=false;
                    break;
                }
            }
            curr[0]=flag;
            
            for(int j=1;j<=m;j++){
        
            if(wild[i-1]==pattern[j-1]||wild[i-1]=='?'){
                 curr[j]=prev[j-1];
            }
            else if(wild[i-1]=='*'){
                 curr[j]=prev[j]||curr[j-1];
            }
            else curr[j]=false;
            
        }
        prev=curr;
    }
        
        return prev[m];
    }


int main(){
    
	string wild="**geek?";
    string pattern="geeks";

    cout<<match(wild,pattern);
   
    return 0;
}