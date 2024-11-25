#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <utility>

class Person {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string gender;
    int age{};
    int weight{};
    int height{};
    std::string education;
    std::string maritalStatus;
    int passportSeries{};
    int passportNumber{};
    int salary{};

public:
    Person() = default;

    Person(std::string name, std::string surname, std::string patronymic,
           std::string gender, const int& age, const int& weight, const int& height,
           std::string  education, std::string  maritalStatus, const int& passportSeries,
           const int& passportNumber, const int& salary) :
        name(std::move(name)), surname(std::move(surname)), patronymic(std::move(patronymic)), gender(std::move(gender)), age(age), weight(weight), height(height),
        education(std::move(education)), maritalStatus(std::move(maritalStatus)), passportSeries(passportSeries),
        passportNumber(passportNumber), salary(salary) {}

    Person(const Person&) = default;
    Person(Person&&) noexcept = default;
    Person& operator=(const Person&) = default;
    Person& operator=(Person&&) noexcept = default;

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] std::string getSurname() const { return surname; }
    [[nodiscard]] std::string getPatronymic() const { return patronymic; }
    [[nodiscard]] std::string getEducation() const { return education; }
    [[nodiscard]] std::string getMaritalStatus() const { return maritalStatus; }
    [[nodiscard]] std::string getGender() const { return gender; }
    [[nodiscard]] int getAge() const { return age; }
    [[nodiscard]] int getPassportSeries() const { return passportSeries; }
    [[nodiscard]] int getPassportNumber() const { return passportNumber; }
    [[nodiscard]] int getSalary() const { return salary; }
    [[nodiscard]] int getWeight() const { return weight; }
    [[nodiscard]] int getHeight() const { return height; }

    void setName(const std::string& name) { this->name = name; }
    void setSurname(const std::string& surname) { this->surname = surname; }
    void setPatronymic(const std::string& patronymic) { this->patronymic = patronymic; }
    void setEducation(const std::string& education) { this->education = education; }
    void setMaritalStatus(const std::string& marriageStatus) { this->maritalStatus = marriageStatus; }
    void setGender(const std::string& gender) { this->gender = gender; }
    void setAge(const int& age) { this->age = age; }
    void setPassportSeries(const int& passportSeries) { this->passportSeries = passportSeries; }
    void setPassportNumber(const int& passportNumber) { this->passportNumber = passportNumber; }
    void setSalary(const int& salary) { this->salary = salary; }
    void setWeight(const int& weight) { this->weight = weight; }
    void setHeight(const int& height) { this->height = height; }

    ~Person() = default;
};
#endif // PERSON_H
