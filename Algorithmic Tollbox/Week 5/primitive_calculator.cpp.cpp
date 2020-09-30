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

    int n;
    cin>>n;

    int dp[n+1];

    dp[1] = 0;

    for(int i=2; i<=n; i++)
    {
        if(i<3)
            dp[i] = dp[i-1] + 1;
        else
        {
            if(i%3==0)
                dp[i] = min(dp[i-1], dp[i/3]) + 1;
            else if(i%2==0)
                dp[i] = min(dp[i-1], dp[i/2]) + 1;
            else
                dp[i] = dp[i-1] + 1;
        }
        //cout<<dp[i]<<" ";
    }

    vector<int> ans;

    ans.pb(n);

    int dup = n;

    int count = dp[dup];

    while(n>1)
    {
        int x = min(dp[n-1], min(dp[n/2], dp[n/3]));
        if(n%2==0 && dp[n/2]==x)
            n/=2;
        else if(n%3==0 && dp[n/3]==x)
            n/=3;
        else
            n--;
        ans.pb(n);
    }

    reverse(ans.begin(), ans.end());

    cout<<count<<endl;

    for(int i : ans)
        cout<<i<<" ";
 
    return 0;
   
}