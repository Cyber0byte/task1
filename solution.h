#pragma once
#include <stdint.h>
#include <stdio.h>
#include <math.h>

int cyclic_right_shift(int num, int shift)
{
    // Считаем количество цифр в числе
    int digits = (int)log10(num) + 1;

    // Приводим сдвиг к меньшему диапазону
    shift = shift % digits;

    // Если сдвиг нулевой, возвращаем исходное число
    if (shift == 0)
    {
        return num;
    }

    // Находим старшую и младшую часть числа
    int pow10_shift = pow(10, shift);
    int last_part = num % pow10_shift;
    int first_part = num / pow10_shift;

    return last_part * (pow(10, digits - shift)) + first_part;
}

int Task()
{
    int num = 0;
    int shift = 0;

    printf("Введите число (num): ");
    scanf("%d", &num);

    printf("Введите сдвиг (shift): ");
    scanf("%d", &shift);

    printf("Сдвиг вправо: %d", cyclic_right_shift(num, shift));
    return 0;
}
