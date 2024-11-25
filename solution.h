#pragma once
#include <math.h>
#include <stdint.h>
#include <stdio.h>


int RightShift(int num, int shift) {
    int digits = (int)log10(num) + 1; // Считаем количество цифр в числе

    shift = shift % digits; // Приводим сдвиг к меньшему диапазону

    if (shift == 0) {
        return num; // Если сдвиг нулевой, возвращаем исходное число
    }

    // Находим старшую и младшую часть числа
    int pow10_shift = pow(10, shift);
    int last_part = num % pow10_shift;
    int first_part = num / pow10_shift;

    return last_part * (pow(10, digits - shift)) + first_part;
}

int Task() {
    int num = 0;
    int shift = 0;

    printf("Введите число (num): ");
    scanf("%d", &num);

    printf("Введите сдвиг (shift): ");
    scanf("%d", &shift);

    printf("Сдвиг вправо: %d", RightShift(num, shift));
    return 0;
}
