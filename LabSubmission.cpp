#include "LabSubmission.h"

//+ complexity
LabSubmission::LabSubmission(Discipline discipline, int numLabs, int complexity)
    : discipline(discipline), numLabs(numLabs), currentGrade(0.0), numSubmitted(0)
{
    if (numLabs <= 0) {
        throw std::invalid_argument("���������� ������������ ����� ������ ���� �������������.");
    }
    

    grades = new double[numLabs];
    complexities = new int[numLabs];

    for (int i = 0; i < numLabs; ++i) {
        grades[i] = 0.0;
        complexities[i] = complexity;
    }
}

LabSubmission::Discipline LabSubmission::getDiscipline() const {
    return discipline;
}

int LabSubmission::getNumLabs() const {
    return numLabs;
}

double LabSubmission::getCurrentGrade() const {
    return currentGrade;
}

int LabSubmission::getNumSubmitted() const {
    return numSubmitted;
}

void LabSubmission::printInfo() const {
    std::string disciplineName;
    switch (discipline) {
    case Discipline::Mathematics: disciplineName = "����������"; break;
    case Discipline::Physics: disciplineName = "������"; break;
    case Discipline::Chemistry: disciplineName = "�����"; break;
    case Discipline::ComputerScience: disciplineName = "�����������"; break;
    case Discipline::Biology: disciplineName = "��������"; break;
    case Discipline::Literature: disciplineName = "����������"; break;
    default: disciplineName = "����������� ����������"; break;
    }

    std::cout << "����������: " << disciplineName << std::endl;
    std::cout << "���������� ������������ �����: " << numLabs << std::endl;
    std::cout << "���������� ������� ������������ �����: " << numSubmitted << std::endl;
    std::cout << "������� ������ �� ����������: " << currentGrade << std::endl;
}

void LabSubmission::submitLab(int labNumber, double grade) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("����� ������������ ������ ��� ����������� ���������.");
    }

    if (grade < 0.0 || grade > 100.0) {
        throw std::invalid_argument("������ ������ ���� � ��������� �� 0 �� 100.");
    }

    int index = labNumber - 1;

    if (grades[index] != 0.0) {
        throw std::logic_error("������������ ������ ��� ���� �����.");
    }

    grades[index] = grade;
    numSubmitted++;
    recalculateGrade();
}

//  "[]"
double& LabSubmission::operator[](int labNumber) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("����� ������������ ������ ��� ����������� ���������.");
    }

    int index = labNumber - 1;

    // �������� ���� ������������ ��� �� �����, ����������� ������� ������� �����
    if (grades[index] == 0.0) {
        numSubmitted++;
    }

    return grades[index];
}

// ����� ��� ��������� ������� ������
void LabSubmission::recalculateGrade() {
    double total = 0.0;
    for (int i = 0; i < numLabs; ++i) {
        total += grades[i];
    }
    currentGrade = total / numLabs;
}

// "<<"
std::ostream& operator<<(std::ostream& out, const LabSubmission& ourObject) {
    std::string disciplineName;
    switch (ourObject.discipline) {
    case LabSubmission::Discipline::Mathematics: disciplineName = "����������"; break;
    case LabSubmission::Discipline::Physics: disciplineName = "������"; break;
    case LabSubmission::Discipline::Chemistry: disciplineName = "�����"; break;
    case LabSubmission::Discipline::ComputerScience: disciplineName = "�����������"; break;
    case LabSubmission::Discipline::Biology: disciplineName = "��������"; break;
    case LabSubmission::Discipline::Literature: disciplineName = "����������"; break;
    default: disciplineName = "����������� ����������"; break;
    }

    out << "\n����������: " << disciplineName << "\n";
    out << "���������� ������������ �����: " << ourObject.numLabs << "\n";
    out << "���������� ������� ������������ �����: " << ourObject.numSubmitted << "\n";
    out << "������� ������ �� ����������: " << ourObject.currentGrade << "\n";

    return out;
}

// "+="
int& operator+=(int& sum, const LabSubmission& ourObject) { //������ ��� ��� ������ � ������ const
    sum += (ourObject.getNumLabs() - ourObject.getNumSubmitted());
    return sum;
}

LabSubmission::~LabSubmission() {
    delete[] grades;
    delete[] complexities;
}
