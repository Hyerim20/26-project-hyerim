#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

int SaDaRi(int number, char array_1[][100]);
int main() {
    char array_1[100][100]; // 사다리 그리기 배열
    int number; // 선택 수
    int vision;

    printf("\n");
    printf("선택 수를 입력해주세요.:");
    scanf_s("%d", &number);
    printf("\n");


    for (int i = 0; i < number; i++)
    {
        printf("  %d 번째 선택을 입력: ", i + 1);
        scanf("%s", &array_1[i]);
        printf("\n");
    }
    printf("\n");

    // 선택 수만큼 입력 받아 array_1배열의 첫번째 행에 저장

    while (1) {
        printf("둘 중 하나를 골라주세요\n\n  1. 사다리타기 \n\n  2. 랜덤출력 \n\n  >>> ");
        scanf("%d", &vision);
        printf("\n\n");
        if (vision > 2 || vision <= 0) {
            printf("1 또는 2를 입력해주세요. \n");
        }
        else break;
    }
    // 무한 루프
    // 사다리 타기 or 랜덤 출력 선택

    if (vision == 1)
    {
        int SaDaRi(number, array_1);
    }


    if (vision == 2)
    {
        srand((unsigned int)time(NULL));
        int random = rand() % number + 1;

        for (int i = 0; i < number; i++)
        {
            if (random == i)
            {
                printf("  최종 선택: %s \n\n", &array_1[i]);
            }
        }
    }

    printf("5초 뒤 종료됩니다.\n");
    Sleep(5000);
    system("cls");

    return 0;
}

int SaDaRi(int number, char array_1[][100]) {

    int sadari1[] = { 25,5,23 }; // 사다리 세로줄 
    int x = 6; //  사다리 가로줄 (아스키 코드 : - ) 

    // 아스키 코드 사용 = 5:l, 23:ㅓ, 25:ㅏ, 6:- -> 사다리를 구성하는 문자

    int sadari2[100];

    // 만들어진 사다리 저장 
    int random1;

    // 

    int choice1, choice2 = 0;

    while (1) {
        printf("  숫자를 하나 골라 주세요: ");
        scanf_s("%d", &choice1);
        if (choice1 <= number && choice1 > 0) {
            break;
        }
        else printf("\n 1~%d 사이의 수를 골라주세요. \n\n", number);
    }
    printf("\n\n");
    srand((unsigned int)time(NULL)); //랜덤적인 숫자를 만들기 위한 초기seed값을 만든다

    system("cls");

    printf("\n\n");

    for (int i = 0; i < number; i++) // 선택지 번호 출력 ( 선택한 번호: 빨강, 나머지: 흰색 )
    {
        if (i + 1 == choice1)
        {
            printf("\x1b[31m" "%10d", i + 1);
        }
        else
            printf("\x1b[0m" "%10d", i + 1);
    }

    printf("\n\n");

    for (int l = 0; l < 9; l++) // 사다리의 한 열 만들기
    {

        for (int i = 0; i < number + 1; i++)
        {
            random1 = rand() % 2; // 0,1

            if (i == number - 1) // ㅏ,ㅣ 만 구현
            {
                sadari2[i] = sadari1[1]; // ㅣ를 저장
            }
            else
                sadari2[i] = sadari1[random1]; // ㅏ,ㅣ를 저장

            if (i > 0) // ㅏ 다음엔 ㅓ가 나오도록 구현
            {
                if (sadari2[i - 1] == 25)
                {
                    sadari2[i] = 23;
                }
            }

        }

        for (int j = 0; j < number; j++) // ㅣ를 출력 + 빨강 or 흰색
        {
            if (j == choice1 - 1) // 선택한 숫자 아래의 ㅣ를 빨강으로 출력
            {
                printf("\x1b[31m" "%10c", sadari1[1]);
            }

            else // 그외는 흰색으로 출력
                printf("\x1b[0m""%10c", sadari1[1]);
        }

        printf("\n");

        for (int j = 0; j < number; j++)
        {
            if (j == choice1 - 2 && sadari2[choice1 - 2] == 25) // 선택한 숫자 아래 ㅓ면 빨강으로 출력
            {
                printf("\x1b[31m" "%10c", sadari2[j]); // ㅓ
                for (int i = 0; i < 9; i++) // ㅓ 앞에 ------ 를 출력
                {
                    printf("%c", x);
                }
                choice2 = choice1;
            }
            // 빨간색 출력1

            else if (j == choice1 - 1)
            {
                if (sadari2[j] == 25)
                {
                    printf("\x1b[31m" "%10c", sadari2[j]);
                    for (int i = 0; i < 9; i++)
                    {
                        printf("%c", x);
                    }
                    choice2 = choice1;
                    choice1++;
                }

                else if (sadari2[j] == 23 && sadari2[choice1 - 2] == 25 && (choice1 == choice2))
                {
                    printf("\x1b[31m" "%c", sadari2[j]);
                    choice1--;
                }

                else
                    if (sadari2[j] == 23)
                    {
                        printf("\x1b[31m" "%c", sadari2[j]);
                    }
                    else
                        printf("\x1b[31m" "%10c", sadari2[j]);
            }
            // 빨간색 출력2

            else
                if (sadari2[j] == 25)
                {
                    printf("\x1b[0m""%10c", sadari2[j]);
                    for (int i = 0; i < 9; i++)
                    {
                        printf("%c", x);
                    }
                }
                else if (sadari2[j] == 23)
                {
                    printf("\x1b[0m""%c", sadari2[j]);
                }
                else
                    printf("\x1b[0m""%10c", sadari2[j]);
            // 검은색 출력
        }

        printf("\n");

        for (int j = 0; j < number; j++)
        {
            if (j == choice1 - 1)
            {
                printf("\x1b[31m" "%10c", sadari1[1]);
            }
            else
                printf("\x1b[0m""%10c", sadari1[1]);
        }

        printf("\n");
        Sleep(1000);
    }     // 사다리 출력

    printf("\n");

    for (int j = 0; j < number; j++)
    {
        if (j == choice1 - 1)
        {
            printf("\x1b[31m" "%10s", array_1[j]);
        }
        else
            printf("\x1b[0m""%10s", array_1[j]);
    }
    printf("\n\n");

    printf("\x1b[0m""  최종선택: %s 입니다!", array_1[choice1]);

    return 0;
}
