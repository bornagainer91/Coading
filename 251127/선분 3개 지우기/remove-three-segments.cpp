#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 10
#define MAX_AB 100

using namespace std;

int n {};
int l[MAX_N] {}, r[MAX_N] {};
int lr[MAX_N][2] {};


int GetMaxOverlappedCnt(int i1, int i2, int i3)
{
    int counting[MAX_AB+1] {};
    for(int i = 0; i < n; i++)
    {
        if(i == i1 || i == i2 || i == i3)
        {
            continue;
        }

        int x1 = lr[i][0], x2 = lr[i][1];
        for(int j = x1; j <= x2; j++)
        {
            counting[j]++;
        }
    }

    int max_cnt = 0;

    for(int j = 0; j <= MAX_AB; j++)
    {
        max_cnt = max(max_cnt, counting[j]);
    }

    return max_cnt;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        for (int j=0; j<2; j++)
        {
            if (j==0) lr[i][j] = l[i];
            if (j==1) lr[i][j] = r[i];
        }
    }

    int iCnt {};

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {

                // cout << GetMaxOverlappedCnt(i, j, k) << endl;
                if(GetMaxOverlappedCnt(i, j, k) == 1)
                {
                    iCnt++;
                }
            }
        }
    }

    cout << iCnt << endl;

    return 0;
}