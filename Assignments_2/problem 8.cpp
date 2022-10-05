//problem#8
#include<iostream>
#include<algorithm>
using namespace std;
struct Job{
    char JobID;
    int Deadline;
    int profit;
};
bool comparison(Job x, Job y){
    return (x.profit > y.profit);
}
void JobScheduling(Job arr[], int n){
    sort(arr, arr+n, comparison);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for (int i=0; i<n; i++){
        for (int j=min(n, arr[i].Deadline)-1; j>=0; j--){
            if (slot[j]==false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i=0; i<n; i++)
        if (slot[i])
            cout << arr[result[i]].JobID << " ";
}
int main(){
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                 {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum profit: ";
    JobScheduling(arr, n);
    return 0;
}