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

// 수식 계산 함수 (우선순위 고려한 수정)
float calculate(char* expression) {
    float result = 0.0;
    float currentNum = 0.0;
    char current_operator = '+'; // 초기 연산자는 덧셈

    // 우선순위 처리: 곱셈과 나눗셈을 먼저 처리하는 로직
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            currentNum = currentNum * 10 + (expression[i] - '0');
        }

        // 소수점 처리
        if (expression[i] == '.') {
            float decimalPlace = 0.1;
            i++;
            while (isdigit(expression[i])) {
                currentNum += (expression[i] - '0') * decimalPlace;
                decimalPlace /= 10;
                i++;
            }
            i--; // 이미 처리한 인덱스 복구
        }

        // 연산자가 나오거나 문자열 끝에 도달하면 처리
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
                    printf("나누기 오류: 0으로 나눌 수 없습니다.\n");
                    return 0;
                }
            }

            // 다음 연산자로 변경
            if (expression[i] != ' ') {
                current_operator = expression[i];
            }

            currentNum = 0; // 숫자 초기화
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

    // 추가적인 수식 계산 부분
    char expression[100];
    printf("계산할 수식을 입력하세요 (예 : 3 + 5 * 2 - 8 / 4): ");
    getchar();  // Enter를 처리하기 위한 빈 입력 받기
    fgets(expression, sizeof(expression), stdin);

    // 수식 계산
    float result = calculate(expression);
    printf("결과: %.6f\n", result);

    return 0;
}

