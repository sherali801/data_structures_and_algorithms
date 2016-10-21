#include <iostream>
#include <conio.h>
using namespace std;

class Singleton {
  private:
    static Singleton * single;
    int i;
    Singleton() { i = 5; }
  public:
    static Singleton * getInstance() {
      if (!single) {
        single = new Singleton;
        cout << "new!";
      }
      return single;
    }
    int get() const { return i;  }
    ~Singleton() { delete single; }
};

Singleton * Singleton::single = NULL;

int main()
{
  Singleton *obj = Singleton::getInstance();
  Singleton *obj2 = Singleton::getInstance();
  _getch();
  return 0;
}

