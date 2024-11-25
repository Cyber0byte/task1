#pragma once
#include <stdint.h>
#include <stdio.h>
#include <math.h>

// int cyclic_right_shift(int num)
// {
//     int digits = (int)log10(num); // Считаем количество цифр в числе

//     int last_part = num % 10;
//     int first_part = num / 10;

//     return last_part * (pow(10, digits)) + first_part;
// }


int cyclic_right_shift(int num, int shift) {
    // Считаем количество разрядов в числе
    int digits = (int)log10(num) + 1;
    printf("%d\n", digits);
    
    // Приводим сдвиг к диапазону 0 - digits - 1
    shift = shift % digits;

    // Если сдвиг нулевой, возвращаем исходное число
    if (shift == 0) {
        return num;
    }
    
    // Находим старшую и младшую часть числа
    int pow10_shift = pow(10, shift);
    int last_part = num % pow10_shift;
    int first_part = num / pow10_shift;
    
    // Сдвигаем
    return last_part * (pow(10, digits - shift)) + first_part;
}



int Task()
{
    int a = 12;
    int b = 1;
    printf("Сдвиг вправо: %d", cyclic_right_shift(a, b));
    return 0;
}
