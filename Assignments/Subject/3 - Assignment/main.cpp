#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <conio.h>
using namespace std;

#include "class.BST.h"
#include "class.BSTNode.h"

int main()
{
  unordered_map<string, int> searchQueries;//hold all queries without redundancy
  fstream * fileHandle = new fstream();
  fileHandle->open("search-history.txt", ios::in);
  if (!fileHandle->is_open()) {
    cout << "Error while reading file.\nPress any key to continue...\n";
    _getch();
    return 0;
  }
  string query;
  while (getline(*fileHandle, query)) {
    if (searchQueries[query] == NULL) {
      searchQueries[query] = 1;
    } else {
      searchQueries[query]++;
    }
  }
  fileHandle->close();
  multimap<int, string> sortedSearchQueries;//hold all queries in ascending order according to their occurrences
  for (unordered_map<string, int>::iterator it = searchQueries.begin(); it != searchQueries.end(); it++) {
    sortedSearchQueries.insert({it->second, it->first});
  }
  searchQueries.clear();
  multimap<int, string>::reverse_iterator r1, r2;//highest is in the end so using reverse iterator
  r1 = sortedSearchQueries.rbegin();
  r2 = sortedSearchQueries.rend();
  unordered_map<string, int> topKqueries, top9KRemainingQueries;//hold top 10000 queries based on occurrences
  int i = 0;
  for (i = 0; (r1 != r2) && (i < 1000); r1++, i++) {
    topKqueries[r1->second] = r1->first;
  }
  for (i = 0; (r1 != r2) && (i < 9000); r1++, i++) {
    top9KRemainingQueries[r1->second] = r1->first;
  }
  sortedSearchQueries.clear();
  fileHandle->open("search-results.txt", ios::in);
  if (!fileHandle->is_open()) {
    cout << "Error while reading file.\nPress any key to continue...\n";
    _getch();
    return 0;
  }
  map<string, string> searchResults;
  string urls;
  while (!fileHandle->eof()) {
    getline(*fileHandle, query, ':');
    getline(*fileHandle, urls);
    searchResults[query] = urls;
  }
  fileHandle->close();
  BST tree;
  unordered_map<string, int>::iterator it = topKqueries.begin();
  map<string, string>::iterator searchResult = searchResults.begin();
  while (!topKqueries.empty()) {//storing urls for top 1000 and inserting in BST
    it = topKqueries.begin();
    searchResult = searchResults.find(it->first);
    tree.insert(it->first, searchResult->second, NULL);
    topKqueries.erase(it);
  }
  topKqueries.clear();
  cout << "Top 1000 are stored in BST\n";
  while (!top9KRemainingQueries.empty()) {//storing remaining top 9000 without urls in BST 
    it = top9KRemainingQueries.begin();
    tree.insert(it->first, "", fileHandle);
    top9KRemainingQueries.erase(it);
  }
  top9KRemainingQueries.clear();
  searchResults.clear();
  cout << "Remaining Top 9000 are stored in BST\n";
  string searchQuery = "";
  do {
    cout << "Please enter search query: ";
    getline(cin, searchQuery);
    BSTNode * node = tree.find(searchQuery);
    if (node != nullptr) {
      if (node->urls == "") {
        (node->fileHandle)->open("search-results.txt", ios::in);
        while (!node->fileHandle->eof()) {
          getline(*(node->fileHandle), query, ':');
          getline(*(node->fileHandle), urls);
          if (node->query == query) {
            cout << "Output:" << urls << "\nURLs Read From: Disk\n";
            break;
          }
        }
        (node->fileHandle)->close();
      } else {
        cout << "Output:" << node->urls << "\nURLs Read From: Memory\n";
      }
    } else {
      cout << "Not found\n";
    }
  } while (true);
  tree.clear();
  return 0;
}

