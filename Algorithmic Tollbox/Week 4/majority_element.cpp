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

int get_majority_element(int arr[], int left, int right)
{
    if (left == right)
        return -1;
    if (left + 1 == right)
        return a[left];

    int left_elem = get_majority_element(a, left, (left + right - 1) / 2 + 1);
    int right_elem = get_majority_element(a, (left + right - 1) / 2 + 1, right);

    int lcount = 0;

    for (int i = left; i < right; i++)
        if (a[i] == left_elem)
            lcount += 1;

    if (lcount > (right - left) / 2)
        return left_elem;

    int rcount = 0;
    for (int i = left; i < right; i++)
        if (a[i] == right_elem) rcount += 1;

    if (rcount > (right - left) / 2)
        return right_elem;

    return -1;
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

    if (n==1)
        cout<<1<<endl;
    else
        cout<<(get_majority_element(a,0,n) != -1)<<endl;
 
    return 0;
   
}