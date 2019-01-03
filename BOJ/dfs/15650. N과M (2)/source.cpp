​#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int n, m;
 
vector<int> vc;
void dfs(int cnt)
{
    if (vc.size() == m)
    {
        for (auto i : vc)
            printf("%d ", i);
        printf("\n");
        return;
    }
 
    for (int i = cnt; i <= n; i++)
    {
        if (vc.size() < m)
        {
            vc.push_back(i);
            dfs(i + 1);
            vc.pop_back();
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
 
    dfs(1);
    return 0;
}