#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (x == 0 && n == 1) {
            cout << -1 << endl; // impossible to achieve x = 0 with 1 element
        } else if (x == 0) {
            cout << n << endl; // sum is n because we can use all 1s
        } else if (n == 1) {
            cout << x << endl; // only element must be x
        } else if (n == 2) {
            cout << x + 2 << endl; // for two elements, sum is x + 2
        } else {
            cout << x + n << endl; // for n > 2, sum is x + n
        }
    }
    return 0;
}
