#include <iostream>
using namespace std;

int main() {
    int i, j, n, maxWeight;

    cout << "Enter number of items: ";
    cin >> n;

    int profit[n + 1], weight[n + 1];

    // 1-based indexing
    profit[0]=0;
    weight[0]=0;

    cout<<"Enter profits of items:\n";
    for (i=1;i<=n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights of items:\n";
    for (i=1;i<=n;i++) {
        cin >> weight[i];
    }

    cout << "Enter maximum weight capacity: ";
    cin >> maxWeight;

    int dp[n + 1][maxWeight + 1];

    // Initialize the table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= maxWeight; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i]<=j) {
                dp[i][j] = max(profit[i] + dp[i - 1][j-weight[i]],dp[i-1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print DP Table
    cout << "\nDP Table:\n";
    for (i = 0; i<= n; i++) {
        for (j = 0; j <= maxWeight; j++) {
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }

    cout << "\nMaximum profit that can be taken is: " << dp[n][maxWeight] << endl;

    return 0;
}

