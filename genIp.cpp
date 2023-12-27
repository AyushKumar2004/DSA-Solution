#include<bits/stdc++.h>
using namespace std;

bool isValid(string &check){
        vector<string> ip;
        string ex="";
        for(int i=0;i<check.length();i++){
            if(check[i]=='.'){
                ip.push_back(ex);
                ex="";
            }
            else{
                ex=ex+check[i];
            }
        }
        ip.push_back(ex);
        
        
        for(int i=0;i<ip.size();i++){
            if(ip[i].length()>3||stoi(ip[i])<0||stoi(ip[i])>255){
                return 0;
            }
            if(ip[i].length()>1&&stoi(ip[i])==0) return 0;
            if(ip[i].length()>1&&stoi(ip[i])!=0&&ip[i][0]=='0') return 0;
        }
        
        
        return 1;
    }
    
  
    vector<string> genIp(string &s) {
        int n=s.length();
        
        vector<string> ans;
        string check=s;
        
        for(int i=1;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    check=check.substr(0,k)+'.'+check.substr(k);
                    check=check.substr(0,j)+'.'+check.substr(j);
                    check=check.substr(0,i)+'.'+check.substr(i);
                    
                    if(isValid(check)){
                        ans.push_back(check);
                    }
                    check=s;
                }
            }
        }
        
        return ans;
    }


int main(){
    
	string s="58854556";

    vector<string> ans=genIp(s);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

   
    return 0;
}