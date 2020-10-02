#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define inf 300000000000000007
#define endl "\n"

const int N = 1e5+5;

int a[N];

vector<int> quick_sort_partition3(int a[], int l, int r)
{
    int x = a[l];
    int p_l = l;
    int i = l;
    int p_e = r;
    vector<int> m(2);
    while (i <= p_e)
    {
        if (a[i] < x)
        {
            swap(a[p_l], a[i]);
            p_l++;
            i++;
        }
        else if (a[i] == x)
            i++;
        else
        {
            swap(a[i], a[p_e]);
            p_e -= 1;
        }
        m[0] = p_l;
        m[1] = p_e;
    }
    return m;
}

void randomized_quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m = quick_sort_partition3(a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];

    randomized_quick_sort(a, 0, n - 1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
 
    return 0;
   
}