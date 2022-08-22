#include <iostream>
using namespace std;

int main()
{
    int i = 1, j = 1, k = 0, n;
    char ch = 'A';
    cin >> n;
    while (i <= n)
    {
        j = 1;
        // k = i;
        while (j <= n)
        {
            cout << (char)(ch + i - 1);
            j = j + 1;
            // k = k + 1;
        }
        cout << "\n";
        i = i + 1;
    }
}