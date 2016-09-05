
#include <iostream>
using namespace std;
#define infi 5000  //infi for infinity
class prims
{
	public:
   int **array,nodes;
   void createGraph();
   void primsAlgo();
};

void prims :: createGraph()
{
    int i,j;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
	array=new int*[nodes];
	for(i=0;i<nodes;i++)
	{
		array[i]=new int[nodes];
	}
    cout<<"\nEnter Adjacency Matrix :\n";
    for(i=0;i<nodes;i++)
	{
        for(j=0;j<nodes;j++)
		{
			cin>>array[i][j];
		}
	}
    //Assign infinity to all array[i][j] where weight is 0
        for(i=0;i<nodes;i++)
		{
			for(j=0;j<nodes;j++)
			{
			if(array[i][j]==0)
				{
					array[i][j]=infi;
				}
			}
		}
}


void prims :: primsAlgo()
{
    int selected[nodes],i,j,ne; //ne for no. of edges
    int min,x,y;

    for(i=0;i<nodes;i++)
	{
        selected[i]=0;
	}
    selected[0]=1;
    ne=0;

    while(ne < nodes-1)
    {
        min=infi;
        for(i=0;i<nodes;i++)
        {
            if(selected[i]==1)
			{
                for(j=0;j<nodes;j++)
				{
                    if(selected[j]==0)
					{
                        if(min > array[i][j])
                        {
                            min=array[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        selected[y]=1;
        cout<<"\n"<<x+1<<" --> "<<y+1;
        ne=ne+1;
    }
}

int main()
{
    prims MST;
    cout<<"Prims Algorithm to find Minimum Spanning Tree\n";
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}
