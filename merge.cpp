#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(int arr[],int l,int mid,int h){
    int left=l;
    int right=mid+1;
    vector<int> temp;
    
    while(left<=mid && right<=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right<=h){
        temp.push_back(arr[right]);
        right++;
    }
    
    int n=temp.size();
    
    int j=0;
    for(int i=l;i<=h;i++){
        arr[i]=temp[j++];
    }
    
    return;
}

void mergeSort(int *arr,int l,int h){
    if(l>=h) return;
    
    int mid=l+(h-l)/2;
    
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
    
    return;
}

int main(){
    
    int arr[]={9,6,3,7,1,98,65,45,64,32,4,5,6,7,43,232,5,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    
    mergeSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}