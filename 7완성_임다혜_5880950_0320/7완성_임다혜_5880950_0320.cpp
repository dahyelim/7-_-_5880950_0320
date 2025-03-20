#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ��Ģ������ ���� ����ü ����
typedef struct {
    int num1;
    int num2;
} Arithmetic;

// ���� �Լ�
int add(Arithmetic arith) {
    return arith.num1 + arith.num2;
}

// ���� �Լ�
int subtract(Arithmetic arith) {
    return arith.num1 - arith.num2;
}

// ���� �Լ�
int multiply(Arithmetic arith) {
    return arith.num1 * arith.num2;
}

// ������ �Լ�
float divide(Arithmetic arith) {
    if (arith.num2 != 0) {
        return (float)arith.num1 / arith.num2;
    }
    else {
        printf("������ ����: 0���� ���� �� �����ϴ�.\n");
        return 0;
    }
}

// ������ ����ϴ� �Լ� (������ ��Ģ���길 ����)
float calculate_expression(const char* expression) {
    // �Էµ� ���� ����� ���� ����
    float result = 0.0;
    float current_num = 0.0;
    char current_op = '+';  // �⺻ �����ڴ� ����

    const char* ptr = expression;

    // ���� �� ������ ó��
    while (*ptr != '\0') {
        if (isdigit(*ptr) || *ptr == '.') {
            current_num = strtof(ptr, (char**)&ptr);  // ���� �Ľ�
            if (current_op == '+') {
                result += current_num;
            }
            else if (current_op == '-') {
                result -= current_num;
            }
            else if (current_op == '*') {
                result *= current_num;
            }
            else if (current_op == '/') {
                if (current_num != 0) {
                    result /= current_num;
                }
                else {
                    printf("0���� ���� �� �����ϴ�.\n");
                    return 0;
                }
            }
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            current_op = *ptr;  // ������ ����
            ptr++;  // ������ �Ѿ��
        }
        else {
            ptr++;  // ��Ÿ ���� �Ѿ��
        }
    }

    return result;
}

int main() {
    int num1, num2;

    // ����ڷκ��� ���� ���� �Է¹ޱ�
    printf("ù ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num1);

    printf("�� ��° ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &num2);

    // Arithmetic ����ü �ʱ�ȭ
    Arithmetic arith = { num1, num2 };

    // ��Ģ���� ��� ���
    printf("����: %d\n", add(arith));
    printf("����: %d\n", subtract(arith));
    printf("����: %d\n", multiply(arith));
    printf("������: %.2f\n", divide(arith));

    // ����� ���� �Է� �ޱ�
    char expression[100];
    printf("����� ������ �Է��ϼ��� (��: 3 + 5 * 2 - 8 / 4): ");
    fgets(expression, sizeof(expression), stdin);  // fgets�� ����Ͽ� �Է� �ޱ�
    fgets(expression, sizeof(expression), stdin);  // �� �� �� ȣ���Ͽ� ���� ���� �ذ�

    // ���� ��� ��� ���
    float result = calculate_expression(expression);
    printf("��� : %.6f\n", result);

    return 0;
}
