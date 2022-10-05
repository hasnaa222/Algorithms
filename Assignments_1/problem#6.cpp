/*
problem#6
 *this code Explain HashFunction in simple code
 * fisrt step:convert key to index by hash function
 * then Insert in HashTable using key and HashFunction by get mod HashingKey
 * and to solve collision we insert in linked list
 */
#include<bits/stdc++.h>
using namespace std;
class Hashing{
    int ID;
    list<int> *soldBy;
public:
    Hashing(int b) {
        this->ID = b;
        soldBy = new list<int>[ID];
    }
    int hashFunction(int x) {
        return (x % ID);
    }
    void insert(int key){
        int index = hashFunction(key);
        soldBy[index].push_back(key);
    }
    //print HashTable
    void print() {
        for (int i = 0; i < ID; i++) {
            cout << i;
            for (auto x : soldBy[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};
int main(){
    const int maxn = 5e3 + 10;
    int a[maxn];
    int key;
    int n;
    cout<<"Enter HashingKey:"<<endl;
    cin>>key;
    cout<<"Enter num of key:"<<endl;
    cin>>n;
    cout<<"Enter keys:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    Hashing h(key);
    for (int i = 0; i < n; i++)
    {
        h.insert(a[i]);
    }
    h.print();
    return 0;
}