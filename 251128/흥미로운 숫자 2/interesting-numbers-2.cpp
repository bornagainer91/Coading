#include <iostream>
#include <algorithm>

using namespace std;

/*
X 이상 Y 이하의 숫자 중
흥미로운 숫자의 개수를 구하는 프로그램.

흥미로운 숫자란?
→ 모든 자리수 중 정확히 '한 자리'만 다른 숫자.
예시)
O: 33335, 1118       (딱 1자리만 다름)
X: 333333, 11188     (0개 또는 2개 이상 다름)
*/

int X {}, Y {};

bool isInteresting(int i)
{
    /*
        필요한 값:
        1) 전체 자리수 개수
        2) 가장 많이 등장한 숫자의 개수
        3) temp 변수 (i를 분해하기 위한 값)
        4) 각 숫자의 등장 횟수를 저장하는 배열

        기본 아이디어:
        - 숫자 i를 1자리씩 분해하여 iDigitCnt[] 카운트
        - 전체 자리수(totalDigitCnt)를 계산
        - iDigitCnt[] 중 최댓값(maxDigitCnt)을 구함
        - (전체 자리수 - 최댓값 == 1) 이면 흥미로운 숫자
    */

    int totalDigitCnt {};   // 전체 자리수 개수
    int maxDigitCnt {};     // 가장 많이 등장한 숫자의 개수
    int iTemp = i;          // 자리수 분해용 임시 변수
    int iDigitCnt[10] {};   // 각 숫자가 몇 번 등장했는지 기록

    // 자리수 분해 + 등장 횟수 카운트
    while (iTemp > 0)
    {
        iDigitCnt[iTemp % 10]++;  // 마지막 자리 숫자 카운트
        iTemp /= 10;               // 자리 하나 제거
        totalDigitCnt++;           // 자리수 증가
    }

    // 최빈값(가장 많이 등장한 숫자의 개수) 찾기
    for (int n = 0; n < 10; n++)
    {
        maxDigitCnt = max(maxDigitCnt, iDigitCnt[n]);
    }

    // 전체 자리수 - 최빈값 == 1  → 흥미로운 숫자
    return (totalDigitCnt - maxDigitCnt == 1);
}

int main()
{
    cin >> X >> Y;

    int iFunnyNumCnt {};  // 흥미로운 숫자 카운트

    // X부터 Y까지 모든 숫자 검사
    for (int i = X; i <= Y; i++)
    {
        if (isInteresting(i))
        {
            iFunnyNumCnt++;
        }
    }

    cout << iFunnyNumCnt << endl;

    return 0;
}