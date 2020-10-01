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
    int v[21];
    int sum=0;
    int flag1 =0, flag2 = 0;

    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }

    // Return 0 if the total sum isn't divisivle by 3.
    if(sum%3)
        cout<<0<<endl;
    // Check whether it's possible to obtain sum/3 and 2*sum/3 using Knapsack like Algo
    else
    {
        int x = sum/3;
        int y = (2*sum)/3;

        // Checking for sum/3
        int dp[x+1][n+1];

        for(int i=0; i<=x; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(i-v[j]>=0)
                        dp[i][j] = max(dp[i-v[j]][j-1] + v[j], dp[i][j-1]);
                    else
                        dp[i][j] = dp[i][j-1];
                }
            }
        }

        // Checking for 2*sum/3
        int dp1[y+1][n+1];

        for(int i=0; i<=y; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp1[i][j] = 0;
                else
                {
                    if(i-v[j]>=0)
                        dp1[i][j] = max(dp1[i-v[j]][j-1] + v[j], dp1[i][j-1]);
                    else
                        dp1[i][j] = dp1[i][j-1];
                }
            }
        }

        if(dp[x][n]==x && dp1[y][n]==y)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
 
    return 0;
   
}