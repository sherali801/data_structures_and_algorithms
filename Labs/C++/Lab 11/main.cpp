#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include <iostream>
#include <hash_map>
#include <conio.h>
using namespace std;

#include "class.Student.h"

int main()
{
  hash_map<int, string> map;
  typedef pair<int, string> p;
  hash_map<int, string>::iterator it;
  Student s;
  int id;
  string name;
  cout << "(1) Hash 10 records of any id and name using any hashing function\n";
  for (int i = 0; i < 10; i++) {
    cout << "Enter id: ";
    cin >> id;
    s.setId(id);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    s.setName(name);
    map.insert(p(s.getId(), s.getName()));
  }
  for (it = map.begin(); it != map.end(); it++) {
  cout << it->first << ": " << it->second << "\n";
  }
  cout << "(2) Store multiple records to any of one index of hash table\n";
  hash_multimap<int, string> map1;
  hash_multimap<int, string>::iterator iter;
  for (int i = 0; i < 5; i++) {
    cout << "Enter id: ";
    cin >> id;
    s.setId(id);
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    s.setName(name);
    map1.insert(p(s.getId(), s.getName()));
  }
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  cout << "(3) Show first, last, third and All records in Hash table\n";
  cout << "First Record: ";
  iter = map1.begin();
  cout << iter->first << ": " << iter->second << "\n";
  cout << "Last Record: ";
  iter = map1.end();
  --iter;
  cout << iter->first << ": " << iter->second << "\n";
  cout << "Third Record: ";
  iter = map1.begin();
  ++iter;
  ++iter;
  cout << iter->first << ": " << iter->second << "\n";
  cout << "All Records:\n";
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  cout << "(4) Show all records having the same id/key\n";
  cout << "Enter id: ";
  cin >> id;
  id = s.hash(id);
  iter = map1.find(id);
  if (iter == map1.end()) {
    cout << "No Record found\n";
  } else {
    while (iter != map1.end()) {
      if (iter->first == id) {
        cout << iter->first << ": " << iter->second << "\n";
      } else {
        break;
      }
      iter++;
    }
  }
  cout << "(5) Show all records having the same name/value\n";
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, name);
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    if (iter->second == name) {
      cout << iter->first << ": " << iter->second << "\n";
    }
  }
  cout << "(6) Check if a given name/value has duplication in hash table or not\n";
  cout << "Enter name: ";
  getline(cin, name);
  int count = 0;
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    if (iter->second == name) {
      count++;
    }
  }
  if (count > 1) {
    cout << "Duplicate Exist\n";
  } else {
    cout << "No Duplicate\n";
  }
  cout << "(7) Show all name/value duplication in hash table\n";
  hash_map<string, int> noDupMap;
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    if (noDupMap[iter->second] != NULL) {
      noDupMap[iter->second]++;
    } else {
      noDupMap[iter->second] = 1;
    }
  }
  hash_map<string, int>::iterator it1;
  for (it1 = noDupMap.begin(); it1 != noDupMap.end(); it1++) {
    if (it1->second > 1) {
      cout << it1->second << ": " << it1->first << "\n";
    }
  }
  cout << "(0) ";
  cout << "Size: " << map1.size() << "\n";
  cout << "(8) Delete record store at start, 50th, last index of hash table\n";
  iter = map1.begin();
  map1.erase(iter);
  iter = map1.end();
  iter--;
  map1.erase(iter);
  if (map1.size() > 50) {
    iter = map1.begin();
    for (int i = 0; i < 50; i++) {
      iter++;
    }
    map1.erase(iter);
  }
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  cout << "(9) Delete all records against a given input id/key\n";
  cout << "Enter id: ";
  cin >> id;
  id = s.hash(id);
  map1.erase(id);
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  cout << "(0) ";
  cout << "Size: " << map1.size() << "\n";
  cout << "(10) Reverse the content of hash table\n";
  hash_multimap<int, string>::reverse_iterator r1, r2;
  r1 = map1.rbegin();
  r2 = map1.rend();
  for (; r1 != r2; r1++) {
    cout << r1->first << ": " << r1->second << "\n";
  }
  cout << "(11) Make an other hash table, and add pair<key, value> of your choice\n";
  hash_multimap<int, string> map2;
  for (int i = 0; i < 5; i++) {
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    map2.insert(p(id, name));
  }
  cout << "(12) Swap content of Hash table1 and hash table2\n";
  map1.swap(map2);
  cout << "Map1\n";
  for (iter = map1.begin(); iter != map1.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  cout << "Map2\n";
  for (iter = map2.begin(); iter != map2.end(); iter++) {
    cout << iter->first << ": " << iter->second << "\n";
  }
  _getch();
  return 0;
}
