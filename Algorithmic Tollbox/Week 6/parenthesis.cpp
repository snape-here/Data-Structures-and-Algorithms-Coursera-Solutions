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

int eval(int a, int b, char op) {
    if (op == '*')
        return (a * b);
    else if (op == '+')
        return (a + b);
    else if (op == '-')
        return (a - b);
    else
        assert(0);
}

int get_max_val(const string &exp) {
    int length = exp.size();
    int n = (length + 1) / 2;
    int MIN[n][n]={0};
    int MAX[n][n]={0};

    for (int i=0; i<n; i++)
    {
        MIN[i][i] = std::stoll(exp.substr(2*i,1));
        MAX[i][i] = std::stoll(exp.substr(2*i,1));
    }

    for (int s = 0; s<n-1; s++)
    {
        for (int i=0; i<n-s-1; i++)
        {
            int j = i+s+1;
            int mn = inf;
            int mx = -inf;
            for (int k = i; k < j; k++)
            {
                int a = eval(MIN[i][k],MIN[k+1][j],exp[2*k+1]);
                int b = eval(MIN[i][k],MAX[k+1][j],exp[2*k+1]);
                int c = eval(MAX[i][k],MIN[k+1][j],exp[2*k+1]);
                int d = eval(MAX[i][k],MAX[k+1][j],exp[2*k+1]);
                mn = min(mn,min(a,min(b,min(c,d))));
                mx = max(mx,max(a,max(b,max(c,d))));
            }

            MIN[i][j] = mn;
            MAX[i][j] = mx;
        }
    }
    return MAX[0][n-1];
}
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    string s;
    cin>>s;

    cout<<get_max_val(s)<<endl;
 
    return 0;
   
}