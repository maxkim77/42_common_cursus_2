*This project has been created as part of the 42 curriculum by jeongkim.*

# Push_swap

## Description
**push_swap**은 두 개의 스택(`a`, `b`)과 제한된 **11가지 연산**만 사용하여 정수 리스트를 **오름차순**으로 정렬하는 프로젝트입니다.  
목표는 단순 정렬이 아니라 **최소한의 연산(instruction)** 으로 정렬하는 것입니다.

프로그램은 정수 리스트를 인자로 받아, 스택 `a`를 정렬하기 위한 연산 시퀀스를 계산하고 **표준 출력(stdout)** 으로 출력합니다.

#### Allowed operations (11)
| op  | description |
|---|---|
| sa  | swap top 2 of stack a |
| sb  | swap top 2 of stack b |
| ss  | sa and sb at the same time |
| pa  | push top of b to a |
| pb  | push top of a to b |
| ra  | rotate a (first becomes last) |
| rb  | rotate b |
| rr  | ra and rb at the same time |
| rra | reverse rotate a (last becomes first) |
| rrb | reverse rotate b |
| rrr | rra and rrb at the same time |

#### Algorithm: Turk (cost-optimized)
원소가 **3개 이하**면 하드코딩 로직으로 처리하고, 그 이상은 **Turk 알고리즘(비용 최적화 그리디)** 을 사용합니다.

1. **Phase 1 (a -> b)**  
   스택 `a`에서 **3개만 남을 때까지** `b`로 push 합니다.  
   매 단계마다 **회전 비용이 가장 적은 원소**를 선택합니다.  
   스택 `b`는 **내림차순 유지**를 목표로 합니다.

2. **Phase 2 (3개 정렬)**  
   스택 `a`에 남은 3개 원소를 하드코딩 로직으로 정렬합니다. *(최대 2회 연산)*

3. **Phase 3 (b -> a)**  
   스택 `b`의 원소를 다시 `a`로 push 합니다.  
   역시 **최소 비용 원소**를 우선 선택합니다.

4. **Phase 4 (최종 회전)**  
   스택 `a`의 **최솟값이 맨 위**에 오도록 회전합니다.

5. **후처리 최적화**  
   연속된 연산을 병합 (`ra` + `rb` → `rr`)  
   상쇄되는 쌍 제거 (`ra` + `rra` → 제거)

---

## Instructions

#### Build
```bash
make
make clean
make fclean
make re
```
#### Run
#### Basic execution

```bash
# Individual arguments
./push_swap 4 67 3 87 23
# Single string argument
./push_swap "4 67 3 87 23"
```
#### Count instructions

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```
#### Validate with checker

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

---

## Resources

- [Push_swap Visualizer](https://push-swap-visualizer.vercel.app/) - push_swap 연산 시각화 도구
- [Big O notation (Wikipedia)](https://en.wikipedia.org/wiki/Big_O_notation) - 알고리즘 복잡도 개념
- [[42서울] push_swap 그리디 알고리즘](https://campus-coder.tistory.com/132) - 그리디 알고리즘 접근법 참고
- [MariPeshko/push_swap](https://github.com/MariPeshko/push_swap) - push_swap 참고 구현
- [비교 정렬 알고리즘 시간 복잡도의 하한](https://freshrimpsushi.github.io/ko/posts/1359/) - 비교 정렬의 Ω(n log n) 하한 증명
- [Push_Swap 테스트 쉘 스크립트](https://velog.io/@bahn/PushSwap-%ED%85%8C%EC%8A%A4%ED%8A%B8-%EC%89%98-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8)-push_swap 테스터

### AI 사용 내역

AI(Claude Code)를 개발 보조 도구로 활용하였습니다:
- **코드 생성:** 스택 연산, 파싱 로직, Turk 정렬 알고리즘의 초기 구현 작성
- **아키텍처 설계:** 파일 구조 및 데이터 흐름 계획
- **디버깅:** 컴파일 에러 및 로직 오류 식별 및 수정
- **테스트:** 정확성과 성능 검증을 위한 벤치마크 테스트 스크립트 생성

---
#### 평가 명령어 정리
#### Memory Leaks

- Monitor memory usage (e.g., using the `top` command).
- Ensure all allocated memory is properly freed.
- If there is **even one memory leak** → **final grade is 0**.

```bash
valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes ./push_swap 2 1 0
```

```bash
ARG="3 2 5 1 4"
valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes ./push_swap $ARG
```
#### Error Management

- If at least one test fails → **no points for this section**.
- Must print `"Error\n"` to **standard error**.

###### Non-numeric parameters

```bash
./push_swap 1 a 2
```

###### Duplicate parameters

```bash
./push_swap 1 1 1
```

###### Greater than MAXINT

```bash
./push_swap 2147483648 1 2
```

###### Without parameters (must print nothing)

```bash
./push_swap
```


#### Push_swap – Identity Test
- If at least one test fails → **no points for this section**.
- Expected result: **No output (0 instructions)**

```bash
./push_swap 42
./push_swap 2 3
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
./push_swap 1 4 7 9
```

#### Push_swap – Simple Version

If any test fails → **no points for this section**.

###### Test 1

```bash
ARG="2 1 0"
./push_swap $ARG | ./checker_linux $ARG
```

Requirements:
- Checker displays `"OK"`
- Instruction count must be **2 or 3**

###### Test 2

```bash
ARG="<Between 0 and 3 randomly chosen values>"
./push_swap $ARG | ./checker_linux $ARG
```

```bash
ARG="2 1 0"
./push_swap $ARG | ./checker_linux $ARG
```

Requirements:
- Checker displays `"OK"`
- Instruction count must be between **0 and 3**

#### Another Simple Version (5 Values)

If at least one test fails → **no points for this section**.

###### Test 1

```bash
ARG="1 5 2 4 3"
./push_swap $ARG | ./checker_linux $ARG
```

Requirements:
- Checker displays `"OK"`
- Instruction count must not exceed **12**
- 8 steps is considered excellent

###### Test 2

```bash
ARG="<5 random values>"
./push_swap $ARG | ./checker_linux $ARG
```

```bash
ARG="3 -1 10 0 7"
./push_swap $ARG | ./checker_linux $ARG
```

Requirements:
- Checker displays `"OK"`
- Instruction count ≤ 12

Repeat multiple times with different permutations to ensure robustness.

#### Push_swap – Middle Version (100 Values)

If the test fails → **no points for this section**.

```bash
ARG="<100 random values>"
./push_swap $ARG | ./checker_OS $ARG
```

```bash
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-2147483648,2147483648), 100))))")
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

Requirements:
- Checker displays `"OK"`

Grading:
- < 700 → 5
- < 900 → 4
- < 1100 → 3
- < 1300 → 2
- < 1500 → 1

Rate from 0 (failed) to 5 (excellent).

#### Push_swap – Advanced Version (500 Values)

If the test fails → **no points for this section**.

```bash
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-2147483648,2147483648), 500))))")
./push_swap $ARG | ./checker_OS $ARG
./push_swap $ARG | wc -l
```

```bash
ARG="<500 random values>"
./push_swap $ARG | ./checker_OS $ARG
```

Requirements:
- Checker displays `"OK"`

Grading:
- < 5500 → 5
- < 7000 → 4
- < 8500 → 3
- < 10000 → 2
- < 11500 → 1

Rate from 0 (failed) to 5 (excellent).