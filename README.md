# CPP Module 00

## 1️⃣ 프로젝트 소개

CPP Module 00는 42서울 C++ 커리큘럼의 출발점으로, C 방식의 절차지향 사고에서 객체지향(OOP) 관점으로 전환하는 연습에 초점을 둡니다. 간단한 프로그램부터 class/object/static 멤버, 스트림 기반 I/O(iostream)까지 기본기를 체계적으로 익히며, 헤더/소스 분리와 빌드 습관을 함께 다집니다.

---

## 2️⃣ 과제 목표
	•	C와 구분되는 C++ 기본 문법 및 철학(캡슐화·추상화·객체 수명) 이해
	•	class 정의, 생성자/소멸자, 멤버 함수/변수, static 멤버의 의미 습득
	•	스트림 입출력(std::cout, std::cin, 조작자)과 문자열 처리에 익숙해지기
	•	헤더(.hpp) / 소스(.cpp) 분리, 인터페이스-구현 구분, 간단한 Makefile 운용

---

## 3️⃣ Exercise별 구현 사항

### ex00 — Megaphone
	•	기능: 프로그램 인자로 받은 문자열을 대문자로 변환하여 출력
	•	주요 포인트: argc/argv 처리, std::toupper/문자 순회, 인자 없을 때의 메시지 처리
	•	예외/경계: 공백/특수문자 보존 여부, 로케일 영향 최소화

### ex01 — My Awesome PhoneBook
	•	기능: 최대 8개 Contact를 저장/검색하는 간단 전화번호부(순환 저장)
	•	구조: Contact와 PhoneBook 두 클래스로 캡슐화
	  -	Contact: 이름/별명/전화/비밀 필드 + 접근자
	  -	PhoneBook: 추가(ADD), 요약/상세 조회(SEARCH), 종료(EXIT)
	•	UI/출력: 요약 테이블 폭 고정(std::setw), 길면 말줄임 처리
	•	에러 처리: 비어있는 입력/인덱스 범위 오류 처리, 입력 스트림 상태 복구

### ex02 — Account
	•	기능: 은행 계좌 클래스를 구현하고, 입금/출금 시도들을 로그와 함께 출력
	•	정적 멤버: nbAccounts, totalAmount, totalNbDeposits, totalNbWithdrawals
	•	인스턴스 멤버: _amount, _nbDeposits, _nbWithdrawals, _accountIndex
	•	로깅 형식: 타임스탬프 [YYYYMMDD_HHMMSS] + 액션별 포맷 일치
	•	제약: 음수 출금 거절, 모든 상태 변화가 정확한 카운터로 집계되도록 유지

---

## 4️⃣ 배운 점
### 4.1 객체지향 전환의 감각
	•	데이터와 행위의 결합: 전역 함수 + 구조체 조합이 아니라, 상태(필드)와 행동(메서드)을 class로 묶어 응집도를 올림.
	•	생성자/소멸자: 객체 수명에 따라 초기화/정리가 자동 호출됨을 실제로 체감. (리소스 관리의 기초)

### 4.2 캡슐화와 인터페이스 설계
	•	private 멤버를 외부로부터 숨기고 public 메서드로만 조작하게 함으로써 불변식(invariant)을 보존.
	•	ex01에서 Contact 필드 접근을 게터로만 허용해, 출력 형식 변경·검증 로직을 클래스 내부로 밀어넣는 습관 형성.

### 4.3 정적 멤버/클래스 간 책임 분리
	•	ex02에서 전체 집계는 클래스(static) 영역, 개별 거래 내역은 인스턴스에 귀속.
	•	정적/인스턴스 카운터의 일관성 유지(입금/출금 시 동시 갱신, 실패 시 롤백 없음)를 통해 state machine 사고 강화.

### 4.4 스트림 I/O와 포매팅
	•	std::cout/조작자(std::setw, std::setfill)로 표 형식 출력을 구현하며, C printf 대비 타입 안전성과 조합성 체감.
	•	입력 스트림 오류 처리(std::cin.fail()), 공백 포함 입력 처리(std::getline) 등 사용자 입력의 현실적 문제 대응.

### 4.5 경계/예외 처리 루틴
	•	ex01의 인덱스 파싱, 빈 문자열, 길이 제한, 말줄임 처리 등 “깨지지 않는 UI” 경험.
	•	ex02에서 음수 거래, 과도 출금 거절 등 업무 규칙(validation)을 코드로 명확히 모델링.

### 4.6 빌드·구조화 습관
	•	헤더/소스 분리로 인터페이스-구현 경계를 처음부터 명확히 함.
	•	-Wall -Wextra -Werror -std=c++98로 컴파일하며 엄격한 코딩 규칙을 습관화.
	•	작은 단위로 클래스를 나누고, 변경 영향이 국소화되도록 의존성 최소화.

### 4.7 출력 포맷 재현의 중요성(ex02)
	•	스펙과 완전히 동일한 출력을 만드는 과정에서, 포맷의 사소한 차이가 테스트 실패로 이어질 수 있음을 체득.
	•	테스트 주도 시점 정렬(동일 타임스탬프 포맷, 라인 단위 flush 등)의 필요성 이해.

---

## 5️⃣ Exercise별 실행 방법

### 공통:
```
make            # 모든 과제별 바이너리 빌드
make re / clean # 재빌드 / 정리
```

### ex00 — Megaphone

bash
```
./megaphone "hello" "c++" 
# 출력: HELLO C++
./megaphone
# 출력: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01 — PhoneBook

bash
```
./phonebook
# 명령: ADD / SEARCH / EXIT
# ADD → 8개 고정 저장, 9번째부터 0번부터 순환 덮어쓰기
# SEARCH → 인덱스 입력 후 상세 보기
```

### ex02 — Account

bash
```
./accounts
# 제공된 테스트 드라이버(혹은 스펙)와 동일한 출력 형식 재현 여부 확인
# 예: [YYYYMMDD_HHMMSS] index:0;amount:42;created
#     [YYYYMMDD_HHMMSS] index:0;deposit:5;amount:47;nb_deposits:1
```

---

## 6️⃣ 기술 스택
	•	언어: C++98
	•	운영체제/환경: Unix/Linux
	•	빌드 도구: GNU Make
	•	표준 라이브러리: <iostream>, <iomanip>, <string>
