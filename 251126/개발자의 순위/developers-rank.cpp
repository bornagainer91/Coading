#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_K 10
#define MAX_N 20

using namespace std;

int k {}, n {};
int arr[MAX_K][MAX_N+1] {};
int iRank[MAX_K][MAX_N+1] {};

int main()
{
    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        // cout << i+1 << "번째: " << endl;

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            int iDeveloper = arr[i][j];
            iRank[i][iDeveloper] = j;
            // cout << iDeveloper << "의 순위: " << iRank[i][iDeveloper] << endl;
        }
        // cout << endl;
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;

            bool ok = true;

            // 모든 경기에서 a가 b보다 높은 순위인지 체크
            for (int l = 0; l < k; l++)
            {
                if (iRank[l][i] >= iRank[l][j])
                {
                    ok = false;
                    break;
                }
            }

            if (ok) answer++;
        }
    }

    cout << answer << endl;

    return 0;
}