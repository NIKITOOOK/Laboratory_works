#include "ExtendedLabSubmission.h"

int main() {
    setlocale(0, "");
    try {
        ExtendedLabSubmission studentLab(LabSubmission::Discipline::ComputerScience, 3);

        studentLab[1] = 85.5;         // ��������� ������ ��� ������ � ������ ������
        studentLab[2] = 75.5;  

        studentLab.submitReport(1);   // ������ ����� �� ������ � ������ ������
        studentLab.submitReport(2);  

        studentLab.recalculateGrade();// ����������� ������� ������

        std::cout << studentLab;      // ������� ���������� � ������������ � �������
    }
    catch (const std::exception& ex) {
        std::cerr << "������: " << ex.what() << std::endl;
    }

    return 0;
}
//422 �������