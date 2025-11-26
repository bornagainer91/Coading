// #include <iostream>
// #include <algorithm>
// #include <climits>

// #define MAX_K 10
// #define MAX_N 20

// using namespace std;

// int k {}, n {};
// int arr[MAX_K][MAX_N+1] {};
// int iRank[MAX_K][MAX_N+1] {};

// int main()
// {
//     cin >> k >> n;

//     for (int i = 0; i < k; i++)
//     {
//         // cout << i+1 << "번째: " << endl;

//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[i][j];
//             int iDeveloper = arr[i][j];
//             iRank[i][iDeveloper] = j;
//             // cout << iDeveloper << "의 순위: " << iRank[i][iDeveloper] << endl;
//         }
//         // cout << endl;
//     }

//     int answer = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j) continue;

//             bool ok = true;

//             // 모든 경기에서 a가 b보다 높은 순위인지 체크
//             // 숫자가 겹치지 않는다고 했으니깐 같다는 표시는 안해도 됨.
//             for (int l = 0; l < k; l++)
//             {
//                 if (iRank[l][i] >= iRank[l][j])
//                 {
//                     ok = false;
//                     break;
//                 }
//             }

//             if (ok) answer++;
//         }
//     }

//     cout << answer << endl;

//     return 0;
// }

#include <iostream>

#define MAX_K 10
#define MAX_N 20

using namespace std;

int N {}, K {};
int arr[MAX_K][MAX_N+1] {};
int iRank[MAX_K][MAX_N+1] {};

int main()
{
    cin >> N >> K;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<K; j++)
        {
            cin >> arr[i][j];
            int iDeveloper = arr[i][j];
            iRank[i][iDeveloper] = j;
        }
    }

    int iCnt {};

    for (int a=1; a<=K; a++)
    {
        for (int b=1; b<=K; b++)
        {
            int bChk = true;
            // a,b가 같으면 넘어가기. 사람이 같으면 순위를 비교할 필요가 없음.
            if (a==b) continue;

            // a,b가 i번째 경기마다 순위가 어떠한지 체크. 한번이라도 순위가 벗어나면 탈출
            for (int i=0; i<N; i++)
            {
                // a가 b보다 크거나 같으면 해제(순위가 작을수록 높기 때문에. 순위가 뒤쳐지면 false임)
                if (iRank[i][a] >= iRank[i][b])
                {
                    bChk = false;
                    break;
                }                
            }
            if(bChk) iCnt++;
        }
    }

    cout << iCnt << endl;

    return 0;
}