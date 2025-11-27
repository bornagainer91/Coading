#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int X, Y;

int main()
{
    // X부터 Y까지 범위를 입력받습니다.
    cin >> X >> Y;

    int iMax = INT_MIN;   // 자리수 합의 최댓값을 저장할 변수

    // X 이상 Y 이하의 모든 정수를 확인합니다.
    for (int i = X; i <= Y; i++)
    {
        int sum = 0;      // 현재 숫자의 자리수 합
        int t = i;        // i를 직접 변경하지 않기 위해 복사본 t 사용

        // 숫자 t가 0이 될 때까지 반복하며 하나씩 자리수를 추출합니다.
        // EX: 352 -> (2) -> (5) -> (3)
        while (t > 0)
        {
            sum += t % 10;   // 마지막 자리 숫자를 sum에 더함
            t /= 10;         // 마지막 자리 숫자를 제거
        }

        // 지금까지의 최대 자리수 합과 비교해 더 큰 값을 저장합니다.
        iMax = max(iMax, sum);
    }

    // 최종 결과 출력
    cout << iMax << endl;

    return 0;
}