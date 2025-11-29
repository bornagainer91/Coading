#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_T 100
#define MAX_X 1000

int main()
{
    int T {}, iXstart_Pos {}, iXend_Pos {};
    cin >> T >> iXstart_Pos >> iXend_Pos;

    /*
        문제의 핵심:
        - 좌표 위에 'S' 와 'N' 알파벳이 여러 개 놓여 있음.
        - 각 알파벳은 특정 위치(pos)에 하나씩 존재.
        - x 위치에서 가장 가까운 S 거리(d1)
        - x 위치에서 가장 가까운 N 거리(d2)
        - d1 <= d2 이면 그 x는 "특별한 위치"

        가장 중요한 구조:
        - S와 N을 섞어 저장하지 않고,
          S 배열, N 배열로 따로 분리 저장.
          → 그래야 거리 계산이 단순해지고 명확해짐.
    */

    // S와 N 각각의 위치를 저장하는 배열
    int S_Pos[MAX_T] {};    // S가 놓인 좌표들
    int N_Pos[MAX_T] {};    // N이 놓인 좌표들

    int S_Count = 0;        // S가 몇 개 있는지
    int N_Count = 0;        // N이 몇 개 있는지

    // --- 입력 단계 ---
    for (int i = 0; i < T; i++)
    {
        char c {};          // 'S' 또는 'N'
        int pos {};         // 그 알파벳이 놓인 좌표

        cin >> c >> pos;

        // 입력받은 알파벳을 종류별로 분류하여 저장
        if (c == 'S')
        {
            S_Pos[S_Count++] = pos;
        }
        else    // 'N'
        {
            N_Pos[N_Count++] = pos;
        }
    }

    int iAnswer = 0;    // 특별한 위치 개수

    // --- x = a ~ b 까지 모든 위치를 검사 ---
    for (int x = iXstart_Pos; x <= iXend_Pos; x++)
    {
        // 각각 가장 가까운 S 거리, N 거리를 매우 큰 값으로 초기화
        int iMin_S_Distance = INT_MAX;
        int iMin_N_Distance = INT_MAX;

        /*
            1) 현재 x에서 S들까지의 거리 중 가장 가까운 값을 찾기
               예: S_Pos = {1, 10}이고 x = 7이면
                   |7-1| = 6, |7-10| = 3 → 최소값 3
        */
        for (int i = 0; i < S_Count; i++)
        {
            int diff = abs(x - S_Pos[i]);     // x와 S 좌표 거리
            iMin_S_Distance = min(iMin_S_Distance, diff);
        }

        /*
            2) 현재 x에서 N들까지의 거리 중 가장 가까운 값을 찾기
        */
        for (int i = 0; i < N_Count; i++)
        {
            int diff = abs(x - N_Pos[i]);     // x와 N 좌표 거리
            iMin_N_Distance = min(iMin_N_Distance, diff);
        }

        /*
            3) 조건 검사: d1(S) <= d2(N)이면 특별한 위치
        */
        if (iMin_S_Distance <= iMin_N_Distance)
        {
            iAnswer++;
        }
    }

    // 특별한 위치의 총 개수 출력
    cout << iAnswer << endl;

    return 0;
}