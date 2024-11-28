// LabSubmission.h

#ifndef LABSUBMISSION_H
#define LABSUBMISSION_H

#include <iostream>
#include <string>
#include <stdexcept>

class LabSubmission {
public:
    enum class Discipline {
        Mathematics,
        Physics,
        Chemistry,
        ComputerScience,
        Biology,
        Literature
    };

    LabSubmission(Discipline discipline, int numLabs, int complexity = 1);

    Discipline getDiscipline() const;
    int getNumLabs() const;
    double getCurrentGrade() const;
    int getNumSubmitted() const;

    void printInfo() const;
    void submitLab(int labNumber, double grade);

    friend std::ostream& operator<<(std::ostream& out, const LabSubmission& ourObject);
    double& operator[](int labNumber);

    void recalculateGrade();
    virtual ~LabSubmission();

protected:
    Discipline discipline;
    int numLabs;
    double* grades;
    int* complexities;
    double currentGrade;
    int numSubmitted;
};

int& operator+=(int& sum, const LabSubmission& ourObject);

#endif
