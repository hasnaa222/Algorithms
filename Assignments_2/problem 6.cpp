#include <iostream>

using namespace std;
int shortest_time(int m, int s)
{
    //static int x=0;
    int s1=0,s2=0,w,Min=1000;
    for(int j=0; j<m; j++)
    {
        //cout<<"1221"<<endl;

        cin>>s1>>s2>>w;
        if(Min>w)
        {
            Min=w;
        }

    }

    //cout<<"mim"<<Min;
   return Min*m;

}
int main()
{
    int number_of_cases,n,m,s=0,t=0;
    // cout << "Hello world!" << endl;
    cin>>number_of_cases;
    for(int i=0; i<number_of_cases; i++)
    {

            cin>>n>>m>>s>>t;
         int res=shortest_time(m, s);
         if(res==0)
         {
             cout<<"Case #"<<i+1<<" :  unreachable"<<endl;
         }
         else
         {
             cout<<"Case #"<<i+1<<" : "<<res<<endl;
         }


    }
    return 0;
}
