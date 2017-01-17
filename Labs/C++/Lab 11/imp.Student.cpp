#include "class.Student.h"

Student::Student() {
  this->id = 0;
  this->name = "";
}

Student::Student(int id, string name) {
  this->id = hash(id);
  this->name = name;
}

void Student::setId(int id) {
  this->id = this->hash(id);
}

void Student::setName(string name) {
  this->name = name;
}

int Student::getId() const {
  return this->id;
}

string Student::getName() const {
  return this->name;
}

int Student::hash(int id) {
  return id % 100;
}
