#include <cstdio> 
#include <locale>  

// Функция(является ли число простым)
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "");  
    int number;
    int primeCount = 0;

    printf("Введите последовательность положительных чисел (0 для завершения):\n");

    // Ввод чисел, пока не введут 0
    while (true) {
        scanf_s("%d", &number);  // ввод числа
        if (number == 0) break;  // если число 0, выходим из цикла
        if (isPrime(number)) {
            primeCount++;  // если число простое, увеличиваем счетчик
        }
    }

    printf("Количество простых чисел: %d\n", primeCount);

    return 0;
}
