/*
 * prims.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: system
 */




/*#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class prims
{

	int a[10][10],spantree[10][10],n;
	int visit[20],from[20],dist[20];
	public:
	void dir();
	void span();
}c;

void prims::dir()

{
	int v1,v2,i,j,w;
	char ch;
	cout<<"\n\nenter no of nodes: ";
	cin>>n;
	do
	{
		cout<<"enter the source vertex : ";
		cin>>v1;
		cout<<"\nenter the destination vertex: ";
		cin>>v2;
		cout<<"\nenter the weight of edge: ";
		cin>>w;
		a[v1][v2]=w;
		a[v2][v1]=w;
		cout<<"\n\ndo you want to continue?(Y/N): ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');

}

void prims::span()

{
	int u,v,y,i,ne,mindist,j,mincost;
	ne=0;
	mincost=0;
	cout<<"\nenter your starting vertex: ";
	cin>>v;
	visit[v]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			a[i][j]=9999;
		}
	}
	for(i=0;i<n;i++)
	{
		dist[i]=a[0][i];
	}
	while(ne<=n-1)
	{
		mindist=9999;
		for(i=0;i<n;i++)
		{
			if((visit[i]==0)&&(dist[i]<mindist))
			{
				v=i;
				mindist=dist[i];
			}
		}
		u=from[v];
		spantree[u][v]=dist[v];
		spantree[v][u]=dist[v];
		visit[v]=1;
		ne++;
		for(i=1;i<n;i++)
		{
			if((visit [i]==0)&&(a[i][v]<dist[i]))
			{
				dist[i]=a[i][v];
				from[i]=v;
			}
		}
		mincost+=mindist;
	}
	mincost=mincost-9999;
	cout<<"\nminimum spanning tree is: \n";
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<spantree[i][j];
		}
	}
	cout<<"\n\nminimum cost of spanning tree is: "<<mincost;

}

int  main()
{
	int ch;
	char f;
	//system("clear");
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t...minimum cost spanning tree using prim's algorithm....";

	do
	{
		cout<<"\n\nMENU: ";
		cout<<"\n\n\t1.create graph\n\n\t2.find minimum cost spanning tree\n\n\t3.exit";
		cout<<"\n\nenter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				c.dir();

			break;
			case 2:
				c.span();
			break;
			case 3:

			break;
			default:
				cout<<"\n\nplease enter valid choice.";
			break;
		}
		cout<<"\n\ndo you want to continue to main program (Y/N): ";
		cin>>f;
	}while(f=='Y' || f=='y' );
	return 0;

}
*/

/*#include<iostream>
#include<stdlib.h>
using namespace std;

class prims
{
private:
int a[10][10],spantree[10][10],n;
int visit[20],from[20],dist[20];
public:
void dir();
void span();
}c;

void prims::dir()

{
int v1,v2,i,j,w;
int ch;
cout<<"\nEnter Number of HOUSES: ";
cin>>n;
do
{
cout<<"\nEnter the Source vertex:" ;
cin>>v1;
cout<<"\nEnter The Destination Vertex:" ;
cin>>v2;
cout<<"\nEnter The Weight Of Edge:";
cin>>w;
a[v1][v2]=w;
a[v2][v1]=w;
cout<<"\nDo You Want To Continue?(1): " ;

cin>>ch;
}while(ch==1);

}

void prims::span()

{
int u,v,y,i,ne,mindist,j,mincost;
ne=0;
mincost=0;
cout<<"\nEnter Your Starting vertex: ";
cin>>v;
cout<<"path ="<<v<<"\t";
visit[v]=1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]==0)
a[i][j]=9999;
}
}
for(i=0;i<n;i++)
{
dist[i]=a[0][i];
}
while(ne<=n-1)
{
mindist=9999;
for(i=0;i<n;i++)
{
if((visit[i]==0)&&(dist[i]<mindist))
{
v=i;
mindist=dist[i];
}
}
u=from[v];
spantree[u][v]=dist[v];
spantree[v][u]=dist[v];
visit[v]=1;
ne++;
for(i=1;i<n;i++)
{
if((visit [i]==0)&&(a[i][v]<dist[i]))
{
dist[i]=a[i][v];
from[i]=v;
cout<<v<<"\t";
}

}
mincost+=mindist;
}
mincost=mincost-9999;
cout<<"\nMinimum Spanning Tree is:\n";
for(i=0;i<n;i++)
{
cout<<"\n";
for(j=0;j<n;j++)
{
cout<<"\t"<<spantree[i][j];
}
}
cout<<"\n\nMinimum cost of Spanning tree is: " <<mincost;

}
int main()
{
int ch;




do
{
cout<<"\n\n MENU: ";
cout<<"\n\n\t1.Create SOciety\n\n\t2.Find Minimum Cost Spanning Tree\n\n\t3.Exit";

cout<<"\n\nEnter Your Choice:  ";
cin>>ch;
switch(ch)
{
case 1:
c.dir();

break;
case 2:
c.span();
break;

default:
cout<<"\n\nPlease Enter Valid choice.";
break;
}


}while(ch!=3);

}*/
/* Program for creating minimum spanning tree from Prim's algorithm */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAX 10
#define TEMP 0
#define PERM 1
#define FALSE 0
#define TRUE 1
#define infinity 9999

