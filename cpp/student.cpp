#include "student.h"

Student::Student(const Student &s)
{
    id = s.id;
    average = s.average;
}

Student::Student(const Student &&s)
{
    id = s.id;
    average = s.average;
}

Student Student::operator=(const Student &s)
{
    id = s.id;
    average = s.average;
    return *this;
}

Student Student::operator+(double avg)
{
    Student s = *this;
    s.average += avg;
    return s;
}

std::ostream &operator<<(std::ostream &os,const Student &s)
{
    os << s.id ;
    return os;
}
