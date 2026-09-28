#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


class Person
{
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age);

    const std::string& getName() const;
    int getAge() const;

    virtual void displayInfo(std::ostream& out) const = 0;
    virtual void introduce(std::ostream& out) const;

    virtual ~Person() = default;
};


//setup student class, priv/public attributes
class Student : public Person
{
private:
    std::string studentID;
    double gpa;

public:
    Student(const std::string& name, int age,
            const std::string& studentID, double gpa);

    void displayInfo(std::ostream& out) const override;
    void introduce(std::ostream& out) const override;
};


class Teacher : public Person
{
private:
    std::string subject;
    int yearsOfExperience;

public:
    Teacher(const std::string& name, int age,
            const std::string& subject, int yearsOfExperience);

    void displayInfo(std::ostream& out) const override;
    void introduce(std::ostream& out) const override;
};


//initialize priv Person
Person::Person(const std::string& name, int age)
    : name(name), age(age)
{
}


//return functions
const std::string& Person::getName() const
{
    return name;
}
int Person::getAge() const
{
    return age;
}


// Given "Person" introduction
void Person::introduce(std::ostream& out) const
{
    out << "I am a person. My name is "
        << getName() << ".\n";
}


// Initialize the Person data and Student data.
Student::Student(const std::string& name, int age,
                 const std::string& studentID, double gpa)
    : Person(name, age),
      studentID(studentID),
      gpa(gpa)
{
}


// Write the Student information line.
void Student::displayInfo(std::ostream& out) const
{
    out << "Student: " << getName()
        << ", Age: " << getAge()
        << ", ID: " << studentID
        << ", GPA: " << std::fixed << std::setprecision(1)
        << gpa << '\n';
}


// Write the Student introduction line.
void Student::introduce(std::ostream& out) const
{
    out << "I am a student. My name is "
        << getName() << ".\n";
}


// Initialize the Person data and Teacher data.
Teacher::Teacher(const std::string& name, int age,
                 const std::string& subject,
                 int yearsOfExperience)
    : Person(name, age),
      subject(subject),
      yearsOfExperience(yearsOfExperience)
{
}


// Write the Teacher information line.
void Teacher::displayInfo(std::ostream& out) const
{
    out << "Teacher: " << getName()
        << ", Age: " << getAge()
        << ", Subject: " << subject
        << ", Experience: " << yearsOfExperience
        << " years\n";
}


// Write the Teacher introduction line.
void Teacher::introduce(std::ostream& out) const
{
    out << "I am a teacher. My name is "
        << getName() << ".\n";
}


int main()
{
    int numberOfPeople;
    std::cin >> numberOfPeople;

    std::vector<Person*> people;
    people.reserve(numberOfPeople);

    // Read each record and construct the appropriate object.
    for (int i = 0; i < numberOfPeople; i++)
    {
        std::string type;
        std::string name;
        int age;

        std::cin >> type >> name >> age;

        if (type == "Student")
        {
            std::string studentID;
            double gpa;

            std::cin >> studentID >> gpa;

            people.push_back(
                new Student(name, age, studentID, gpa)
            );
        }
        else if (type == "Teacher")
        {
            std::string subject;
            int yearsOfExperience;

            std::cin >> subject >> yearsOfExperience;

            people.push_back(
                new Teacher(name, age, subject, yearsOfExperience)
            );
        }
    }

    // Use virtual dispatch to produce both lines for each person.
    for (Person* person : people)
    {
        person->displayInfo(std::cout);
        person->introduce(std::cout);
    }

    // Delete every dynamically allocated object exactly once.
    for (Person* person : people)
    {
        delete person;
    }

    return 0;
}
