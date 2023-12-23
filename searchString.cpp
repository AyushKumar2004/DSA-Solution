#include<bits/stdc++.h>
using namespace std;

#define d 256

void search(char pat[],char txt[],int q){
    int n=strlen(pat);
    int m=strlen(txt);
    int i,j;
    int p=0;
    int t=0;
    int h=1;

    for( i=0;i<n-1;i++){
        h=(h*d)%q;
    }

    for( i=0;i<n;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }

    for( i=0;i<=m-n;i++){
        if(p==t){
            for( j=0;j<n;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }

            if(j==n){
                cout<<"pattern found at index:"<<i<<endl;
            }
        }

        if(i<m-n){
            t=(d*(t-txt[i]*h)+txt[i+n])%q;
        }
        if(t<0){
            t=t+q;
        }
    }
}

int main(){
    
	char txt[]="this is a text";
    char pat[]="text";
    int q=INT_MAX;

    search(pat,txt,q);

    return 0;
}