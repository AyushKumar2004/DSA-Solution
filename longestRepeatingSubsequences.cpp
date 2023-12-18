#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    int arr[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0||j==0){
		                arr[i][j]=0;
		            }
		            else if(str[i-1]==str[j-1]&&i!=j){
		                arr[i][j]=1+arr[i-1][j-1];
		            }
		            else{
		                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
		            }
		        }
		    }
		    
		    return arr[n][n];
		}

	

int main(){
    
	string S="aaaabbaa";
	int z=LongestRepeatingSubsequence(S);
	cout<<z<<endl;
    return 0;
}