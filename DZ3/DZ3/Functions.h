#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
using namespace std;

string Delete_Spaces(string S) {
    string result;
    bool Temp = false;

    int count = 0;
    for (char c : S) {
        if (c != ' ') {
            break;
        }
        count++;
    }

    for (char c : S) {
        if (c == ' ') {
            if (Temp) {
                result += c;
                Temp = false;
            }
        }
        else {
            result += c;
            Temp = true;
        }
    }

    if (count != 0) {
        result.insert(0, count, ' ');
    }

    return result;
}

string Delete_Comments(string S) {
    string result;
    bool Temp = false;

    for (int i = 0; i < S.size(); i++) {
        if (Temp) {
            if (S[i] == '*' && S[i + 1] == '/') {
                Temp = false;
                i++;
            }
        }
        else {
            if (S[i] == '/' && S[i + 1] == '/') {
                while (S[i] != '\n' && i < S.size()) {
                    i++;
                }
            }
            else if (S[i] == '/' && S[i + 1] == '*') {
                Temp = true;
                i++;
            }
            else {
                result += S[i];
            }
        }
    }
    return result;
}

string Find(string result, string search) {
    int pos = 0;
    string replace{ "(" + search + ")" };

    while ((pos = result.find(search, pos)) != string::npos) {
        result.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return result;
}



string Roman_to_arabic(int number) {
    string roman = "";
    while (number >= 1000) {
        roman += "M";
        number -= 1000;
    }
    if (number >= 900) {
        roman += "CM";
        number -= 900;
    }
    while (number >= 500) {
        roman += "D";
        number -= 500;
    }
    if (number >= 400) {
        roman += "CD";
        number -= 400;
    }
    while (number >= 100) {
        roman += "C";
        number -= 100;
    }
    if (number >= 90) {
        roman += "XC";
        number -= 90;
    }
    while (number >= 50) {
        roman += "L";
        number -= 50;
    }
    if (number >= 40) {
        roman += "XL";
        number -= 40;
    }
    while (number >= 10) {
        roman += "X";
        number -= 10;
    }
    if (number >= 9) {
        roman += "IX";
        number -= 9;
    }
    while (number >= 5) {
        roman += "V";
        number -= 5;
    }
    if (number >= 4) {
        roman += "IV";
        number -= 4;
    }
    while (number >= 1) {
        roman += "I";
        number -= 1;
    }
    return roman;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    for (auto x : s) {
        if (x == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            token += x;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

void File_info(const string& file_path) {
    auto tokens = split(file_path, '\\');
    string file_name_with_extension = tokens.back();
    tokens.pop_back();
    string path = "";
    for (auto token : tokens) {
        path += token + '\\';
    }
    string last_folder = tokens.empty() ? "" : tokens.back();

    auto dot_pos = file_name_with_extension.find('.');
    string file_name_without_extension = file_name_with_extension.substr(0, dot_pos);
    string file_extension = file_name_with_extension.substr(dot_pos + 1);

    cout << "Path without file name: " << path << endl;
    cout << "Name of the last folder in the path: " << last_folder << endl;
    cout << "File name with extension: " << file_name_with_extension << endl;
    cout << "File name extension: ." << file_extension << endl;
    cout << "File name without path and without extension: " << file_name_without_extension << endl;
}

string ComputeSumAndDifference(const string& str) {
    istringstream ss(str);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    auto compute = [](int a, char op, int b) {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        default: return 0;
        }
        };

    for (auto& word : words) {
        if (word.find('+') != std::string::npos || word.find('-') != string::npos) {
            int a, b;
            char op;
            istringstream(word) >> a >> op >> b;
            word = std::to_string(compute(a, op, b));
        }
    }

    ostringstream oss;
    copy(words.begin(), words.end() - 1, ostream_iterator<string>(oss, " "));
    oss << words.back();

    return oss.str();
}