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

// ���� ��� �Լ� (�켱���� ����� ����)
float calculate(char* expression) {
    float result = 0.0;
    float currentNum = 0.0;
    char current_operator = '+'; // �ʱ� �����ڴ� ����

    // �켱���� ó��: ������ �������� ���� ó���ϴ� ����
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            currentNum = currentNum * 10 + (expression[i] - '0');
        }

        // �Ҽ��� ó��
        if (expression[i] == '.') {
            float decimalPlace = 0.1;
            i++;
            while (isdigit(expression[i])) {
                currentNum += (expression[i] - '0') * decimalPlace;
                decimalPlace /= 10;
                i++;
            }
            i--; // �̹� ó���� �ε��� ����
        }

        // �����ڰ� �����ų� ���ڿ� ���� �����ϸ� ó��
        if ((!isdigit(expression[i]) && expression[i] != ' ') || i == strlen(expression) - 1) {
            if (current_operator == '+') {
                result += currentNum;
            }
            else if (current_operator == '-') {
                result -= currentNum;
            }
            else if (current_operator == '*') {
                result *= currentNum;
            }
            else if (current_operator == '/') {
                if (currentNum != 0) {
                    result /= currentNum;
                }
                else {
                    printf("������ ����: 0���� ���� �� �����ϴ�.\n");
                    return 0;
                }
            }

            // ���� �����ڷ� ����
            if (expression[i] != ' ') {
                current_operator = expression[i];
            }

            currentNum = 0; // ���� �ʱ�ȭ
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

    // �߰����� ���� ��� �κ�
    char expression[100];
    printf("����� ������ �Է��ϼ��� (�� : 3 + 5 * 2 - 8 / 4): ");
    getchar();  // Enter�� ó���ϱ� ���� �� �Է� �ޱ�
    fgets(expression, sizeof(expression), stdin);

    // ���� ���
    float result = calculate(expression);
    printf("���: %.6f\n", result);

    return 0;
}

