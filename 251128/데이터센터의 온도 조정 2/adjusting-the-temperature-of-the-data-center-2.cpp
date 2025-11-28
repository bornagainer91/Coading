#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

/*
첫번째 줄 - N, C, G, H
N - 장비의 개수
C, G, H - 장비들의 작업량

두번째 줄 - Ta, Tb
Ta, Tb - 온도 범위
*/

int N {}, C {}, G {}, H {};
int Ta[1001] {}, Tb[1001] {};

int CaseMachine(int iMachineNum, int iTemperNum)
{
    if (iTemperNum < Ta[iMachineNum])
    {
        return C;
    }    
    else if (iTemperNum >= Ta[iMachineNum] && iTemperNum <= Tb[iMachineNum])
    {
        return G;
    }    
    else if (iTemperNum > Tb[iMachineNum])
    {
        return H;
    }
}

int main()
{
    cin >> N >> C >> G >> H;    

    for (int i = 0; i < N; i++)
    {
        cin >> Ta[i] >> Tb[i];
    }

    int iTotalMaxTemp {};
    
    for (int j=0; j<=1000; j++)
    {
        int iSumTemp {};
        for (int i = 0; i < N; i++)
        {
            iSumTemp += CaseMachine(i, j);
        }

        iTotalMaxTemp = max(iTotalMaxTemp, iSumTemp);
        // cout << j+1 << "도 일때 최고 작업량: " << iTotalMaxTemp << endl;
    }

    cout << iTotalMaxTemp << endl;

    return 0;
}