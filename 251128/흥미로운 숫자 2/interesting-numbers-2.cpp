// #include <iostream>
// #include <algorithm>

// #define MAX_NUM 1000000
// using namespace std;

// /*
// X 이상  Y이하의 흥미로운 숫자 Count
// 흥미로운 숫자 = 모든 자릿수에 있는 숫자들이 같지만, 정확히 한 자리만 다른 숫자

// Ex)
//     O) 33335 , 1118  = 흥미로운 숫자 O. 정확히 한자리만 다름.
//     X) 333333, 11188 = 흥미로운 숫자 X. 같거나, 1자리보다 더 많이 다름.
// */

// int X {}, Y {};

// bool isInteresting(int n)
// {
//     int cnt[10] {};    // 숫자 0~9 몇 번 나왔는지 기록
//     int t = n;
//     int len = 0;       // 전체 자리수 기록

//     // (1) 각 자리 숫자 뜯어서 cnt에 기록
//     while (t > 0)
//     {
//         cnt[t % 10]++;   // 해당 숫자 등장 횟수 증가
//         t /= 10;         // 다음 자리로 이동
//         len++;           // 자리수 1 증가
//     }

//     // (2) 가장 많이 나온 숫자 개수 MX 찾기
//     int mx = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         mx = max(mx, cnt[i]);
//     }

//     // (3) 전체 자리수 - 가장 많이 나온 숫자 == 1 인지 확인
//     return (len - mx == 1);
// }

// int main()
// {
//     cin >> X >> Y;

//     int iFunnyNumCnt {};

//     for (int i=X; i<=Y; i++)
//     {
//         if(isInteresting(i))
//         {
//             iFunnyNumCnt++;
//         }
//     }

//     cout << iFunnyNumCnt << endl;

//     return 0;
// }

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

bool isInteresting(int i)
{
    // 문자의 총 숫자 개수 - 제일 많이 나온 숫자 개수
    /*
        - 필요한 변수
            1. 문자의 총 개수
            2. 제일 많이 나온 숫자 개수
            3. temp 변수 - 입력받은 숫자를 넣을 temp 변수
            4. digitNum 배열 (각 숫자가 몇개씩 나왔는지 체크)

        - 해야할 작업
            1. 입력받은 숫자를 일의 자리씩 확인하여 digitNum 배열에 +1
            2. 일의 자리씩 분해 ex) 1234 -> 123 -> 12 -> 1
            3. while문 이 끝날때마다 문자의 총 개수 +1            
            4. digitNum 배열에서 나온 숫자중에 가장 많이 나온 숫자 체크
            5. 전체 문자의 총 개수 - 제일 많이 나온 숫자 = 1 체크하여 맞으면 true 틀리면 false
    */

    // 1. 문자의 총 개수
    int iTotalNumCnt {};

    // 2. 제일 많이 나온 숫자 개수
    int iMaxNumCnt {};

    // 3. 치환 변수 - 입력받은 숫자를 넣을 temp 변수
    int t=i;

    // 4. digitNum 배열 (각 숫자가 몇개씩 나왔는지 체크)
    int iArr[10] {};

    while (t > 0)
    {
        iArr[t%10]++;
        t /= 10;
        iTotalNumCnt++;
    }

    for (int i=0; i<10; i++)
    {
        iMaxNumCnt = max(iMaxNumCnt, iArr[i]);        
    }

    return (iTotalNumCnt - iMaxNumCnt == 1);
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