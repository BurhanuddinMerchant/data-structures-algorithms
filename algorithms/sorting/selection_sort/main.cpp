#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to selection sort" << endl;
    cout<<"\nEnter the size of the array you want to sort : ";
    int max_size;
    cin>>max_size;
    int arr[max_size];
    for(int i=0;i<max_size;i++){
        cout<<"enter the "<<i+1<<"th element : ";
        cin>>arr[i];
    }
    for(int i=0;i<max_size-1;i++){
        int min_index = i;
        for(int j = i+1;j<max_size;j++){
            if(arr[min_index]>arr[j]){
                min_index = j;
            }
        }
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
    }
    cout<<"Sorted array : ";
    for(int i=0;i<max_size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
