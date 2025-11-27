#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 10
#define MAX_AB 100

using namespace std;

int n {};
int l[MAX_N] {}, r[MAX_N] {};

// i1, i2, i3 선분을 제거했을 때,
// 남은 선분들 중 어느 위치에서도 겹침 개수의 최대값을 구하는 함수
int GetMaxOverlappedCnt(int i1, int i2, int i3)
{
    int counting[MAX_AB+1] {}; // 0으로 자동 초기화

    for(int idx = 0; idx < n; idx++)
    {
        // 제거한 3개의 선분은 건너뜀
        if(idx == i1 || idx == i2 || idx == i3)
            continue;

        // 현재 선분의 구간
        int start = l[idx];
        int end   = r[idx];

        // 해당 구간의 모든 위치에 +1
        for(int x = start; x <= end; x++)
            counting[x]++;
    }

    // counting 배열 중 가장 큰 값 반환
    int max_cnt = 0;
    for(int x = 0; x <= MAX_AB; x++)
        max_cnt = max(max_cnt, counting[x]);

    return max_cnt;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    int iCnt = 0;

    // i < j < k 형태로 모든 3개 조합 완전탐색
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                // 제거한 뒤, 겹치는 위치가 하나도 없어야 함
                // 즉, 최대 겹침 수가 1이면 “겹침 없음”
                if(GetMaxOverlappedCnt(i, j, k) == 1)
                {
                    iCnt++;
                }
            }
        }
    }

    cout << iCnt << endl;

    return 0;
}