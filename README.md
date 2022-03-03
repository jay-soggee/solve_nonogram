# solve_nonogram

C/C++을 이용하여 노노그램을 완성해주는 프로그램을 만들어보려 한다.

노노그램의 재미를 알려준 침착맨에게 감사하다. 

# 개요

노노그램을 C++코딩으로 풀어보자!

- 노노그램이란?
    
    [노노그램 - 온라인 퍼즐 게임](https://ko.puzzle-nonograms.com/)
    
## 어떻게 주어질까?

- 각 칸은 🔲, ⬛, ❎ 의 세가지 상태를 갖는다.
- 최대 128개의 행/열을 가질 수 있다. 여기서 메모리를 아낄 필요가 있어보인다.
- 입력 : 먼저 열의 갯수, 열 단서의 최대 갯수, 행의 갯수, 행 단서의 최대 갯수가 주어진다. 이후 각 행/열에 단서를 담은 2개의 2차원배열이 주어진다.
- 출력 : 비트맵 파일을 생성한다.

# 어떻게 문제를 풀것인가?

## 옴닉다운 방법

---

각 행/열에 대하여 아래를 반복한다.

예시) 단서가 **3 7 4** 로 주어졌고, **20**칸짜리 행을 풀고있다고 하자.

### 1. 단서를 이용하여 모든 경우의 수를 생성한다.

---

모든 칸이 비워져있다고 가정하면,

- 각 단서 사이에는 한 칸 이상을 비워야 할 것이다.
- 양 끝은 비우지 않아도 되지만 띄워질 수도 있을 것이다.
- 따라서 단서의 양 끝과 그 사이사이에는 공간이 있을 것이다.
- 행/열에 단서와 최소한의 공간을 집어넣으면 남는 공간이 있을 것이다. 이것을 ‘가동범위(`movable_padding`)’라고 하자.
- 이 가동범위를 단서의 양 끝과 그 사이사이에 나누어 넣어야 할 것이다.

---

### 가동범위를 단서 양 끝과 사이사이에 나누어 넣는 경우의 수

- (가동범위 = `movable_padding` ) = (행/열의 길이) - ( (단서의 총합) + (단서의 개수 - 1) )
    
    단서 사이사이에 한칸은 무조건 띄워야 하므로, 최소한 3+1+7+1+4 = 16 칸을 사용하고 있고, 20칸짜리 행이므로, 4칸을 움직일 수 있다. 이것이 가동범위가 된다.
    

- 이것을 단서 양 끝과 사이사이 자리에 분배해야 한다.
- (자리의 개수) = (단서의 개수) + 1
    
    단서가 3개이므로, 총 4개의 자리가 있다 : _ 3 _ 7 _ 4 _ 
    
    각 자리에 가동범위인 4를 분배한다 : 0+1+1+2 → 0 **3** (1+1) **7** (1+1) **4** 2 
    

위의 경우를 **중복조합**이라고 한다. [나무위키 참고](https://namu.wiki/w/%EC%A1%B0%ED%95%A9#s-2)

- ( (단서의 개수) + 1 ) Homogeneous Combination (가동범위)

중복조합을 조합으로 치환할 수 있다.

- ( (가동범위) + (단서의 개수) ) Combination (단서의 개수)

> 조합으로 코드를 짜고, 역치환하여 경우들을 생성할 것이다.
> 

///4444 → 0+0+0+4

//3/444 → 0+0+1+3

//33/44 → 0+0+2+2

//333/4 → 0+0+3+1

//3333/ → 0+0+4+0

/2/3/44 → 0+1+1+2 → 0 **3** 2 **7** 2 **4** 2 = `temp_lineinfo`

...

이를 통해 얻은 해당 행/열의 경우의 수의 (단서와 양 끝과 사이사이의 공백을 담은)정보를 `temp_lineinfo` 라고 하자.

### 2. 이미 특정된 칸을 참고하여 불가능한 경우의 수를 제거한다.

- 이 행/열에서 모든 칸(`cell`)을 검사한다.
    - 비워졌는가? →
        - 검사 끝
    - 채워졌는가? →
        - 위에서 구한 경우 중에서, 해당 칸이 채워지는지 검사한다.
            - 해당 칸의 열/행(#번째 칸)에서 `temp_lineinfo` 를 앞에서부터 하나하나씩 뺀다.
            - 더이상 빼면 음수가 되는 지점이 `temp_lineinfo` 의 홀수항일 경우
                - 해당 칸은 현재 경우의 수에서 비워진 곳이므로 조건과 맞지 않는다.
                - 검사 끝
            - 더이상 빼면 음수가 되는 지점이 `temp_lineinfo` 의 짝수항일 경우
                - 해당 칸은 현재 경우의 수에서 채워진 곳이므로 조건과 맞는다.
                - 가능한 경우의 수에 추가한다.
                - 검사 끝
        - 검사 끝
    - 금지되었는가? →
        - 위에서 구한 경우 중에서, 해당 칸이 비워지는지 검사한다.
            - 해당 칸의 열/행(#번째 칸)에서 `temp_lineinfo` 를 앞에서부터 하나하나씩 뺀다.
            - 더이상 빼면 음수가 되는 지점이 `temp_lineinfo` 의 홀수항일 경우
                - 해당 칸은 현재 경우의 수에서 비워진 곳이므로 조건과 맞는다.
                - 가능한 경우의 수에 추가한다.
                - 검사 끝
            - 더이상 빼면 음수가 되는 지점이 `temp_lineinfo` 의 짝수항일 경우
                - 해당 칸은 현재 경우의 수에서 채워진 곳이므로 조건과 맞지 않는다.
                - 검사 끝
        - 검사 끝

- 이때 각 칸(`cell`)은 3가지 상태가 필요함을 알 수 있다 : 🔲 빈 상태, ⬛ 채워진 상태, ❎ 금지된 상태.

### 3. 남은 경우의 수에서 무조건 칠해지는 칸을 채우고, 무조건 안 칠해지는 칸을 금지한다.

## 어떻게 문제를 받아 올 것인가

### 각 단서를 받아온다.

- 단서 구조체가 필요하다.
    - 단서의 배열
        
        해당 행/열의 단서 : typedef `lineclues`
        
        - 단서의 개수 : 경우의 수 계산과 배열 길이 특정에 필요하다.
        - 단서의 배열

### 문제를 푼다.

각 칸(`cell`)은 3가지 상태가 필요하다 : 🔲 빈 상태, ⬛ 채워진 상태, ❎ 금지된 상태.

이를 담기 위해서는 2bit가 필요하다 :

- 0b0X = 빈 상태
- 0b10 = 금지된 상태
- 0b11 = 채워진 상태

# 일단 실력대로 풀어보자 (Feb, 22 ~)

절차지향, 적당한 탐색법

## 어떤 배열 자료형을 사용할 것인가?

1. C 스타일 - `malloc` `free`
2. C++ 스타일 - `new` `delete`
3. C++ 스타일 - `<vector>`

메모리를 직접 관리해보기 위해 1, 2번 중 하나를 사용해볼 것이다. `malloc` 과 `new` 의 차이점에 대해 알아보았다.

절차지향 스타일의 코딩에서는 일단 `malloc` 을 사용하기로 하였다.
