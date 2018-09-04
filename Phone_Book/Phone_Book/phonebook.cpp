
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100 // 최대 100명 저장
#define BUFFER_SIZE 20

char * names[CAPACITY]; // 이름 -> 배열 이름[크기]
char * numbers[CAPACITY]; // 전화번호

int n = 0; // 저장된 사람 수 -> 처음 저장된 사람이 없으므로 0으로 초기화

void add();
void find();
void status();
void remove();

int main() {

	char command[BUFFER_SIZE];
	while (1) { // 무한루프를 통해 command 명령문을 받고 처리하고 무한 반복
		printf("$ ");
		scanf_s("%s", command, sizeof(command));

		if (strcmp(command, "add") == 0) // strcmp함수는 두 문자열이 동일한지 비교->동일하면 0 리턴
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			remove();
		else if (strcmp(command, "exit") == 0) // exit 명령어 입력하면
			break; // 프로그램 종료
	}
	system("pause");
	return 0;
}

void add() {

	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	// 함수 내에 선언된 변수 = 지역변수로
	// buf1과 buf2가 지역변수, 스택에 할당된 메모리로 add함수가 return 되고 나면 소멸.
	// 따라서 buf1에 저장된 문자열을 복제 한 후 배열 names[0]에 복제된 배열의 주소를 저장해야 함.
	// 복제된 배열은 strdup 함수 내에서 malloc으로 할당된 메모리이므로 add 함수가 종료된 후에도 소멸하지 ㅇ낳음.
	// strdup() : 배열을 만들고, 매개변수로 받은 하나의 문자열을 거기에 복사하여 반환

	scanf_s("%s", buf1, sizeof(buf1)); // 이름 입력
	scanf_s("%s", buf2, sizeof(buf2)); // 번호 입력

	int i = n - 1; // i가 맨 마지막 사람 -> n명이라면 배열에선 0부터 시작하므로 마지막은 n이 아니라 n-1
	while (i > 0 && strcmp(names[i], buf1) > 0) { // strcmp()는 비교뿐 아니라 왼쪽문자가 오른쪽 문자보다 사전식 배열로 크면 1 반환, 작으면 음수 반환-> while문의 조건이 바로 i가 같은 문자를 만나거나 사전식 배열로 입력한 문자가 작다면 while문 빠져나옴
		names[i + 1] = names[i]; // i번째 있는 문자가 한칸 뒤로 옮겨진다.
		numbers[i + 1] = numbers[i];
		i--; // i를 감소시켜 앞으로 한칸 움직여 다시 검사하도록 함.
	}
	names[i + 1] = _strdup(buf1); // names 배열에 입력한 이름을 n번째에 추가
	numbers[i + 1] = _strdup(buf2); // nunbers 배열에 입력한 번호를 n번째에 추가
	n++; // 사람 수 추가

	printf("%s 성공적으로 추가되었습니다.\n", buf1);

}

void find() {

	char buf[BUFFER_SIZE];

	scanf_s("%s", buf, sizeof(buf)); // 찾을 사람 이름 입력

	int i;
	for (i = 0; i < n; i++) { // 전화번호부에 저장되어 있는 사람을 찾는 for문
		if (strcmp(buf, names[i]) == 0) { // 비교하여 있으면

			printf("%s\n", numbers[i]); // 출력
			return;
		}
	}

	printf("%s 사람은 존재하지 않습니다.\n", buf); // 없으면
}

void status() {

	int i;
	for (i = 0; i < n; i++) {
		printf("%s %s\n", names[i], numbers[i]);
	}

	printf("총 %d명 입니다.\n", n);
}

void remove() {

	char buf[BUFFER_SIZE];

	scanf_s("%s", buf, sizeof(buf)); // 삭제할 사람 이름 입력

	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {

			names[i] = names[n - 1]; // 맨 마지막 사람을 삭제된 자리로 옮김
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' 성공적으로 삭제되었습니다.\n", buf);
			return;
		}
	}

	printf("%s라는 사람은 존재하지 않습니다.\n", buf);
}