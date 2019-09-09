        #include <bits/stdc++.h>
        typedef long long int lli;
        typedef unsigned long long int ulli;
        typedef long double ldb;
         
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/tree_policy.hpp>
        using namespace __gnu_pbds;
         
        #define pb push_back
        #define popb pop_back()
        #define pf push_front
        #define popf pop_front()
        #define si size()
        #define be begin()
        #define en end()
        #define all(v) v.be, v.en
        #define le length()
        #define mp make_pair
        #define mt make_tuple
        #define F first
        #define S second
         
        #define forz(i, n) for (int i = 0; i < n; i++)
        #define forzm(i, m, n) for (int i = m; i < n; i++)
        #define rforz(i, n) for (int i = n - 1; i >= 0; i--)
        #define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)
        #define deci(n) fixed << setprecision(n)
        #define high(n) __builtin_popcount(n)
        #define parity(n) __builtin_parity(n)
        #define ctz(n) __builtin_ctz(n)
        #define lb lower_bound
        #define ub upper_bound
        #define er equal_range
        #define maxe *max_element
        #define mine *min_element
        #define mod 1000000007
        #define mod2 998244353
        #define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
         
        #define endl "\n"
        #define p0(a) cout << a << " "
        #define p1(a) cout << a << endl
        #define p2(a, b) cout << a << " " << b << endl
        #define p3(a, b, c) cout << a << " " << b << " " << c << endl
        #define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
         
        #define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
        #define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
        //member functions :
        //1. order_of_key(k) : number of elements strictly lesser than k
        //2. find_by_order(k) : k-th element in the set
        #define ofk order_of_key
        #define fbo find_by_order
        using namespace std;
         
        /*STD fucntions*/
        lli power(lli x, lli y, lli p)
        {
            lli res = 1;
            x = x % p;
            while (y > 0)
            {
                if (y & 1)
                    res = (res * x) % p;
                //y must be even now
                y = y >> 1; //y=y/2
                x = (x * x) % p;
            }
            return res;
        }
        lli gcd(lli a, lli b)
        {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }
        lli lcm(lli a, lli b)
        {
            return a * b / gcd(a, b);
        }
        lli modi(lli a, lli m)
        {
            // fermat little thm where m is prime
            return power(a, m - 2, m);
        }

        bool compare(string a, string b)
        {
            lli x= a.si;
            lli y= b.si;
            if(a+b>b+a)
            {
                return 0;
            }
            else 
            {
                return 1;
            }
        }

void merge(string arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    string L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (compare(L[i], R[j])==0)
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(string arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
        
         
        int main()
        {
            lli s;
            cin>> s;
            while(s--)
            {
                lli x;
                cin>> x;
                vector <pair <string, string> > v;
                string s[x];
                lli maxl=0;
                for(lli i=0; i<x; i++)
                {
                    cin>> s[i];
                }
                mergeSort(s, 0, x-1);
                for(lli i=0; i<x; i++)
                {
                    cout<< s[i];
                }

            }
         
           
            
        }
