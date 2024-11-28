#include "ExtendedLabSubmission.h"

// ��� ����� �������
ExtendedLabSubmission::ExtendedLabSubmission(Discipline discipline, int numLabs, int complexity)
    : LabSubmission(discipline, numLabs, complexity)
{
    reportsSubmitted = new bool[numLabs];
    for (int i = 0; i < numLabs; ++i) {
        reportsSubmitted[i] = false;  // ���������� ��� ������ �� �����
    }
}

// ����� �������� ��� ����� �� ������������ ����
void ExtendedLabSubmission::submitReport(int labNumber) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("����� ������������ ��� ���������.");
    }
    reportsSubmitted[labNumber - 1] = true;  // �������� ����� ��� �������
}

//  �������� ��������� �� ����� ������������ ������
bool ExtendedLabSubmission::isFullySubmitted(int labNumber) const {
    int index = labNumber - 1;
    return grades[index] > 0.0 && reportsSubmitted[index];  // ��������: ���� ������ � ����� ����
}

// ������������ ���������� ��������� �������
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

    std::cout << "������ �� ������������ �������:\n";
    for (int i = 0; i <numLabs; ++i) {
        std::cout << "������������ " << (i + 1) << ": ";
        std::cout << (isFullySubmitted(i + 1) ? "�����\n" : "�� �����\n");
    }
    std::cout << "���������� ��������� �������: " << getRemainingReports() << std::endl;
}

// ��������������� ��������� ������ ��� ����������� ���������� � ������������ � �������
std::ostream& operator<<(std::ostream& out, const ExtendedLabSubmission& ourObject) {
    out << static_cast<const LabSubmission&>(ourObject);  // ����� �������� ��������� <<
    out << "������ �� ������������ �������:\n";
    for (int i = 0; i < ourObject.numLabs; ++i) {
        out << "������������ " << (i + 1) << ": ";
        out << (ourObject.isFullySubmitted(i + 1) ? "�����\n" : "�� �����\n");
    }
    out << "���������� ��������� �������: " << ourObject.getRemainingReports() << std::endl;
    return out;
}

ExtendedLabSubmission::~ExtendedLabSubmission() {
    delete[] reportsSubmitted;
}
