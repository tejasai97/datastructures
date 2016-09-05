#include<iostream>
using namespace std;
class DFS
{
private:
	int **b,*queue,*visited,*visit,k,m,v,front,rear,n,p,q,size2,size3,size4;
public:
	void input();
};
void DFS::input()
{	int j,i,rear=front=0;
	cout<<"enter p and q";
	cin>>p>>q;
	b=new int*[p];
	for(int i=0;i<p;i++)
	{
		b[i]=new int [q];
	}
	cout<<"enter the size of visited node";
	cin>>size2;
	visited=new int[size2];
	cout<<"enter the size of visit";
	cin>>size3;
	visit=new int[size3];
	cout<<"enter the size of stack";
	cin>>size4;
	queue=new int[size4];
	cout <<"enterno of vertices";
	cin >> n;
	cout <<"ente no of edges";
	cin >> m;
	cout <<"\nEDGES \n";
	for(k=1;k<=m;k++)
	{
		cin >>i>>j;
		b[i][j]=1;
	}

	cout <<"enter initial vertex";
	cin >>v;
	cout <<"Visitied vertices\n";
	cout << v;
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j=1;j<=n;j++)
		if(b[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
		{
			visit[j]=1;
			queue[rear++]=j;
		}
			v=queue[front++];
			cout<<v << " ";
			k++;
			visit[v]=0;
			visited[v]=1;
		}
}

int main()
{
	DFS d;
	d.input();
	return 0;
}



