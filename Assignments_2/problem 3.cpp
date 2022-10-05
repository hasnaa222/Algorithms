#include <iostream>
#include <vector>
using namespace std;

int Kruskal(int g_from [],int g_to[],int g_with[],int g_edg,int g_node)
{
    int Min=g_with[0];
    int sum=0,in;
    vector<int>index;
    index.push_back(-1);
    int start=g_from[0];
    for(int j=0; j<g_node; j++)
    {

        for(int i=1; i<g_edg; i++)
        {
            for(int s=0;s < index.size() ;s++)
            {
           if(i!=index[s])
            {
            if(j>=g_node-3)
            {
                if(Min>g_with[i])
                    {
                        Min=g_with[i];
                        in=i;


                    }
            }
            else{
                if(start==g_from[i])
                {

                    if(Min>g_with[i])
                    {
                        Min=g_with[i];
                        in=i;


                    }

                }
            }



        }
            }

        }
        index.push_back(in);
        start=g_to[in];
        sum=sum+Min;
        Min=10000;
    }
    return sum;
}
int main()
{

    int g_node,g_edg;
   // cout << "enter node and edge" << endl;
    cin>>g_node>>g_edg;

    int g_from [g_edg],g_to[g_edg],g_with[g_edg];
    for(int i=0; i<g_edg; i++)
    {
        cin>>g_from [i]>>g_to[i]>>g_with[i];
    }
    cout<<Kruskal(g_from,g_to, g_with, g_edg,g_node);

    return 0;
}
