#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string gender;
    int age;
    double weight;
    double height;
    std::string education;
    std::string marriageStatus;
    int passportSeries;
    int passportNumber;
    int salary;

public:
    Person() = default;

    Person(const std::string& name, const std::string& surname, const std::string& patronymic,
           const std::string& gender, const int& age, const double& weight, const double& height,
           const std::string& education, const std::string& marriageStatus, const int& passportSeries,
           const int& passportNumber, const int& salary) :
        name(name), surname(surname), patronymic(patronymic), gender(gender), age(age), weight(weight), height(height),
        education(education), marriageStatus(marriageStatus), passportSeries(passportSeries),
        passportNumber(passportNumber), salary(salary) {}

    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    std::string getPatronymic() const { return patronymic; }
    std::string getEducation() const { return education; }
    std::string getMarriageStatus() const { return marriageStatus; }
    std::string getGender() const { return gender; }
    int getAge() const { return age; }
    int getPassportSeries() const { return passportSeries; }
    int getPassportNumber() const { return passportNumber; }
    int getSalary() const { return salary; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }

    void setName(const std::string& name) { this->name = name; }
    void setSurname(const std::string& surname) { this->surname = surname; }
    void setPatronymic(const std::string& patronymic) { this->patronymic = patronymic; }
    void setEducation(const std::string& education) { this->education = education; }
    void setMarriageStatus(const std::string& marriageStatus) { this->marriageStatus = marriageStatus; }
    void setGender(const std::string& gender) { this->gender = gender; }
    void setAge(const int& age) { this->age = age; }
    void setPassportSeries(const int& passportSeries) { this->passportSeries = passportSeries; }
    void setPassportNumber(const int& passportNumber) { this->passportNumber = passportNumber; }
    void setSalary(const int& salary) { this->salary = salary; }
    void setWeight(const double& weight) { this->weight = weight; }
    void setHeight(const double& height) { this->height = height; }

    ~Person() = default;
};
#endif // PERSON_H
