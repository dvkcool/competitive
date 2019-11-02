#include <bits/stdc++.h>
using namespace std;
int a[21];
int modMax = 1000000007;
int largestPower(int n, int p)
{
    // Initialize result
    int x = 0;

    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n) {
        n /= p;
        x += n;
    }
    return x;
}

// Utility function to do modular exponentiation.
// It returns (x^y) % p
int power(int x, int y, int p)
{
    int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int factmod(int n) {
  int p = modMax;
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
// Returns n! % p
int modFact(int n)
{
  int p = modMax;
    if (n >= p){
      //cout<<"called me"<<endl;
      return 0;
    }


    int res = 1;

    // Use Sieve of Eratosthenes to find all primes
    // smaller than n
    bool isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

    // Consider all primes found by Sieve
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            // Find the largest power of prime 'i' that divides n
            int k = largestPower(n, i);

            // Multiply result with (i^k) % p
            res = (res * power(i, k, p)) % p;
        }
    }
    return res;
}

// Returns nCr % p. In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModpDP(int n, int r, int p)
{
	// The array C is going to store last row of
	// pascal triangle at the end. And last entry
	// of last row is nCr
	int C[r+1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // Top row of Pascal Triangle

	// One by constructs remaining rows of Pascal
	// Triangle from top to bottom
	for (int i = 1; i <= n; i++)
	{
		// Fill entries of current row using previous
		// row values
		for (int j = min(i, r); j > 0; j--)

			// nCj = (n-1)Cj + (n-1)C(j-1);
			C[j] = (C[j] + C[j-1])%p;
	}
	return C[r];
}

// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function. First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p)
{
// Base case
if (r==0)
	return 1;

// Compute last digits of n and r in base p
int ni = n%p, ri = r%p;

// Compute result for last digits computed above, and
// for remaining digits. Multiply the two results and
// compute the result of multiplication in modulo p.
return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
		nCrModpDP(ni, ri, p)) % p; // Remaining digits
}

int completeTree(int n){
  int eve = n/2;
  int od = eve;
  if(n%2 !=0){
    od++;
  }
  return ((long long int)((long long int)factmod(eve) * (long long int)factmod(od)))%modMax;
}
void calc(int o, int e, int pairoe, int lf, int n){
  int et = completeTree(n);
  //cout << lf<<" lf"<<endl;
  //cout << et<<"et"<<endl;
  int lfpair = lf/2;
  //odd root
  int x = (nCrModpLucas(lfpair, o-pairoe-1, modMax)*nCrModpLucas(lfpair, e-pairoe, modMax))%modMax;
  //cout<<lfpair<<" " <<pairoe<<" "<<o-pairoe-1<<" "<<e-pairoe<<endl;
  //cout << x<<"odd"<< endl;
  // even root
  x = (x + (nCrModpLucas(lfpair, e-pairoe-1, modMax) * nCrModpLucas(lfpair, o-pairoe, modMax))%modMax)%modMax;
  //cout<<lfpair<<" " <<e-pairoe-1<< " "<<o-pairoe<<endl;
  //cout <<x<<"even"<<endl;
  x = (x * et)%modMax;
  cout << x<< endl;
}

void solve(){
  int n;
  cin >> n;
  if(n==1){
    cout<<1<<endl;
    return;
  }
  int h=1;
  for(h=1; h<21; h++){
    if(a[h]>=n)
    break;
  }
  if(a[h]+1==n){
    cout<< completeTree(n)<<endl;
    return;
  }

  if(a[h]==n){
    h++;
  }
  int lf = a[h-1];//leaf nodes
  int pairoe = (lf-1)/2;//pair of odd, even in complete tree
  // complete tree = pairoe*odd + pairoe*even + root-node
  int e = n/2;
  int o = e;
  if(n%2 !=0){
    o++;
  }
  calc(o, e, pairoe, lf, n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  a[0]= 1;
  for(int i=1; i<21; i++){
    a[i] = 2*a[i-1];
  }
	int cases;
	cin >> cases;
	for(int i=0; i<cases; ++i)
		solve();
	return 0;
}
