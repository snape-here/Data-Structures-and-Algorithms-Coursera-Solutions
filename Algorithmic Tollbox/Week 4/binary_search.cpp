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

int bin_search(int a[], int n, int x)
{
    int lo = 0;
    int hi = n-1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(a[mid]>x)
            hi = mid-1;
        else if(a[mid]<x)
            lo = mid+1;
        else
            return mid;
    }
    return -1;
}
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    int b[k];
    for(int i=0; i<k; i++)
        cin>>b[i];

    for(int i=0; i<k; i++)
        cout<<bin_search(a,n,b[i])<<" ";
 
    return 0;
   
}