//
// Created by Jugglyuser on 06.10.2022.
//

#include "stdio.h"


int main() {
    int first, second, result;
    char operation;

    scanf("%d%c%d", &first, &operation, &second);

    __asm {
            mov eax, first;
            mov ebx, second;
            movzx ecx, operation;
            cmp ecx, '+';
            jz plus;
            cmp ecx, '-';
            jz subs;
            cmp ecx, '*';
            jz mult;
            cmp ecx, '/';
            jz martinez;
            plus:
            add eax, ebx;
            jmp res;
            subs:
            sub eax, ebx;
            jmp res;
            mult:
            mul ebx;
            jmp res;
            martinez:
            div ebx;
            jmp res;
            res:
            mov result, eax;

    };

            printf("result = %d!", result);
    }