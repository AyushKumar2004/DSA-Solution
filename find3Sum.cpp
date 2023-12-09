#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
    {
        for(int i=0;i<n;i++){
            sort(A,A+n);
            int j=i+1;
            int k=n-1;
            
            while(j<k){
                int currSum=A[i]+A[j]+A[k];
                if(currSum==X){
                    return true;
                }
                else if(currSum<X){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        return false;
    }


int main(){

    int a1[8]={11, 7, 1, 13, 21, 3, 7, 3};
	int n=8;
    int x=19;
    bool z=find3Numbers(a1,n,x);
    cout<<z<<endl;
	

    return 0;
}