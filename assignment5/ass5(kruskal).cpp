//NAME:SAKSHI KHODE  ROLL NO:223031  BATCH:C2

/*You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities.
You want a set of lines that connects all your offices with a minimum total cost.
 Solve the problem by suggesting appropriate data structures*/
#include <iostream>
using namespace std;
#define V 5
int parent[V];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void kruskalMST(int cost[][V])
{
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        cout<<"Edge "<< edge_count++<<":"<<a<<"-"<<b<<" cost: "<<min<<endl;
        mincost += min;
    }
    cout<<"\n Minimum cost= "<< mincost;
}
int main()
{
   int i,j,n,noofedges,costmat[V][V];
    cout<<"Enter total number of offices:";
    cin>>n;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            costmat[i][j]=999;
        }
    }
    cout<<"Enter number of phone lines";
    cin>>noofedges;
    for(i=0;i<noofedges;i++)
    {
        int a,b,cost;
        cout<<"Enter the two cities and corresponding cost";
        cin>>a>>b>>cost;
        costmat[a][b]=cost;
        costmat[b][a]=cost;
    }
    kruskalMST(costmat);

    return 0;
}
