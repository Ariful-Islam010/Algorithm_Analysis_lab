#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    int prime[n+1];
    for (int i = 0; i <= n; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;

    for (int p = 2; p <= sqrt(n); p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }

    cout << "Prime numbers from 1 to " << n << ":\n";
    for (int p = 2; p <= n; p++) {
        if (prime[p] == 1)
            cout << p << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter the maximum number to find primes: ";
    cin >> n;
    SieveOfEratosthenes(n);
    return 0;
}
