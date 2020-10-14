#include <iostream>

using namespace std;

void merge_array(int *a,int *l ,int lc,int *r,int rc){
    int i,j,k;
    i=j=k=0;
    while(i<lc && j<rc){
        if(l[i]>=r[j]){
            a[k] = l[i];
            i++;
            k++;
        }
        else{
            a[k] = r[j];
            j++;
            k++;
        }
    }
    while(i<lc){
        a[k] = l[i];
        i++;
        k++;
    }
    while(j<rc){
        a[k] = r[j];
        k++;
        j++;
    }
}

void merge_sort(int *a,int n){
    if(n<2) return ;
    int mid = n/2;
    int l[mid];
    int r[n-mid];
    for(int i=0;i<mid;i++){
        l[i] = a[i];
    }
    for(int i=mid;i<n;i++){
        r[i-mid] = a[i];
    }
    merge_sort(l,mid);
    merge_sort(r,n-mid);
    merge_arrays(a,l,mid,r,n-mid);
    delete l;
    delete r;
}


void print_array(long long *a, long long n){
    for(long long i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element : ";
        cin>>a[i];
    }
    cout<<"Before : ";
    print_array(a);
    merge_sort(a,n);
    cout<<"After : ";
    print_array(a);
    return 0;
}
