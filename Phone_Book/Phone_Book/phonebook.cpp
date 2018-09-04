
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100 // �ִ� 100�� ����
#define BUFFER_SIZE 20

char * names[CAPACITY]; // �̸� -> �迭 �̸�[ũ��]
char * numbers[CAPACITY]; // ��ȭ��ȣ

int n = 0; // ����� ��� �� -> ó�� ����� ����� �����Ƿ� 0���� �ʱ�ȭ

void add();
void find();
void status();
void remove();

int main() {

	char command[BUFFER_SIZE];
	while (1) { // ���ѷ����� ���� command ��ɹ��� �ް� ó���ϰ� ���� �ݺ�
		printf("$ ");
		scanf_s("%s", command, sizeof(command));

		if (strcmp(command, "add") == 0) // strcmp�Լ��� �� ���ڿ��� �������� ��->�����ϸ� 0 ����
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			remove();
		else if (strcmp(command, "exit") == 0) // exit ��ɾ� �Է��ϸ�
			break; // ���α׷� ����
	}
	system("pause");
	return 0;
}

void add() {

	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	// �Լ� ���� ����� ���� = ����������
	// buf1�� buf2�� ��������, ���ÿ� �Ҵ�� �޸𸮷� add�Լ��� return �ǰ� ���� �Ҹ�.
	// ���� buf1�� ����� ���ڿ��� ���� �� �� �迭 names[0]�� ������ �迭�� �ּҸ� �����ؾ� ��.
	// ������ �迭�� strdup �Լ� ������ malloc���� �Ҵ�� �޸��̹Ƿ� add �Լ��� ����� �Ŀ��� �Ҹ����� ������.
	// strdup() : �迭�� �����, �Ű������� ���� �ϳ��� ���ڿ��� �ű⿡ �����Ͽ� ��ȯ

	scanf_s("%s", buf1, sizeof(buf1)); // �̸� �Է�
	scanf_s("%s", buf2, sizeof(buf2)); // ��ȣ �Է�

	int i = n - 1; // i�� �� ������ ��� -> n���̶�� �迭���� 0���� �����ϹǷ� �������� n�� �ƴ϶� n-1
	while (i > 0 && strcmp(names[i], buf1) > 0) { // strcmp()�� �񱳻� �ƴ϶� ���ʹ��ڰ� ������ ���ں��� ������ �迭�� ũ�� 1 ��ȯ, ������ ���� ��ȯ-> while���� ������ �ٷ� i�� ���� ���ڸ� �����ų� ������ �迭�� �Է��� ���ڰ� �۴ٸ� while�� ��������
		names[i + 1] = names[i]; // i��° �ִ� ���ڰ� ��ĭ �ڷ� �Ű�����.
		numbers[i + 1] = numbers[i];
		i--; // i�� ���ҽ��� ������ ��ĭ ������ �ٽ� �˻��ϵ��� ��.
	}
	names[i + 1] = _strdup(buf1); // names �迭�� �Է��� �̸��� n��°�� �߰�
	numbers[i + 1] = _strdup(buf2); // nunbers �迭�� �Է��� ��ȣ�� n��°�� �߰�
	n++; // ��� �� �߰�

	printf("%s ���������� �߰��Ǿ����ϴ�.\n", buf1);

}

void find() {

	char buf[BUFFER_SIZE];

	scanf_s("%s", buf, sizeof(buf)); // ã�� ��� �̸� �Է�

	int i;
	for (i = 0; i < n; i++) { // ��ȭ��ȣ�ο� ����Ǿ� �ִ� ����� ã�� for��
		if (strcmp(buf, names[i]) == 0) { // ���Ͽ� ������

			printf("%s\n", numbers[i]); // ���
			return;
		}
	}

	printf("%s ����� �������� �ʽ��ϴ�.\n", buf); // ������
}

void status() {

	int i;
	for (i = 0; i < n; i++) {
		printf("%s %s\n", names[i], numbers[i]);
	}

	printf("�� %d�� �Դϴ�.\n", n);
}

void remove() {

	char buf[BUFFER_SIZE];

	scanf_s("%s", buf, sizeof(buf)); // ������ ��� �̸� �Է�

	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {

			names[i] = names[n - 1]; // �� ������ ����� ������ �ڸ��� �ű�
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' ���������� �����Ǿ����ϴ�.\n", buf);
			return;
		}
	}

	printf("%s��� ����� �������� �ʽ��ϴ�.\n", buf);
}