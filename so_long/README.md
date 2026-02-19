*This project has been created as part of the 42 curriculum by jeongkim.*


## Description
**so_long**은 **MiniLibX** 라이브러리를 활용하여 제작된 작은 2D 게임 프로젝트입니다.  
플레이어는 맵에 흩어진 모든 수집품을 모으고, 가장 적은 이동 횟수로 탈출구에 도달해야 합니다.

### Key Features
- **2D Rendering**: 2D 그래픽 출력.
- **Input Handling**: `W/A/S/D` 키를 이용한 상하좌우 이동.
- **Move Counter**: 이동할 때마다 터미널(Shell)에 현재 이동 횟수 실시간 출력.
- **Map Validation**: `.ber` 확장자 파일 파싱 및 엄격한 규칙 검사.

## Instructions

### 1. Requirements
- **MiniLibX** (Linux 버전 또는 OS에 맞는 라이브러리)
- **C Compiler** (gcc, cc 등)
- **Make** 유틸리티

### 2. Build & Run
```bash
make
```
### 3. 게임 실행
```bash
./so_long maps/mandatory.ber
```

### 3. Controls
| Key | Action |
| :--- | :--- |
| **W** | 위로 이동 (Move Up) |
| **A** | 왼쪽으로 이동 (Move Left) |
| **S** | 아래로 이동 (Move Down) |
| **D** | 오른쪽으로 이동 (Move Right) |
| **ESC** | 게임 종료 (Exit) |

### 4. Map Rules
게임이 실행되기 위해서는 `.ber` 파일이 다음의 엄격한 규칙을 만족해야 합니다.

### Map Characters
- `0`: 빈 공간 (Empty space)
- `1`: 벽 (Wall)
- `C`: 수집품 (Collectible)
- `E`: 탈출구 (Exit)
- `P`: 플레이어 시작 지점 (Player start)

### Validation Checklist
- **직사각형 형태**: 모든 행의 길이가 동일해야 합니다.
- **벽 폐쇄성**: 맵의 모든 가장자리는 벽(`1`)으로 둘러싸여 있어야 합니다.
- **필수 요소 구성**
  - `E` (탈출구) : **정확히 1개**
  - `P` (플레이어 시작점) : **정확히 1개**
  - `C` (수집품) : **최소 1개 이상**
- **유효 경로 (Pathfinding)**: 플레이어가 모든 수집품을 획득하고 탈출구까지 도달할 수 있는 유효한 경로가 반드시 존재해야 합니다.

### Rendering & Logic
- **MiniLibX**: `mlx_new_window`, `mlx_loop`, `mlx_xpm_file_to_image` 등을 활용하여 그래픽을 구현했습니다.
- **Event Handling**: 윈도우 포커스 변경이나 최소화 시에도 그래픽이 깨지지 않고 유지되도록 설계되었습니다.
- **Memory Management**: 프로그램 종료 시 할당된 모든 이미지 포인터와 메모리를 해제(Free)하여 누수를 방지합니다.


## Resources
- MiniLibX 기본 개념 및 함수 설명  
  https://one-zin.tistory.com/2

- 42 Seoul so_long 구현 회고 (맵 파싱, 이벤트 처리 흐름 설명)  
  https://velog.io/@hyuntall/42-Seoul-solong-%ED%9A%8C%EA%B3%A0%EB%A1%9D

- 42Seoul so_long 과제 정리 및 구현 가이드  
  https://fkdl0048.github.io/c/42sub_so_long/


### AI Usage
본 프로젝트 제작 과정에서 AI는 다음과 같은 보조적인 용도로 활용되었습니다:
- **로직 검토**: 맵 유효성 검사, 전체 구성 알고리즘 
- **규정 해석**: Norminette 규칙(함수 길이, 변수 제한 등)에 대한 가이드라인 확인.
- **디버깅 보조**: 메모리 누수 방지를 위한 구조 설계 및 예외 처리 로직 조언.