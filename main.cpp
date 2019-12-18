#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,m,a,b,o,s,end=0;
        cin>>n>>r>>m;
        int i,j;
        vector<int> graph[n+1];
        vector<int> vis(n+1);
        for(i=0;i<=n;i++)
        {
            vis[i]=0;
        }
        vector<pair<int,int> > soldier(m);
        for(i=0;i<r;i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(i=0;i<m;i++)
        {
            cin>>o>>s;
            soldier[i]=make_pair(o,s);
        }
        vector<int> parent(n+1,0);
        for(i=0;i<m;i++)
        {
            pair<int,int> p=soldier[i];
            queue<pair<int,int> > q;
            q.push(p);
            vis[p.first]++;
            if(vis[p.first]>1)
            {
                end=1;
                break;
            }
            while(!q.empty())
            {
                pair<int,int> tmp=q.front();
                q.pop();
                vector<int> :: iterator ir;
                for(ir=graph[tmp.first].begin();ir!=graph[tmp.first].end();ir++)
                {
                    if(*ir!=parent[tmp.first]&&tmp.second!=0&&vis[*ir]==0)
                    {
                        q.push(make_pair(*ir,(tmp.second)-1));
                        parent[*ir]=tmp.first;
                        vis[*ir]++;
                    }
                    else if(vis[*ir]>1)
                    {
                        end=1;
                        break;
                    }
                }
                if(end==1)
                    break;
            }
            if(end==1)
                break;
        }
        int flag=0;
        if(end==1)
            cout<<"No"<<endl;
        else
        {for(i=1;i<=n;i++)
        {
            //cout<<vis[i]<<endl;
            if(vis[i]==1)
            {
                flag++;
            }
        }
        if(flag==n)
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        }
    }
}
