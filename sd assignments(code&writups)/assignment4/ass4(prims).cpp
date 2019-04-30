//NAME:SAKSHI KHODE  ROLL NO:223031  BATCH:C2

#include<iostream>
using namespace std;
void prim(int costmat[11][11],int n,int noofedges)
{
    int visited[n],i,dist[n],from[n],v,k=0;
    for(i=0;i<n;i++)
    {
        dist[i]=999;
        visited[i]=0;
    }
    dist[0]=0;
    visited[0]=1;
    from[0]=-1;
    int sum=0;
    int spanningtree[n][n]={0};
    for(i=1;i<n;i++)
    {
        dist[i]=costmat[0][i];
        from[i]=0;
    }
    for(int j=0;j<n;j++)
    {
        int min=999;
        for(i=0;i<n;i++)
        {
            if(dist[i]<min&&visited[i]==0)
            {
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        for(i=0;i<n;i++)
        {
            if(dist[i]>costmat[v][i]&&costmat[v][i]&&visited[i]==0)
            {
                dist[i]=costmat[v][i];
                from[i]=v;
            }
        }

    }
    for(i=1;i<n;i++)
    {
        cout<<"Minimum spanning tree"<<endl;
        cout<<"edge: "<<from[i]<<"-"<<i<<"\t"<<costmat[i][from[i]]<<endl;
    }

}



int main()
{
    int i,j,n,noofedges,costmat[11][11];
    cout<<"Enter total number of nodes:";
    cin>>n;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            costmat[i][j]=999;
        }
    }
    cout<<"Enter number of edges";
    cin>>noofedges;
    for(i=0;i<noofedges;i++)
    {
        int a,b,cost;
        cout<<"Enter the two nodes and corresponding cost";
        cin>>a>>b>>cost;
        costmat[a][b]=cost;
        costmat[b][a]=cost;
    }
    prim(costmat,n,noofedges);
    return 0;

}
