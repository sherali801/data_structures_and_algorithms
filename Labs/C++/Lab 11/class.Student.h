#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
using namespace std;

class Student {
private:
  int id;
  string name;
public:
  Student();
  Student(int id, string name);
  void setId(int id);
  void setName(string name);
  int getId() const;
  string getName() const;
  int hash(int id);
};

#endif // !STUDENT_H_
