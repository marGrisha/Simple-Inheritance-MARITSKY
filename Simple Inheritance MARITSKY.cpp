#include <iostream>
#include <string>

class Person
{
public:
    virtual const std::string &getName() const = 0;
    virtual int getAge() const = 0;
};

class Human : public Person
{
protected:
    std::string name;
    int age;

public:
    Human(const std::string &name, int age) : name(name), age(age) {}

    const std::string &getName() const override
    {
        return name;
    }

    int getAge() const override
    {
        return age;
    }
};

class Student : public Human
{
public:
    std::string Unik;

public:
    Student(const std::string &name, int age, const std::string &Unik)
        : Human(name, age), Unik(Unik) {}

    const std::string &getUnik() const
    {
        return Unik;
    }
};

class ability : public Human
{
public:
    std::string Special_ability;

public:
    ability(const std::string &name, int age, const std::string &Special_ability)
        : Human(name, age), Special_ability(Special_ability) {}

    const std::string &getSpecial_ability() const
    {
        return Special_ability;
    }
};

class Player : public Student
{
private:
    std::string sport;

public:
    Player(const std::string &name, int age, const std::string &sport, const std::string &Unik)
        : Student(name, age, Unik), sport(sport) {}

    const std::string &getSport() const
    {
        return sport;
    }
};

class Professor : public ability, public Student
{
private:
    std::string subject_area;

public:
    Professor(const std::string &name, int age, const std::string &Unik, const std::string &Special_ability, const std::string &subject_area)
        : ability(name, age, Special_ability), Student(name, age, Unik), subject_area(subject_area) {}

    const std::string &getsubject_area() const
    {
        return subject_area;
    }
};

int main()
{
    Human human("Лешик", 25);
    Student student("Иван", 18, "ДВФУ");
    ability ability("Александр А.Д.", 19, " Пропускать пары");
    Player Player("Влад", 21, "ДВФУ", "Теннис");
    Professor Professor("Ольга", 36, "ДВФУ", "Понимание к студентам", "Матиматический анализ");

    std::cout << "Имя человека: " << human.getName() << ", Возраст: " << human.getAge() << std::endl;

    std::cout << "Имя бедолаги: " << student.getName() << ", Возраст: " << student.getAge() << ", Университет: " << student.getUnik() << std::endl;

    std::cout << "Имя человека: " << ability.getName() << ", Возраст: " << ability.getAge() << ", Особенность: " << ability.getSpecial_ability() << std::endl;

    std::cout << "Имя спортсмена: " << Player.Student::getName() << ", Возраст: " << Player.Student::getAge() << ", Университет: " << Player.getSport() << ", Вид спорта: " << Player.getUnik() << std::endl;

    std::cout << "Имя препода: " << Professor.Student::getName() << ", Возраст: " << Professor.Student::getAge() << ", Университет: " << Professor.getUnik() << ", Предмет: " << Professor.getsubject_area() << ", Особенность: " << Professor.getSpecial_ability() << std::endl;

    return 0;
}