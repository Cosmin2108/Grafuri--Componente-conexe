#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
ifstream f("dfs.in");
ofstream g("dfs.out");

void DFS (int node, vector<int> *graf,int *viz)
{
  viz[node]=1;
  int lim=graf[node].size();
  for(int i=0;i<lim;i++)
  {
      int vecin=graf[node][i]; ///merg pe vecini
      if(!viz[vecin])
        DFS(vecin,graf,viz);
  }

}

int main()
{
    int n,m,x,y;
    f>>n>>m;
    cout<<n<<" "<<m;
    vector< int> graf[n+1];
    int viz[n+1];
    int i;
    for(i=1;i<=n;i++)
        viz[i]=0;

    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        graf[x].push_back(y);
        graf[y].push_back(x);

    }
    int nr=0;
    cout<<"Crapa";
    for(i=1;i<=n;i++)
    {
        if(viz[i]==0)
        {
         DFS(i,graf,viz);
         nr++;
        }

    }
    g<<nr;
    return 0;
}
