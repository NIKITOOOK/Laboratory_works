#include "ExtendedLabSubmission.h"

// для сдачи отчетов
ExtendedLabSubmission::ExtendedLabSubmission(Discipline discipline, int numLabs, int complexity)
    : LabSubmission(discipline, numLabs, complexity)
{
    reportsSubmitted = new bool[numLabs];
    for (int i = 0; i < numLabs; ++i) {
        reportsSubmitted[i] = false;  // Изначально все отчеты не сданы
    }
}

// метод отмечает что отчет по лабораторной сдан
void ExtendedLabSubmission::submitReport(int labNumber) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("Номер лабораторной вне диапазона.");
    }
    reportsSubmitted[labNumber - 1] = true;  // Отмечаем отчет как сданный
}

//  проверка полностью ли сдана лабораторная работа
bool ExtendedLabSubmission::isFullySubmitted(int labNumber) const {
    int index = labNumber - 1;
    return grades[index] > 0.0 && reportsSubmitted[index];  // Проверка: есть оценка и отчет сдан
}

// Подсчитываем количество несданных отчетов
int ExtendedLabSubmission::getRemainingReports() const {
    int remaining = 0;
    for (int i = 0; i < numLabs; ++i) {
        if (!reportsSubmitted[i]) {
            remaining++;
        }
    }
    return remaining;
}

void ExtendedLabSubmission::printInfo() const
{
    LabSubmission::printInfo();

    std::cout << "Отчеты по лабораторным работам:\n";
    for (int i = 0; i <numLabs; ++i) {
        std::cout << "Лабораторная " << (i + 1) << ": ";
        std::cout << (isFullySubmitted(i + 1) ? "Сдана\n" : "Не сдана\n");
    }
    std::cout << "Количество несданных отчетов: " << getRemainingReports() << std::endl;
}

// Переопределение оператора вывода для отображения информации о лабораторных и отчетах
std::ostream& operator<<(std::ostream& out, const ExtendedLabSubmission& ourObject) {
    out << static_cast<const LabSubmission&>(ourObject);  // Вызов базового оператора <<
    out << "Отчеты по лабораторным работам:\n";
    for (int i = 0; i < ourObject.numLabs; ++i) {
        out << "Лабораторная " << (i + 1) << ": ";
        out << (ourObject.isFullySubmitted(i + 1) ? "Сдана\n" : "Не сдана\n");
    }
    out << "Количество несданных отчетов: " << ourObject.getRemainingReports() << std::endl;
    return out;
}

ExtendedLabSubmission::~ExtendedLabSubmission() {
    delete[] reportsSubmitted;
}
