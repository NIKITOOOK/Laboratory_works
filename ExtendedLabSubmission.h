#ifndef EXTENDEDLABSUBMISSION_H
#define EXTENDEDLABSUBMISSION_H

#include "LabSubmission.h"

class ExtendedLabSubmission : public LabSubmission {
public:
    ExtendedLabSubmission(Discipline discipline, int numLabs, int complexity = 1);

    void submitReport(int labNumber);           // ��������, ��� ����� �� ������������ ����
    bool isFullySubmitted(int labNumber) const;// ���������, ��������� �� ����� ������

    int getRemainingReports() const;         // �������� ���������� ��������� �������

    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& out, const ExtendedLabSubmission& ourObject);

    ~ExtendedLabSubmission();
     
private:
    bool* reportsSubmitted;             // ������, �������� ������ ����� �������
};

#endif
