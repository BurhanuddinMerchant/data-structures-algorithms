#include <iostream>

using namespace std;

void printArray(int *a,int n){
    for(int i = 0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
}

void swap_positions(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition_array(int *a,int left ,int right,int pivot){
    while(left<=right){
        while(a[left]<pivot){
            left++;
        }
        while(a[right]>pivot){
            right--;
        }
        if(left<=right){
            swap_positions(a[left],a[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(int *a,int left,int right){
    if(left>=right){
        return;
    }
    int pivot = a[left];
    int pi = partition_array(a,left,right,pivot);
    quickSort(a,left,pi-1);
    quickSort(a,pi,right);
}


int main()
{
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element of the array : ";
        cin>>arr[i];
    }
    //sort the array from the index 0,n-1 (basically the whole array
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}
