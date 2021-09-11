#include <bits/stdc++.h>
using namespace std;

#define rep(i, n, m) for (int i = n; i < m; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define desc_sort(v) sort(v.rbegin(), v.rend())
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define ios                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define M 1000000007
#define pushll(head, d) push_into_linkedlist(&head, d)
#define popll(head) dp_delete_first(&head)
#define eol cout << "\n"
#define N 1000000

typedef long long ll;
typedef long double ld;

const ld PI = 3.141592653589793;
// #define int long long

// #ifdef _DEBUG
// //  freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif


// ifstream fin;
//   fin.open("RARBG.txt");
//   string n;
//   while(fin)
//   {
//     fin>>n;
//     cout<<n<<" ";
//   }
//   fin.close(); 

int solve()  
{
    string s;
    int k,n;
    cin>>n>>k>>s;
    int curr=0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            curr++;
    }
return abs(curr-k);
  
}


signed main(int argc, char *argv[])
{
  ios int t = 1;
  cin >> t;
  int T=t;
  while (t--)
  {
    cout << "Case #"<<T-t<<": "<<solve()<<endl;
  }
}
