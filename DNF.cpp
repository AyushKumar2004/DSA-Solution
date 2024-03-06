#include <bits/stdc++.h>
using namespace std;

class Partition{
    public:
        int left;
        int right;

        Partition(int l,int r):left(l),right(r){}
};

int compareCnt(int num1,int num2){
    if(num1<num2){
        return -1;
    }
    else if(num2<num1){
        return 1;
    }
    else{
        return 0;
    }
}

void swap(int arr[],int position1,int position2){
    if(position1!=position2){
        int temp=arr[position1];
        arr[position1]=arr[position2];
        arr[position2]=temp;
    }
}

Partition partition(int arr[],int low,int high){
    int pivot=arr[low];
    int it=low,gt=high,current=low;
    while(current<=gt){
        int comp=compareCnt(arr[current],pivot);
        switch(comp){
            case 1:
                swap(arr,current,gt--);
                break;
            case -1:
                swap(arr,current++,it++);
                break;
            case 0:
                current++;
                break;
        }
    }
    return Partition(it,gt);
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        Partition partIndex=partition(arr,low,high);
        quickSort(arr,low,partIndex.left-1);
        quickSort(arr,partIndex.right+1,high);
    }
}

int main(){

	int arr[5]={2,4,1,3,5};
    int N=5;
    cout<<"this is quickSort:"<<endl;
    quickSort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    
	return 0;
}