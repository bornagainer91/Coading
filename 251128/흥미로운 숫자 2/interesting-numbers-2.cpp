#include <iostream>
#include <algorithm>

#define MAX_NUM 1000000
using namespace std;

/*
X 이상  Y이하의 흥미로운 숫자 Count
흥미로운 숫자 = 모든 자릿수에 있는 숫자들이 같지만, 정확히 한 자리만 다른 숫자

Ex)
    O) 33335 , 1118  = 흥미로운 숫자 O. 정확히 한자리만 다름.
    X) 333333, 11188 = 흥미로운 숫자 X. 같거나, 1자리보다 더 많이 다름.
*/

int X {}, Y {};

bool isInteresting(int n)
{
    int cnt[10] {};    // 숫자 0~9 몇 번 나왔는지 기록
    int t = n;
    int len = 0;       // 전체 자리수 기록

    // (1) 각 자리 숫자 뜯어서 cnt에 기록
    while (t > 0)
    {
        cnt[t % 10]++;   // 해당 숫자 등장 횟수 증가
        t /= 10;         // 다음 자리로 이동
        len++;           // 자리수 1 증가
    }

    // (2) 가장 많이 나온 숫자 개수 MX 찾기
    int mx = 0;
    for (int i = 0; i < 10; i++)
    {
        mx = max(mx, cnt[i]);
    }

    // (3) 전체 자리수 - 가장 많이 나온 숫자 == 1 인지 확인
    return (len - mx == 1);
}


int main()
{
    cin >> X >> Y;

    int iFunnyNumCnt {};

    for (int i=X; i<=Y; i++)
    {
        if(isInteresting(i))
        {
            iFunnyNumCnt++;
        }
    }

    cout << iFunnyNumCnt << endl;

    return 0;
}