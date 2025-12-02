// #include <iostream>
// #include <algorithm>
// #include <climits>

// #define MAX_N 100
// #define MAX_H 1000

// using namespace std;

// int n {};
// int h[MAX_N] {};
// int h_Max {};

// int main()
// {
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> h[i];
//         h_Max = max(h_Max, h[i]);
//     }

//     int ice_Max = INT_MIN;

//     // 해수면의 높이만큼(1~MAX)
//     for (int j = 1; j <= h_Max; j++)
//     {
//         // 해수면 높이마다 빙산이 몇개씩인지 Count하는 변수
//         int ice_Cnt {};
//         bool bChkIce = false;

//         // 빙산의 개수
//         for (int i = 0; i < n; i++)
//         {
//             //핵심 로직 - 해수면의 높이보다 빙산이 높으면 Count
//             //단, 빙산이 이어지지 않으면 그게 1덩이리임.
//             //ice를 발견하면 True, 아니면 False
//             if(h[i] > j)
//             {
//                 bChkIce = true;
//             }
//             else
//             {
//                 if (bChkIce)
//                 {
//                     ice_Cnt++;
//                 }
//                 bChkIce = false;
//             }

//             if(i==n-1 && bChkIce)
//             {
//                 ice_Cnt++;
//             }
//         }

//         ice_Max = max(ice_Max, ice_Cnt);
//     }
//     // 모든 빙산의 높이가 같아서 위의 분기에 처리가 안되었을 때, 1덩이리 count 하기 위해서
//     // if (bChkIce && ice_Cnt == 0)
//     // {
//     //     ice_Cnt = 1;
//     // }

//     cout << ice_Max << endl;

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define MAX_H 1000

using namespace std;

int n {};
int h[MAX_N] {};
int h_Max {};

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        h_Max = max(h_Max, h[i]);
    }

    int ice_Max = INT_MIN;

    // 해수면의 높이만큼(1~MAX)
    for (int i = 1; i <= h_Max; i++)
    {
        // 해수면 높이마다 빙산이 몇개씩인지 Count하는 변수
        int ice_Cnt {};

        if (h[0] > i)
        {
            ice_Cnt++;
        }

        // 빙산의 개수
        for (int j = 1; j < n; j++)
        {
            if (h[j] > i && h[j-1] <= i)
            {
                ice_Cnt++;
            }
        }

        ice_Max = max(ice_Max, ice_Cnt);
    }

    cout << ice_Max << endl;

    return 0;
}