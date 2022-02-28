# solve_nonogram

C/C++을 이용하여 노노그램을 완성해주는 프로그램을 만들어보려 한다.

노노그램의 재미를 알려준 침착맨에게 감사하다. 


# 어떻게 문제를 풀것인가?

## 무지성한 방법

---

각 행/열에 대하여 아래를 반복한다.

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

단서가 **3 7 4** 로 주어졌고, **20**칸짜리 행을 풀고있다고 하자.

- (가동범위 = `movable_padding` ) = (행/열의 길이) - ( (단서의 총합) + (단서의 개수 - 1) )
    
    단서 사이사이에 한칸은 무조건 띄워야 하므로, 최소한 3+1+7+1+4 = 16 칸을 사용하고 있고, 20칸짜리 행이므로, 4칸을 움직일 수 있다. 이것이 가동범위가 된다.
    

- 이것을 단서 양 끝과 사이사이 자리에 분배해야 한다.
- (자리의 개수) = (단서의 개수) + 1
    
    단서가 3개이므로, 총 4개의 자리가 있다 : _ 3 _ 7 _ 4 _ 
    
    각 자리에 가동범위인 4를 분배한다 : 0+1+1+2 ⇒ 0 **3** 1+1 **7** 1+1 **4** 2 
    

위의 경우를 **중복조합**이라고 한다. [나무위키 참고](https://namu.wiki/w/%EC%A1%B0%ED%95%A9#s-2)

- ( (단서의 개수) + 1 ) Homogeneous Combination (가동범위)

중복조합을 조합으로 치환할 수 있다.

- ( (가동범위) + (단서의 개수) ) Combination (단서의 개수)

> 조합으로 코드를 짜고, 역치환하여 경우들을 생성할 것이다.
> 

### 2. 이미 특정된 칸을 참고하여 불가능한 경우의 수를 제거한다.

- 이때 각 칸(`cell`)은 3가지 상태가 필요함을 알 수 있다 : 🔲 빈 상태, ⬛ 채워진 상태, ❎ 금지된 상태.

### 3. 남은 경우의 수에서 무조건 칠해지는 칸을 채우고, 무조건 안 칠해지는 칸을 금지한다.

## 인간다운 방법

---

각 행/열에 대하여 아래를 반복한다.

1. 각 행/열의 단서와 이미 특정된 칸을 참고하여 모든 경우의 수를 생각한다. 
    1. 이 행/열의 가동범위를 계산한다.
    2. 이미 특정된 칸을 참고한다.
    3. 모든 경우의 수를 계산한다.
2. 모든 경우의 수에서 무조건 칠해지는 칸을 채우고, 무조건 안 칠해지는 칸을 금지한다.

### 경우의 수 생각하기

---

모든 칸이 비워져있다고 가정하면,

- 각 단서 사이에는 한 칸 이상을 비워야 할 것이다.
- 양 끝은 비우지 않아도 되지만 띄워질 수도 있을 것이다.
- 따라서 단서의 양 끝과 그 사이사이에는 공간이 있을 것이다.
- 행/열에 단서와 최소한의 공간을 집어넣으면 남는 공간이 있을 것이다. 이것을 ‘가동범위(movable_padding)’라고 하자.
- 이 가동범위를 단서의 양 끝과 그 사이사이에 나누어 넣어야 할 것이다.

---

---

금지된 부분이 없고, 어떤 부분이 채워져있다고 가정하면,

- 그 칸이 어떤 단서의 일부인지 알아야 할 것이다.
    - 채워져 있던 칸의 개수에 따라 어떤 단서의 일부인지 추려낼 수 있을 것이다.
