#include "LabSubmission.h"

//+ complexity
LabSubmission::LabSubmission(Discipline discipline, int numLabs, int complexity)
    : discipline(discipline), numLabs(numLabs), currentGrade(0.0), numSubmitted(0)
{
    if (numLabs <= 0) {
        throw std::invalid_argument("Количество лабораторных работ должно быть положительным.");
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
    case Discipline::Mathematics: disciplineName = "Математика"; break;
    case Discipline::Physics: disciplineName = "Физика"; break;
    case Discipline::Chemistry: disciplineName = "Химия"; break;
    case Discipline::ComputerScience: disciplineName = "Информатика"; break;
    case Discipline::Biology: disciplineName = "Биология"; break;
    case Discipline::Literature: disciplineName = "Литература"; break;
    default: disciplineName = "Неизвестная дисциплина"; break;
    }

    std::cout << "Дисциплина: " << disciplineName << std::endl;
    std::cout << "Количество лабораторных работ: " << numLabs << std::endl;
    std::cout << "Количество сданных лабораторных работ: " << numSubmitted << std::endl;
    std::cout << "Текущая оценка по дисциплине: " << currentGrade << std::endl;
}

void LabSubmission::submitLab(int labNumber, double grade) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("Номер лабораторной работы вне допустимого диапазона.");
    }

    if (grade < 0.0 || grade > 100.0) {
        throw std::invalid_argument("Оценка должна быть в диапазоне от 0 до 100.");
    }

    int index = labNumber - 1;

    if (grades[index] != 0.0) {
        throw std::logic_error("Лабораторная работа уже была сдана.");
    }

    grades[index] = grade;
    numSubmitted++;
    recalculateGrade();
}

//  "[]"
double& LabSubmission::operator[](int labNumber) {
    if (labNumber < 1 || labNumber > numLabs) {
        throw std::out_of_range("Номер лабораторной работы вне допустимого диапазона.");
    }

    int index = labNumber - 1;

    // Проверка если лабораторная еще не сдана, увеличиваем счетчик сданных работ
    if (grades[index] == 0.0) {
        numSubmitted++;
    }

    return grades[index];
}

// Метод для пересчета средней оценки
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
    case LabSubmission::Discipline::Mathematics: disciplineName = "Математика"; break;
    case LabSubmission::Discipline::Physics: disciplineName = "Физика"; break;
    case LabSubmission::Discipline::Chemistry: disciplineName = "Химия"; break;
    case LabSubmission::Discipline::ComputerScience: disciplineName = "Информатика"; break;
    case LabSubmission::Discipline::Biology: disciplineName = "Биология"; break;
    case LabSubmission::Discipline::Literature: disciplineName = "Литература"; break;
    default: disciplineName = "Неизвестная дисциплина"; break;
    }

    out << "\nДисциплина: " << disciplineName << "\n";
    out << "Количество лабораторных работ: " << ourObject.numLabs << "\n";
    out << "Количество сданных лабораторных работ: " << ourObject.numSubmitted << "\n";
    out << "Текущая оценка по дисциплине: " << ourObject.currentGrade << "\n";

    return out;
}

// "+="
int& operator+=(int& sum, const LabSubmission& ourObject) { //вопрос поч вне класса и почему const
    sum += (ourObject.getNumLabs() - ourObject.getNumSubmitted());
    return sum;
}

LabSubmission::~LabSubmission() {
    delete[] grades;
    delete[] complexities;
}
