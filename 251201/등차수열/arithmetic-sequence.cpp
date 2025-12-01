// #include <iostream>
// #include <algorithm>
// #include <climits>

// #define MAX_N 100

// using namespace std;

// int n {};
// int a[MAX_N] {};

// int main()
// {
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a, a+n);

//     int iMaxCnt = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {            
//             for (int k = a[i]+1; k < a[j]; k++)
//             {
//                 int iCnt {};
//                 if(abs(a[j] - k) == abs(k - a[i]))
//                 {
//                     for (int l = 0; l < n; l++)
//                     {
//                         for (int m = l+1; m < n; m++)
//                         {
//                             for (int o = a[i]+1; o < a[j]; k++)
//                             {
                                
//                             }
//                         }
//                     }
//                 }
//             }
//             iMaxCnt = max(iMaxCnt, iCnt);
//         }
//     }

//     cout << iMaxCnt << endl;

//     return 0;
// }

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

    int iMaxCnt = 0;

    // 1) (i, j) 쌍에서 K 후보 추출
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            // K = (a[i] + a[j]) / 2
            if ((a[i] + a[j]) % 2 != 0)
            {
                continue;   // 정수가 아니면 불가능
            }

            int K = (a[i] + a[j]) / 2;

            // 2) 이 K로 전체 쌍을 검사
            int iCnt = 0;

            for (int l = 0; l < n; l++)
            {
                for (int m = l+1; m < n; m++)
                {
                    if (a[m] - K == K - a[l])
                    {
                        iCnt++;
                    }
                }
            }

            // 3) 최대값 갱신
            iMaxCnt = max(iMaxCnt, iCnt);
        }
    }

    cout << iMaxCnt << endl;

    return 0;
}