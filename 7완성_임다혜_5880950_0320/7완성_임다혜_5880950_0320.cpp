#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 사칙연산을 위한 구조체 정의
typedef struct {
    int num1;
    int num2;
} Arithmetic;

// 덧셈 함수
int add(Arithmetic arith) {
    return arith.num1 + arith.num2;
}

// 뺄셈 함수
int subtract(Arithmetic arith) {
    return arith.num1 - arith.num2;
}

// 곱셈 함수
int multiply(Arithmetic arith) {
    return arith.num1 * arith.num2;
}

// 나눗셈 함수
float divide(Arithmetic arith) {
    if (arith.num2 != 0) {
        return (float)arith.num1 / arith.num2;
    }
    else {
        printf("나눗셈 오류: 0으로 나눌 수 없습니다.\n");
        return 0;
    }
}

// 수식을 계산하는 함수 (간단한 사칙연산만 지원)
float calculate_expression(const char* expression) {
    // 입력된 수식 계산을 위한 변수
    float result = 0.0;
    float current_num = 0.0;
    char current_op = '+';  // 기본 연산자는 덧셈

    const char* ptr = expression;

    // 숫자 및 연산자 처리
    while (*ptr != '\0') {
        if (isdigit(*ptr) || *ptr == '.') {
            current_num = strtof(ptr, (char**)&ptr);  // 숫자 파싱
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
                    printf("0으로 나눌 수 없습니다.\n");
                    return 0;
                }
            }
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            current_op = *ptr;  // 연산자 변경
            ptr++;  // 연산자 넘어가기
        }
        else {
            ptr++;  // 기타 문자 넘어가기
        }
    }

    return result;
}

int main() {
    int num1, num2;

    // 사용자로부터 양의 정수 입력받기
    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf_s("%d", &num1);

    printf("두 번째 양의 정수를 입력하세요: ");
    scanf_s("%d", &num2);

    // Arithmetic 구조체 초기화
    Arithmetic arith = { num1, num2 };

    // 사칙연산 결과 출력
    printf("덧셈: %d\n", add(arith));
    printf("뺄셈: %d\n", subtract(arith));
    printf("곱셈: %d\n", multiply(arith));
    printf("나눗셈: %.2f\n", divide(arith));

    // 계산할 수식 입력 받기
    char expression[100];
    printf("계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
    fgets(expression, sizeof(expression), stdin);  // fgets를 사용하여 입력 받기
    fgets(expression, sizeof(expression), stdin);  // 한 번 더 호출하여 버퍼 문제 해결

    // 수식 계산 결과 출력
    float result = calculate_expression(expression);
    printf("결과 : %.6f\n", result);

    return 0;
}
