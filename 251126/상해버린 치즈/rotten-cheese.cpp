#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 50
#define MAX_M 50
#define MAX_D 1000
#define MAX_S MAX_N
#define MAX_p MAX_N
#define MAX_m MAX_M
#define MAX_t 100

using namespace std;

/*
N - 사람수
M - 치즈 개수
D - 특정 사람이 어떤 치즈를 언제 먹었는지에 대한 기록 수
S - 특정 사람이 언제 확실히 아팠는지에 대한 기록 수

- 특이사항
 1. 아프다고 기록된 사람 외에 다른 사람도 아플 수 있음.
 2. 상한 치즈를 먹게 되면 1초가 지나야 아픔.

- 요구사항
상한 치즈를 먹은 사람에게 약을 복용시켜야 할 때, 약이 최대 몇개 필요한지 출력.

- 입력
첫 번째 줄에
N - 사람의 수
M - 치즈의 수
D - 치즈를 먹은 기록의 수
S - 아픈 기록의 수

두 번째 줄에
D(치즈를 먹은 기록의 수)개의 줄에 걸쳐 한줄에 하나씩
(p, m ,t)
몇 번째 사람(p)이, 몇 번째 치즈(m)를, 언제 먹었는지(t초)에 대한 정보

D+1(치즈를 먹은 기록의 수)번째 이후 줄부터 S(아픈 기록의 수)개의 줄에 걸쳐
한줄에 하나씩 몇 번째 사람(p)이 언제 확실히 아팠는지(t초)에 대한 기록(p, t)이 공백을 사이에 두고 주어짐.
*/

int N {}, M {}, D {}, S {};
int p[1000] {}, m[1000] {}, t[1000] {};
int sick_p[50] {}, sick_t[50] {};
int cheese[51] {}; // 0 안상함, 1 상함
int drug[51] {};   // 1 약 먹어야 하는 사람

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++)
    {
        cin >> p[i] >> m[i] >> t[i];
    }

    for (int i = 0; i < S; i++)
    {
        cin >> sick_p[i] >> sick_t[i];
    }
    
    // 만약 아픈 사람수보다 먹은 케이크 수가 적다면 해당 케이크는 아님. N
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < S; j++)
        {
            // 해당 row에 아픈 사람이 발견되고, 아픈 시간보다 작다면. 해당 치즈 의심.
            if(sick_p[j] == p[i] && sick_t[j] > t[i])
            {
                cheese[m[i]] += 1;
            }
        }
    }

    // 의심되는 치즈를 먹은 사람은 1, 안 먹은 사람은 0
    for (int i=0; i<D; i++)
    {
        if(cheese[m[i]] == S)
        {
            drug[p[i]] = 1;
        }
    }

    int iCnt {};

    // 의심되는 치즈를 먹은 사람 1, 숫자 세기
    for (int i=1; i<51; i++)
    {
        // 치즈를 먹은 
       if (drug[i] > 0)
       {
            iCnt++;
       }
    }

    // 상한 치즈를 찾고, 해당 치즈를 먹은 사람들이 발견될 경우. 의심자로 판단.
    // 완전탐색을 통해서 해당 치즈를 먹은 유저들은 모두. 약먹는 것으로 처리.
    // 치즈를 먹은 유저수 만큼 약 출력

    cout << iCnt << endl;

    return 0;
}