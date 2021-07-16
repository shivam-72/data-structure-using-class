#include<iostream>
using namespace std;
void printarray(int arr[],int n){
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
}
int main(){
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int a[n];
    cout<<"Enter the element of array";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
     for(int j=0;j<n-i-1;j++){
         if(a[j]>a[j+1]){
             swap(a[j],a[j+1]);
         }
     }
    }
    printarray(a,n);
    return 0;
}