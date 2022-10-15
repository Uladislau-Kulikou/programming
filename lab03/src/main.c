/* 
Завдання №20 
Підрахувати суму чисел у заданому діапазоні.
*/
#include <stdio.h>

int main(){
    int start_number = 50; //  Початок відліку
    int end_number = 52; // Кінець відліку
    int result; // Змінна результату

    for (int i = start_number; i < end_number+1; i++){ //задання меж цикла
        result += i;
    }
    return 0;
}
