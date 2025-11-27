#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int X, Y;

int main()
{
    cin >> X >> Y;

    int iMax = INT_MIN;

    for (int i=X; i<=Y; i++)
    {
        int sum = 0;
        int t = i;
        while(t > 0)
        {
            sum += t % 10;
            t /= 10;
        }

        iMax = max(iMax, sum);
    }

    cout << iMax << endl;

    return 0;
}