struct node
{
	int predecessor;
	int dist; /*Distance from predecessor */
	int status;
};

struct edge
{
	int u;
	int v;
};

int adj[MAX][MAX];
int n;


void create_graph()
{
	int i,max_edges,origin,destin,wt;

	cout<<"Enter number of vertices : ";
	cin>>n;
	max_edges=n*(n-1)/2;

	for(i=1;i<=max_edges;i++)
	{
		cout<<"Enter edge (0 0 to quit) : "<<i;
		cin>>origin>>destin;
		if((origin==0) && (destin==0))
			break;
		cout<<"Enter weight for this edge : ";
		cin>>wt;
		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=wt;
			adj[destin][origin]=wt;
		}
	}/*End of for*/
	if(i<n-1)
	{
		cout<<"Spanning tree is not possible\n";

	}
}/*End of create_graph()*/


/*This function returns TRUE if all nodes are permanent*/
int all_perm(struct node state[MAX] )
{
	int i;
	for(i=1;i<=n;i++)
	   if( state[i].status == TEMP )
	       return FALSE;
	return TRUE;
}/*End of all_perm()*/


void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<adj[i][j];
		cout<<"\n";
	}
}/*End of display()*/

int maketree(struct edge tree[MAX],int *weight)
{
	struct node state[MAX];
	int i,k,min,count,current,newdist;
	int m;
	int u1,v1;
	*weight=0;
	/*Make all nodes temporary*/
	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = infinity;
		state[i].status = TEMP;
	}
	/*Make first node permanent*/
	state[1].predecessor=0;
	state[1].dist = 0;
	state[1].status = PERM;

	/*Start from first node*/
	current=1;
	count=0; /*count represents number of nodes in tree */
	while( all_perm(state) != TRUE ) /*Loop till all the nodes become PERM*/
	{
		for(i=1;i<=n;i++)
		{
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				if(  adj[current][i] < state[i].dist )
				{
					state[i].predecessor = current;
					state[i].dist = adj[current][i];
				}
			}
		}/*End of for*/

		/*Search for temporary node with minimum distance
		and  make it current node*/
		min=infinity;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist < min)
			{
				min = state[i].dist;
				current=i;
			}
		}/*End of for*/

		state[current].status=PERM;

		/*Insert this edge(u1,v1) into the tree */
		u1=state[current].predecessor;
		v1=current;
		count++;
		tree[count].u=u1;
		tree[count].v=v1;
		/*Add wt on this edge to weight of tree	*/
		*weight=*weight+adj[u1][v1];
	}/*End of while*/
	return (count);
}/*End of maketree()*/



int main()
{
	int i,j;
	int path[MAX];
	int wt_tree,count;
	struct edge tree[MAX];

	create_graph();
	cout<<"Adjacency matrix is :\n";
	display();

	count = maketree(tree,&wt_tree);

	cout<<"Weight of spanning tree is : %d\n"<< wt_tree;
	cout<<"Edges to be included in spanning tree are : \n";
	for(i=1;i<=count;i++)
	{
		cout<<"v->"<<tree[i].u;
		cout<<"%d\n"<<tree[i].v;
	}
}/*End of main()*/



