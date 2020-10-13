#include <iostream>

using namespace std;

void swap_value(long long &x, long long &y){
    long long temp = x;
    x = y;
    y = temp;
}

void bubble_sort(long long *a,long long n){
    bool compared = true; // keeps track of comparisons
    while(compared){
        compared=false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap_value(a[i],a[i+1]);
                compared = true;
            }
        }
    }
}

void print_array(long long *a, long long n){
    for(long long i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    long long n;
    cout<<"Bubble sort :\n";
    cout<<"Enter the length of list to be sorted : ";
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" th element : ";
        cin>>a[i];
    }
    cout<<"Before sorting : ";
    print_array(a,n);
    bubble_sort(a,n);
    cout<<"After sorting  : ";
    print_array(a,n);
    return 0;
}
