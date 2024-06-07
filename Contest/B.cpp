#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void format_commit_message() {
  int n;
  cin >> n;
  cin.ignore();  // 忽略换行符
  
  for (int t = 0; t < n; ++t) {
    string line;
    getline(cin, line);
    
    istringstream iss(line);
    vector<string> words;
    string word;
    
    while (iss >> word) {
      words.push_back(word);
    }
    
    int length = 0;
    for (int i = 0; i < words.size(); ++i) {
      if (length + words[i].size() + (length > 0 ? 1 : 0) > 72) {
        cout << "\n";
        length = 0;
      }
      
      if (length > 0) {
        cout << " ";
        length++;
      }
      
      cout << words[i];
      length += words[i].size();
    }
    
    if (t < n - 1) {
      cout << "\n";
    }
  }
}

int main() {
  format_commit_message();
  return 0;
}
