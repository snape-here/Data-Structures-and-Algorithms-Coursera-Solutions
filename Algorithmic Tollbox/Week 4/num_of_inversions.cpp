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
int b[N];

int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
}

int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left)
    { 
        mid = (right + left) / 2; 

        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 

        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
}

int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    { 
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 

    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 

    while (j <= right) 
        temp[k++] = arr[j++]; 

    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
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

    cout<<mergeSort(a,n)<<endl;
 
    return 0;
   
}