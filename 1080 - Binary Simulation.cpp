#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

/**------- ShortCuts----------*/
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<int, int>        pii;
typedef pair<ll, ll>          pll;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<ll>            vl;
typedef vector<pii>           vii;
typedef vector<iii>           viii;
typedef vector<vi>            vvi;
typedef map<int, int>         mapii;
typedef map<int, bool>        mapib;
typedef map<int, string>      mapis;
typedef set<int>              seti;

/**------- Char Chk----------*/
bool isLow(char ch) { if (ch >= 'a' && ch <= 'z') return true; return false; }
bool isUpp(char ch) { if (ch >= 'A' && ch <= 'Z') return true; return false; }
bool isDig(char ch) { if (ch >= '0' && ch <= '9') return true; return false; }

/**------- Scanf----------*/
#define sf                 scanf
#define sfi(a)             scanf("%d", &a)
#define sfc(a)             scanf("%c", &a)
#define sfl(a)             scanf("%lld", &a)
#define sfu(a)             scanf("%llu", &a)
#define sfs(a)             scanf("%s", a)
#define sfd(a)             scanf("%lf", &a)

#define sfii(a, b)         scanf("%d %d", &a, &b)
#define sfll(a, b)         scanf("%lld %lld", &a, &b)
#define sfuu(a, b)         scanf("%llu %llu", &a, &b)
#define sfdd(a, b)         scanf("%lf %lf", &a, &b)

#define sfiii(a, b, c)     scanf("%d %d %d", &a, &b, &c)
#define sflll(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define sfuuu(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)
#define sfddd(a, b, c)     scanf("%lf %lf %lf", &a, &b, &c)

/**------- Printf----------*/
#define pf                 printf
#define pfig(a)            pf("%d ", a)
#define pfgap              pf(" ")
#define pfi(a)             printf("%d\n", a)
#define pfc(a)             printf("%c\n", a)
#define pfl(a)             printf("%lld\n", a)
#define pfu(a)             printf("%llu\n", a)
#define pfs(a)             printf("%s\n", a)
#define pfd(a)             printf("%.2lf\n", a)

#define pfii(a, b)         printf("%d %d\n", a, b)
#define pfll(a, b)         printf("%lld %lld\n", a, b)
#define pfuu(a, b)         printf("%llu %llu\n", a, b)
#define pfdd(a, b)         printf("%.2lf %.2lf\n", a, b)

#define pfiii(a, b, c)     printf("%d %d %d\n", a, b, c)
#define pflll(a, b, c)     printf("%lld %lld %lld\n", a, b, c)
#define pfuuu(a, b, c)     printf("%llu %llu %llu\n", a, b, c)
#define pfddd(a, b, c)     printf("%.2lf %.2lf %.2lf\n", a, b, c)
#define pnl                printf("\n")

/**--------File------------*/
#define output             freopen("output.txt","w",stdout)
#define input              freopen("input.txt","r",stdin)
#define inOut              input; output

/**--------Constant------------*/
#define mx2                101
#define mx3                1001
#define mx4                10001
#define mx5                100001
#define mx6                1000001
#define fr0(i, n)          for(int i=0; i<n; i++)
#define fr1(i, n)          for(int i=1; i<=n; i++)
#define ff                 first
#define se                 second
#define pb                 push_back
#define all(x)             x.begin(), x.end()
#define INF                0x3f3f3f3f
#define eps                1e-9
#define ABS(a)             (a)>=0 ? (a) : (-a)
#define PI                 acos(-1.0)
#define sq(x)              (x)*(x)
#define gap                " "
#define gapf               << " " <<
#define nl                 << "\n"
#define cinIg              cin.sync(); cin.get()
#define FasterIO           ios_base::sync_with_stdio(0);cin.tie(0)
#define UNIQ(a)            sort(all(a));a.erase(unique(all(a)),a.end())
#define mem(x, y)          memset(x, y, sizeof(x))
#define TestCases          int cases, tc; sfi(tc); \
                           for(cases=1; cases<=tc; cases++)
#define TestCasespp        int cases, tc; cin>>tc; \
                           for(cases=1; cases<=tc; cases++)

/**--------DeBug------------*/
#define watch(x)           cout<<(#x)<<" is "<<x<<"\n"
#define chk                cout<<"Wtf"<<"\n"

int n, q;
char str[mx5];
int tree[4 * mx5];
bool lazy[4 * mx5];

#define left(p)     (p<<1)
#define right(p)    (p<<1)+1
#define mid(l,r)    (l)+((r-l)>>1)

void build(int p, int l, int r) {
	if (l == r) {
		tree[p] = (str[l] == '1');
	}
	else {
		build(left(p), l, mid(l, r));
		build(right(p), mid(l, r) + 1, r);
		tree[p] = max(tree[left(p)], tree[right(p)]);
	}
	lazy[p] = false;
}

void update(int p, int l, int r, int i, int j) {
	if (lazy[p]) {
		tree[p] = !tree[p];
		if (l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		else str[l] = str[l] == '0' ? '1' : '0';
		lazy[p] = false;
	}

	if (l>r || l>j || r<i) return;
	if (l >= i && r <= j) {
		tree[p] = !tree[p];
		if (l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		else str[l] = str[l] == '0' ? '1' : '0';
		return;
	}

	update(left(p), l, mid(l, r), i, j);
	update(right(p), mid(l, r) + 1, r, i, j);
	tree[p] = max(tree[left(p)], tree[right(p)]);
}

int query(int p, int l, int r, int idx) {
	if (lazy[p]) {
		tree[p] = !tree[p];
		if (l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		else str[l] = str[l] == '0' ? '1' : '0';
		lazy[p] = false;
	}

	if (l == r && l == idx) return tree[p];
	if (idx <= mid(l, r))
		return query(left(p), l, mid(l, r), idx);
	return query(right(p), mid(l, r) + 1, r, idx);
}

int main()
{
	//    inOut;
	TestCases{
		sfs(str); n = strlen(str);
	build(1, 0, n - 1);
	pf("Case %d:\n", cases);
	sfi(q); while (q--) {
		char q[2];
		sfs(q);
		if (q[0] == 'I') {
			int u, v;
			sfii(u, v);
			update(1, 0, n - 1, u - 1, v - 1);
		}
		else {
			int idx; sfi(idx);
			pfi(query(1, 0, n - 1, idx - 1));
		}
	}
	}

	return 0;
}