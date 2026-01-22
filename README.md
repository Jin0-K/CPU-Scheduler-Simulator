# CPU Scheduler Simulator (Round Robin)

C++로 구현한 **Round Robin(RR) CPU 스케줄러 시뮬레이터**입니다.  
운영체제의 CPU 스케줄링 개념을 코드로 직접 구현하며,  
프로세스 상태 전이와 time quantum 기반 선점(preemption) 동작을 확인할 수 있습니다.

---

## Features

- Round Robin 스케줄링 알고리즘 구현
- 단일 CPU 환경 시뮬레이션
- 프로세스 상태 관리 (READY / RUNNING / DONE)
- arrival time 기반 프로세스 큐 관리
- 실행 구간 단위 스케줄링 로그 출력
- 텍스트 파일 기반 프로세스 입력 지원

---

## Tech Stack

- Language: **C++ (C++17)**
- Compiler: `g++`
- OS Concept: CPU Scheduling, Round Robin

---

## Project Structure
src/
├─ main.cpp
├─ processes.txt
├─ process/
│ ├─ process.h
│ └─ process.cpp
├─ cpu/
│ ├─ cpu.h
│ └─ cpu.cpp
└─ scheduler/
├─ scheduler.h
└─ scheduler.cpp


---

## Input Format (`processes.txt`)

각 행은 하나의 프로세스를 의미
각 열은 PID, 프로세스 도착 시간, CPU 실행 시간을 의미

예시:
```bash
1 0 5
2 1 4
3 2 2
```

---

## Build & Run

```bash
make
./RR-scheduler
```

---

## Output Example
출력은 실제 실행 구간 단위로 표시
Time quantum 초과 시 프로세스는 READY 상태로 전환되어 다시 큐에 삽입됨
실행이 끝난 프로세스는 DONE 상태가 되며 스케줄링 대상에서 제외됨

```bash
[ 0 - 2 ] Process 1 RUNNING
[ 2 - 4 ] Process 2 RUNNING
[ 4 - 6 ] Process 3 RUNNING
[ 6 - 8 ] Process 1 RUNNING
[ 8 - 10 ] Process 2 RUNNING
[ 10 - 11 ] Process 1 RUNNING
```