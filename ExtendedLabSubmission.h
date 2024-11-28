#ifndef EXTENDEDLABSUBMISSION_H
#define EXTENDEDLABSUBMISSION_H

#include "LabSubmission.h"

class ExtendedLabSubmission : public LabSubmission {
public:
    ExtendedLabSubmission(Discipline discipline, int numLabs, int complexity = 1);

    void submitReport(int labNumber);           // Отметить, что отчет по лабораторной сдан
    bool isFullySubmitted(int labNumber) const;// Проверить, полностью ли сдана работа

    int getRemainingReports() const;         // Получить количество несданных отчетов

    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& out, const ExtendedLabSubmission& ourObject);

    ~ExtendedLabSubmission();
     
private:
    bool* reportsSubmitted;             // Массив, хранящий статус сдачи отчетов
};

#endif
