#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        int n=x.length();
        stack<char> s;
        for(int i=0;i<n;i++){
            if(x[i]=='('||x[i]=='['||x[i]=='{'){
                s.push(x[i]);
            }
            if(x[i]==')'||x[i]=='}'||x[i]==']'){
                if(s.empty()){
                    return false;
                }
                char top=s.top();
                if(x[i]=='}'&&top!='{'||x[i]==']'&&top!='['||x[i]==')'&&top!='('){
                    return false;
                }
                s.pop();
            }
        }
        if(s.empty()){
            return true;
        }
        
        return false;
    }

int main(){
    
	string s="{()}[(())]";

    bool x=ispar(s);

    cout<<x<<endl;

    return 0;
}