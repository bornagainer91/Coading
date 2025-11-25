#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N {};
int A[101] {}, B[101] {};

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    int iResult = INT_MIN;    

    for (int i=0; i<N; i++)
    {        
        int iWorkTime {};
        int iStack[1001] {};

        for (int j=0; j<N; j++)
        {
            if (i==j) continue;

            for (int k=A[j]; k<B[j]; k++)
            {
                iStack[k]++;
            }
        }

        for (int j=1; j<1001; j++)
        {
            if (iStack[j] > 0) // 여러명이 일해도(겹쳐도) 1번 카운트 됨으로 문제 없음.
            {
                iWorkTime++;
            }
        }

        // cout << i+1 <<"번째: " << iWorkTime << endl;
        iResult = max(iResult, iWorkTime);
    }

    cout << iResult << endl;

    return 0;
}
