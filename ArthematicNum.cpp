#include<iostream>
using namespace std;\

int inSequence(int A, int B, int C){
        if(C==0){
            return A==B;
        }
        return (((B-A)%C==0)&&((B-A)/C>=0));
    }

int main(){
    int A=1;
    int B=3;
    int C=2;
    cout<<inSequence(A,B,C)<<endl;
    return 0;
}