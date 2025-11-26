#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100      // 폭탄 최대 갯수
#define MAX_K 100      // 최대 거리
#define MAX_BOMB 1000  // 폭탄 최대 번호

using namespace std;

int N {}, K {};
int num[MAX_N+1] {};

            /*
            - 첫번째 줄 N, K
            N - 폭탄 갯수
            K - 특정 거리

            - 두번째 줄부터~
            폭탄의 번호

            - 출력
            폭발 할 폭탄중 번호가 가장 큰 것.
            터지는 폭탄이 없다면 -1 출력
            */

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int iMax = INT_MIN;

    for (int i=0; i<N; i++)
    {
        // cout << i << "번째 : " << endl;
        for (int j=i+1; j<=i+K; j++)
        {
            // cout << j+K << endl;
            // cout << j << "번째- num i: " << num[i] << " num j: " << num[j] << endl;
            if (num[i] == num[j])
            {
                // cout << num[i] << num[j] << endl;
                iMax = max(iMax, num[i]);
                break;
            }
        }
        // cout << endl;
    }
    
    if(iMax < 0)
    {
        iMax = -1;
    }

    cout << iMax << endl;

    return 0;
}