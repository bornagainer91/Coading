#include <iostream>


using namespace std;

int main()
{
    int X {}, Y {};
    cin >> X >> Y;

    int iCnt {};

    for (int i=X; i<=Y; i++)
    {
        int rev {};
        int t = i;

        while (t > 0)
        {
            rev = rev * 10 + (t % 10);
            t /= 10;
        }
        if(rev == i)
        {
            iCnt++;
        }
    }

    cout << iCnt << endl;

    return 0;
}