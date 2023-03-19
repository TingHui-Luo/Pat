//
// Created by Dell on 2022-04-08.
//

il int prim()
{
    //先把dis数组附为极大值
    for(re int i=2;i<=n;++i)
    {
        dis[i]=inf;
    }
    //这里要注意重边，所以要用到min
    for(re int i=head[1];i;i=e[i].next)
    {
        dis[e[i].v]=min(dis[e[i].v],e[i].w);
    }
    while(++tot<n)//最小生成树边数等于点数-1
    {
        re int minn=inf;//把minn置为极大值
        vis[now]=1;//标记点已经走过
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(re int i=1;i<=n;++i)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
                now=i;
            }
        }
        ans+=minn;
        //枚举now的所有连边，更新dis数组
        for(re int i=head[now];i;i=e[i].next)
        {
            re int v=e[i].v;
            if(dis[v]>e[i].w&&!vis[v])
            {
                dis[v]=e[i].w;
            }
        }
    }
    return ans;
}

il void kruskal()
{
    sort(edge,edge+m,cmp);
    //将边的权值排序
    for(re int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //若出现两个点已经联通了，则说明这一条边不需要了
        ans+=edge[i].w;
        //将此边权计入答案
        fa[ev]=eu;
        //将eu、ev合并
        if(++cnt==n-1)
        {
            break;
        }
        //循环结束条件，及边数为点数减一时
    }
}