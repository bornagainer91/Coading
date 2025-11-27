#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 1000
#define MAX_B 1000

using namespace std;

int N {}, B {};
int P[1000] {};
int S[1000] {};

/*
1번째줄 : N, B
N - 학생수, B - 예산

2번째줄 : P, S
P(i) - 선물가격, S(i) - 배송비
*/

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        cin >> P[i] >> S[i];
    }

    // 선물 1개를 할인해주고 마지막에는 다시 가격 원상복구.
    //

    // 선물 가능한 최대 개수
    int iMax = INT_MIN;    

    // N명의 학생을 탐색
    for (int i = 0; i < N; i++)
    {
        int iTempMoney = B;
        int iCnt {};

        // 할인 시작
        P[i] = (P[i]/2);        

        for (int j = 0; j < N; j++)
        {
            // 예산 - (선물 + 배송비)
            iTempMoney = (iTempMoney - (P[j] + S[j]));

            // 예산이 부족해지면 break. 선물을 구매할 예산이 없으니깐.
            if (iTempMoney < 0)
            {
                break;
            }

            // 선물+배송 예산내에서 지불 완료.
            iCnt++;
        }

        // 위에서 구매한 선물에 대한 max count(지금까지 산 선물의 개수중에 가장 많은 것을 기록)
        iMax = max(iMax, iCnt);

        // 할인 복구
        P[i] = (P[i]*2);
    }

    //최대 선물 개수 출력
    cout << iMax << endl;

    return 0;
}