#include<bits/stdc++.h>
using namespace std;

int solve(string &s,char ch[6][6],int i,int j,int index,int size){
    int found=0;
        if(i>=0&&j>=0&&i<6&&j<6&&ch[i][j]==s[index]){
            char temp=s[index];
            ch[i][j]=0;
            index+=1;
            if(index==size){
                found=1;
            }
            else{
                found+=solve(s,ch,i+1,j,index,size);
                found+=solve(s,ch,i-1,j,index,size);
                found+=solve(s,ch,i,j+1,index,size);
                found+=solve(s,ch,i,j-1,index,size);
            }
            ch[i][j]=temp;
        }

        return found;

}
int main(){
    
	char ch[6][6]={{'B','B','M','B','B','B'},
                    {'C','B','A','B','B','B'},
                    {'I','B','G','B','B','B'},
                    {'G','B','I','B','B','B'},
                    {'A','B','C','B','B','B'},
                    {'M','C','I','G','A','M'}};
    string s="MAGIC";
    int n=5;
    int ans=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            ans+=solve(s,ch,i,j,0,n);
        }
    }
    cout<<ans;
    return 0;
}