#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n,a[N],b[N],k = 0,sz = 0;

//插入排序
//时间复杂度：最好情况O(n) 平均情况O(n^2) 最坏情况O(n^2)
//空间复杂度：O(1)
//算法稳定性：稳定
void insert_sort() 
{
    for(int i = 0; i < n;i++)
    {
        int t = a[i],j = i;
        while(j && t < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

//二分插入排序 相较于插入排序仅减少了比较次数但算法瓶颈在于移动次数
//时间复杂度：最好情况O(n) 平均情况O(n^2) 最坏情况O(n^2)
//空间复杂度：O(1)
//算法稳定性：稳定
void binary_search_insert_sort() 
{
    for(int i = 0;i < n;i++)
    {
        if(a[i] >= a[i - 1]) continue;
        int t = a[i];
        int l = 0,r = i - 1;
        while(r > l)
        {
            int mid = l + r >> 1;
            if(a[mid] > t) r = mid;
            else l = mid + 1;
        }
        for(int j = i;j > l;j--) a[j] = a[j - 1];
        a[l] = t;
    }
}

//冒泡排序
//时间复杂度：最好情况O(n) 平均情况O(n^2) 最坏情况O(n^2)
//空间复杂度：O(1)
//算法稳定性：稳定
void bubble_sort() 
{
    for(int i = 0;i < n - 1;i++)
    {
        bool flag = false;
        for(int j = n - 1;j > i;j--)
            if(a[j] < a[j - 1]) swap(a[j],a[j - 1]),flag = true;
        if(!flag) break;
    }
}

//选择排序
//时间复杂度：最好情况O(n^2) 平均情况O(n^2) 最坏情况O(n^2)
//空间复杂度：O(1)
//算法稳定性：不稳定
void select_sort() 
{
    for(int i = 0;i < n;i++)
    {
        int idx = i;
        for(int j = i + 1;j < n;j++)
            if(a[idx] > a[j]) idx = j;
        swap(a[idx],a[i]);
    }
}

//快速排序1 不保证划分点等于pivot
//时间复杂度：最好情况O(nlog(n)) 平均情况O(nlog(n)) 最坏情况O(n^2)
//空间复杂度：O(log(n))
//算法稳定性：不稳定
void quick_sort_1(int l,int r) 
{
    if(l >= r) return;
    int i = l - 1,j = r + 1,pivot = a[l + r >> 1];
    while(j > i)
    {
        do i++;while(a[i] < pivot);
        do j--;while(a[j] > pivot);
        if(j > i) swap(a[i],a[j]);
    }
    quick_sort_1(l,j);
    quick_sort_1(j + 1,r);
}

//快速排序2 保证划分点等于pivot
//时间复杂度：最好情况O(nlog(n)) 平均情况O(nlog(n)) 最坏情况O(n^2)
//空间复杂度：O(log(n))
//算法稳定性：不稳定
void quick_sort_2(int l,int r) 
{
    if(l >= r) return;
    int i = l,j = r,pivot = a[l];
    while(i < j)
    {
        while(i < j && a[j] >= pivot) j--;
        a[i] = a[j];
        while(i < j && a[i] < pivot) i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    quick_sort_2(l,i - 1);
    quick_sort_2(i + 1,r);
}

//归并排序
//时间复杂度：最好情况O(nlog(n)) 平均情况O(nlog(n)) 最坏情况O(nlog(n))
//空间复杂度：O(n)
//算法稳定性：稳定
void merge_sort(int l,int r) 
{
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l,mid);
    merge_sort(mid + 1,r);
    int i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r)
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = l,j = 0;i <= r;i++,j++) a[i] = b[j];
}

//堆排序
//时间复杂度：最好情况O(nlog(n)) 平均情况O(nlog(n)) 最坏情况O(nlog(n))
//空间复杂度：O(1)
//算法稳定性：不稳定
void down(int u) //向下调整以u为根节点的子树使其满足堆（小根堆）的性质
{
    int ls = u << 1,rs = u << 1 | 1,now = u;
    if(ls <= sz && a[ls] <= a[now]) now = ls; 
    if(rs <= sz && a[rs] <= a[now]) now = rs;
    if(u != now)
    {
        swap(a[u],a[now]);
        down(now);
    }
}

void heap_sort()
{
    for(int i = sz / 2;i;i--) down(i);
    while(sz)
    {
        cout << a[1] << ' ';
        a[1] = a[sz];
        down(1);
        sz--;
    }
}

int main()
{
    cin >> n;
    //for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> a[i],sz++;
    //insert_sort();
    //binary_search_insert_sort();
    //bubble_sort();
    //select_sort();
    //quick_sort_1(0,n - 1);
    //quick_sort_2(0,n - 1);
    //merge_sort(0,n-1);
    //heap_sort();
    for(int i = 0;i < n;i++) cout << a[i] << ' ';
    return 0;
}

