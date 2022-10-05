//problem#5
#include<bits/stdc++.h>
using namespace std;
int getT(char arr1[],int n1,int k1){
    int count=0;
    for(int i=0;i<n1;i++){
        if(arr1[i]=='P'){
            for (int j = 1; j <= k1; ++j) {
                if(arr1[j]=='T'){
                    count=count+1;
                    break;
                }
            }
        }
    }return count;
}
//{'T', 'T', 'P', 'P', 'T', 'P'}  k=2 output=3
//{ 'P','T','T','P', 'T'}         k=1 output=2
int main(){
    int n,k;
    k=2;
    char arr[]= {'T', 'T', 'P', 'P', 'T', 'P'};
    n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Maximum {"<<getT(arr,n,k)<<"} thieves can be caught"<<endl;
    return 0;
}