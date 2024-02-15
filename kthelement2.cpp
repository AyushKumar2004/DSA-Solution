#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> pq;
        int i=0;
        int j=0;
        int cnt=0;
        
        while(cnt<k&&i<n&&j<m){
            if(arr1[i]<=arr2[j]){
                pq.push(arr1[i]);
                i++;
                cnt++;
            }
            else{
                pq.push(arr2[j]);
                j++;
                cnt++;
            }
        }
        
        while(i<n&&cnt<k){
            pq.push(arr1[i]);
            i++;
            cnt++;
        }
        
        while(j<m&&cnt<k){
            pq.push(arr2[j]);
            j++;
            cnt++;
        }
       return pq.top();
    }

int main(){

	int arr1[5]={4,7,8,9,10};
	int arr2[4]={1,2,4,6};
	int n=5;
	int m=4;
	int k=5;
	cout<<kthElement(arr1,arr2,n,m,k);
	return 0;
}