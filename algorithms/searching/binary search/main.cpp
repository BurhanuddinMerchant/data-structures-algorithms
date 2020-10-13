#include<iostream>
#include<algorithm>
using namespace std;

long long binary_search_algorithm(long long l,long long r,long long *a,long long e){
    if(l<=r){
        long long mid = (l + r) / 2;
        if(a[mid]==e)
            return mid;
        else if(a[mid]>e)
            return binary_search_algorithm(l, mid - 1, a, e);
        return binary_search_algorithm(mid + 1, r, a, e);
    }
    return -1;
}

void print_array(long long *a,long long n){
    for (long long i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    //example functionality
    long long n;
    cout << "Enter the size of array : ";
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n;i++){
        cout << "Enter " << i + 1 << " th element : ";
        cin >> a[i];
    }
    sort(a, a + 7);
    cout << "Sorted array : ";
    print_array(a, n);
    cout << "\n(0 base index used)(-1 indicates not found)\n";
    cout<<"Location of 2 : "<<binary_search_algorithm(0, 6,a,2)<<endl;
    cout<<"Location of 9 : "<<binary_search_algorithm(0, 6,a,9)<<endl;
    return 0;
}
