//============================================================================
// Name        : dij_try.cpp
// Author      : agrima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int srch_min(int length[10],int set[10],int n)
{
	int i,min=9999,min_index;
	for(i=1;i<n;i++)
	{
		if(set[i]!=1)
		{
			if(length[i]<min)
			{
				min=length[i];
				min_index=i;
			}
		}
	}
	return min_index;
}
int dij(int a[10][10],int n,int v1,int v2)
{
	int length[10],set[10],path[10],s,z,i,j,tmp[10],c=0,f;
	s=v1;
	z=v2;
	for(int i=0;i<n;i++)
	{
		set[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[s][i]==0)
		{
			length[i]=999999;
			path[i]=0;
		}
		else
		{
			length[i]=a[s][i];
			path[i]=s;
		}
	}
	set[s]=1;
	length[s]=0;
	while(set[z]!=1)
	{
		j=srch_min(length,set,n);
		set[j]=1;
		for(i=0;i<n;i++)
		{
			if(set[i]!=1)
			{
				if(a[i][j]!=0)
				{
					if(length[j]+a[i][j]<length[i])
					{
						length[i]=length[j]+a[i][j];
						path[i]=j;
					}
				}

			}
		}

	}
	j=0;
	i=z;
	while(i!=s)
	{
		tmp[j]=path[i];
		i=path[i];
		j++;
		c++;
	}
	for(j=c-1;j>=0;j--)
	{
		cout<<"v->"<<tmp[j];
		if(tmp[j]==z)
			f=1;
	}
	if(f!=1)
	{
		cout<<"v"<<z;
	}
	return length[z];
}










int main() {
	int a[10][10],i,j,n,v1,v2,cost;
	cout << "enter the number of vertex in t graph" << endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"enter the weight between"<<i<<","<<j;
			cin>>a[i][j];
		}
	}
	cout<<"the entered matrix is :\n";
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
	cout<<"enter the starting vertex";
	cin>>v1;
	cout<<"enter the end vertex";
	cin>>v2;
	cost=dij(a,n,v1,v2);
	cout<<"the cost between"<<v1<<","<<v2;
	cout<<"\n"<<cost;

	return 0;
}

