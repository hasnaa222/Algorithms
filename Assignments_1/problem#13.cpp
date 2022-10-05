// string assigning
#include <iostream>
#include <string>

using namespace std;
class matrix
{
    int Size;
    int *row, *column;
public:
    matrix(int s)
    {
        Size=s;
        row =new int[Size];
        column =new int [Size];
    }
    string display ()
    {
        for(int i=0; i<Size; i++)
        {
            cout<<"\n Enter row and column for "<<i+1<<" array"<<endl;
            cin>>row[i]>>column[i];
        }
        cout<<endl;
        string output =" ",tmp,tmp1;
        for(int i=Size-2 ; i>=0 ; i--)
        {
           if(row[i+1]==column[i])
           {
               if(output==" ")
               {
                   output="(A2";
                  // i+=1;
                   tmp="xA3";
                   output=output+tmp+")";
                  // i-=1;
               }
               else
               {
                   tmp1=output;
                   output="(A1";
                   tmp=" X";
                   output=output+tmp;
                   //output="(A1 *";
                   output=output+tmp1+")";

               }
           }
        }
        return output;

    }
};

int main()
{
    int number;
    cout << "enter number array" << endl;
    cin>>number;
    matrix obj(number);
    cout<<obj.display();
    return 0;
}
