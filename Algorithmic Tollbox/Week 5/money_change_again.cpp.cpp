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
#define endl "\n"
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    int coins[3] = {1,3,4};

    int m;
    cin>>m;

    int dp[m+1];

    dp[0] = 0;

    for(int i=1; i<=m; i++)
    {
        if(i<3)
            dp[i] = dp[i-1] + 1;
        else if(i<4)
            dp[i] = min(dp[i-1], dp[i-3]) + 1;
        else
            dp[i] = min(dp[i-1], min(dp[i-3], dp[i-4])) + 1;
    }

    cout<<dp[m]<<endl;
 
    return 0;
   
}