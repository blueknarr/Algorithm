#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m;
int arr[10];
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
 
    for (int i = cnt; i < n; i++)
    {
        if (vc.size() < m)
        {
            vc.push_back(arr[i]);
            dfs(i + 1);
            vc.pop_back();
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    dfs(0);
    return 0;
}