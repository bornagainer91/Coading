#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100

using namespace std;

int n {};
int a[MAX_N] {};

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n);

    int iMaxCnt = INT_MIN;
    int iCnt {};

    for (int i = 0; i < n; i++)
    {        
        for (int j = i+1; j < n; j++)
        {            
            for (int k = a[i]+1; k < a[j]; k++)
            {
                if(abs(a[j] - k) == abs(k - a[i]))
                {
                    iCnt++;
                }
            }
            //iMaxCnt = max(iMaxCnt, iCnt);
        }
    }

    cout << iCnt << endl;

    return 0;
}