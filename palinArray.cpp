#include<bits/stdc++.h>
using namespace std;

int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++){
            int x=a[i];
            int digit=0;
            while(x>0){
               int carry=x%10;
               digit=digit*10+carry;
               x=x/10;
            }
            if(digit!=a[i]){
                return 0;
            }
        }
        
        return 1;
    	
    }


int main(){

    int arr[6]={1,4,3,6,2,1};
	int n=6;
    int z=PalinArray(arr,n);
    
	cout<<z<<endl;

    return 0;
}