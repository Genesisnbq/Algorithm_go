#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    cout << n / 5 + (n % 5 ? 1 : 0) << endl;

    return 0;
}