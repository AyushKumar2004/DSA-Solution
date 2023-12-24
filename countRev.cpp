#include<bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    int open =0;
    int close=0;
    for(auto ch:s){
        if(ch=='{'){
            open++;
        }else{
            if(open>0){
                open--;
            }else{
                close++;
            }
        }
    }
    if((s.length())%2==1) return -1;
    
    return (open/2)+(open%2)+(close/2)+(close%2);
}

int main(){
    
	string str="{}{}}}{}{}";

	int x=countRev(str);
	cout<<x<<endl;

    return 0;
}