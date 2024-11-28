#include "ExtendedLabSubmission.h"

int main() {
    setlocale(0, "");
    try {
        ExtendedLabSubmission studentLab(LabSubmission::Discipline::ComputerScience, 3);

        studentLab[1] = 85.5;         // Установим оценку для первой и второй работе
        studentLab[2] = 75.5;  

        studentLab.submitReport(1);   // Сдадим отчет по первой и второй работе
        studentLab.submitReport(2);  

        studentLab.recalculateGrade();// Пересчитаем среднюю оценку

        std::cout << studentLab;      // Выводим информацию о лабораторных и отчетах
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
//422 КАБИНЕТ