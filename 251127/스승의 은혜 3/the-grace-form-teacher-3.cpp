#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 1000
#define MAX_B 1000

using namespace std;

int N {}, B {};
int P[MAX_N] {};
int S[MAX_N] {};

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++)
        cin >> P[i] >> S[i];

    int iMax = INT_MIN;

    // 학생 i에 대해 할인 적용 시도
    for (int i = 0; i < N; i++)
    {
        int iTempMoney = B;
        int iCnt {};

        // * 구매 비용 배열 생성 (정렬용)
        int cost[MAX_N] {};

        for (int j = 0; j < N; j++)
        {
            if (j == i)
            {
                cost[j] = (P[j] / 2) + S[j];   // 할인된 학생
            }                
            else
            {
                cost[j] = P[j] + S[j];        // 일반 학생
            }
        }

        // *** 핵심: 전체를 정렬 (가장 싼 애부터 사야 최대 개수 가능)
        sort(cost, cost + N);

        // * 정렬된 순서대로 예산이 허락하는 만큼 구매
        for (int j = 0; j < N; j++)
        {
            if (iTempMoney >= cost[j])
            {
                iTempMoney -= cost[j];
                iCnt++;
            }
            else
            {
                break;
            }
        }

        // 최댓값 갱신
        iMax = max(iMax, iCnt);
    }

    cout << iMax << endl;

    return 0;
}