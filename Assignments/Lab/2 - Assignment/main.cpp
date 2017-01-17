#include <iostream>
#include <string>
#include <map>
#include <conio.h>
using namespace std;

string generateHash(string str) {
  string key = "";
  for (int i = 0; i < str.size() && i < 3; i++) {
    key += tolower(str[i]);
  }
  return key;
}

string parseWord(string str) {
  string parsed = "";
  for (int i = 0; i < str.size() && str[i] != ':'; i++) {
    parsed += str[i];
  }
  return parsed;
}

string parseType(string str) {
  int i = 0;
  string parsed = "";
  for (; i < str.size() && str[i] != ':'; i++) { }
  i++;
  for (; i < str.size(); i++) {
    parsed += str[i];
  }
  return parsed;
}

bool compare(string str1, string str2) {
  if (str1.size() < str2.size()) {
    return false;
  }
  for (int i = 0; i < str2.size(); i++) {
    if (toupper(str1[i]) != toupper(str2[i])) {
      return false;
    }
  }
  return true;
}

int main()
{
  multimap<string, string> map1;
  typedef pair<string, string> p;
  multimap<string, string>::iterator it;
  string word = "", type = "", key = "", parsed = "";
  int num;
  cout << "(1)\nStore Words and their Types using hash function\nHow many Words you want to enter: ";
  cin >> num;
  cin.ignore();
  for (int i = 0; i < num; i++) {
    cout << "Enter Word: ";
    getline(cin, word);
    key = generateHash(word);
    cout << "Enter Type: ";
    getline(cin, type);
    map1.insert(p(key, word + ":" + type));
  }
  cout << "(2)\nSearch a particular Word in a table\nEnter Word: ";
  getline(cin, word);
  key = generateHash(word);
  it = map1.find(key);
  if (it == map1.end()) {
    cout << "Word " << word << " not found. Enter type to store it in table: ";
    cin.ignore();
    getline(cin, type);
    map1.insert(p(key, word + type));
  } else {
    while (key == it->first) {
      parsed = parseWord(it->second);
      if (word == parsed) {
        parsed = parseType(it->second);
        cout << "Word: " << word << "\nType: " << parsed << "\n";
      }
      it++;
    }
  }
  cout << "(3)\nDisplay all Words in the table\nWords: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    cout << parseWord(it->second) << ", ";
  }
  cout << "\n(4)\nDisplay all words starting with given pattern\nEnter Word/Pattern: ";
  getline(cin, word);
  for (it = map1.begin(); it != map1.end(); it++) {
    if (compare(parseWord(it->second), word)) {
      cout << parseWord(it->second) << ": " << parseType(it->second) << "\n";
    }
  }
  cout << "(5)\nDisplay all Verbs, Nouns, Adjectives\nVerbs: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    if (parseType(it->second) == "verb") {
      cout << parseWord(it->second) << ", ";
    }
  }
  cout << "\nNouns: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    if (parseType(it->second) == "noun") {
      cout << parseWord(it->second) << ", ";
    }
  }
  cout << "\nAdjectives: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    if (parseType(it->second) == "adjective") {
      cout << parseWord(it->second) << ", ";
    }
  }
  cout << "\n(6)\nDisplay all Words stored at a particular index\nEnter Index: ";
  getline(cin, key);
  it = map1.find(key);
  if (it == map1.end()) {
    cout << "No Word against given key\n";
  } else {
    cout << "Words: ";
    for (; it->first == key; it++) {
      cout << parseWord(it->second) << ", ";
    }
  }
  cout << "\n(7)\nErase words stored at first, last and int index of table\n";
  it = map1.begin();
  map1.erase(it);
  it = map1.end();
  it--;
  map1.erase(it);
  for (it = map1.begin(); it != map1.end() && it->first != "int"; it++) { }
  if (it != map1.end()) {
    map1.erase(it);
  }
  cout << "(0)\nDisplay all words stored in the table\nWords: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    cout << parseWord(it->second) << ", ";
  }
  cout << "\n(8)\nReverse the content of table\n";
  multimap<string, string>::reverse_iterator r1, r2;
  r1 = map1.rbegin();
  r2 = map1.rend();
  cout << "Words: ";
  for (; r1 != r2; r1++) {
    cout << parseWord(r1->second) << ", ";
  }
  cout << "\n(9)\nMake another table and insert 5 pairs\n";
  multimap<string, string> map2;
  for (int i = 0; i < 5; i++) {
    cout << "Enter Word: ";
    getline(cin, word);
    key = generateHash(word);
    cout << "Enter Type: ";
    getline(cin, type);
    map2.insert(p(key, word + ":" + type));
  }
  cout << "Words in map2: ";
  for (it = map2.begin(); it != map2.end(); it++) {
    cout << parseWord(it->second) << ", ";
  }
  cout << "\n(10)\nSwap the content of map1 and map2\n";
  map1.swap(map2);
  cout << "Words in map1: ";
  for (it = map1.begin(); it != map1.end(); it++) {
    cout << parseWord(it->second) << ", ";
  }
  cout << "\nWords in map2: ";
  for (it = map2.begin(); it != map2.end(); it++) {
    cout << parseWord(it->second) << ", ";
  }
  cout << "\n";
  _getch();
  return 0;
}