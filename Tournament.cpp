#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,j,k;
        cin>>n>>j>>k;
        int arr[n];
        for (int i=0; i<n; i++) {
            cin>>arr[i];
        }
        bool flag=false;
        if (k==1) {
            flag=true;
            int count=arr[j-1];
            sort(arr,arr+n);
            if (arr[n-1]==count)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        if (!flag) {
            cout<<"YES"<<endl;
        }
    }
}