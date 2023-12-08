//code help
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(int arr[],int l,int h){
    int pivot=arr[l];
    
    int count=0;
    
    for(int i=l+1;i<=h;i++){
         if(arr[i]<=pivot){
             count++;
         }    
    }
    
    int pivotInd=l+count;
    
    swap(arr[l],arr[pivotInd]);
    
    
    
    int i=l;
    int j=h;
    while(i<pivotInd && j>pivotInd){
        while(arr[i]<=pivot){
            i++;
        }
        
        while(arr[j]>pivot){
            j--;
        }
        
        if(i<pivotInd && j>pivotInd){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    
    return pivotInd;
}


void quickSort(int arr[],int l,int h){
    if(l>=h){
        return;
    }
    
    int p= partition(arr,l,h);
    
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,h);
}





int main(){
    
    int arr[]={9,6,3,7,1,98,65,45,64,32,4,5,6,7,43,232,5,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    
    quickSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
