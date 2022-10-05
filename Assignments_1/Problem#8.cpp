#include <iostream>

using namespace std;


    int Search(int arr[5],int key)
    {

        for(int i=1;i<5;i++)
        {
            if(arr[i]==(key+1))
            {
                key+=1;

            }
            else
            {

                return i;

            }
        }
        return -1;
    }


int main()
{
    cout << "-----------------------------------------------" << endl;
    int arr[5]={111,112,113,22,115};
    int x=arr[0];
    int indx=Search(arr,x);
    if (indx==-1)
    {
        cout<<" dont  have any defective toy"<<endl;
    }
    else{ cout<<" the serial number of the first defective toy is : "<<indx<<endl;}
    return 0;
}
