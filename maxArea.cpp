#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<int> nextSmallerElement(int* arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(arr[s.top()]>=curr&&s.top()!=-1){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevNextSmallerElement(int* arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(arr[s.top()]>=curr&&s.top()!=-1){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    int largestArea(int* heights,int n){
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int> prev(n);
        prev=prevNextSmallerElement(heights,n);
        
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            
            int newArea=l*b;
            area=max(area,newArea);
        }
        
        return area;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int Area=largestArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
            }
            
            Area=max(Area,largestArea(M[i],m));
        }
        return Area;
    }


int main(){
int M[MAX][MAX]={{0,1,1,0},
                {1,1,1,1},
                {1,1,1,1},
                {0,1,1,0}};
int n=4;
int m=4;
int z=maxArea(M,n,m);
cout<<z<<endl;
    return 0;
}