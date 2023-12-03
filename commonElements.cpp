#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0;
            int j=0;
            int k=0;
            vector<int> v;
            while(i<n1&&j<n2&&k<n3){
                if(A[i]==B[j] and B[j]==C[k]){
                    v.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j]){
                    i++;
                }
                else if(B[j]<C[k]){
                    j++;
                }
                else{
                    k++;
                }
                int xx=A[i-1];
                while(A[i]==xx) i++;
                int yy=B[j-1];
                while(B[j]==yy) j++;
                int zz=C[k-1];
                while(C[k]==zz) k++;
            }
            if(v.size()==0){
                return {-1};
            }
            
            return v;
        }



int main(){

    int v1[3]={3,3,3};
    int n1=3;
    int v2[3]={3,3,3};
    int n2=3;
    int v3[3]={3,3,3};
    int n3=3;

    vector<int> ans=commonElements(v1,v2,v3,n1,n2,n3);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}