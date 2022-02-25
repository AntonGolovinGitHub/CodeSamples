#include "pch.h"

#include "strings.h"
#include <string>
#include <vector>

#include <cctype>

using std::string;
using std::vector;
using namespace getrealgoodutils;

// returns a pointer to a new string; make sure to delete the
// old string's pointer when not needed anymore
string* strings::to_upper(string* s) {

    if (s == nullptr)
        throw strings_exception(string("string *s == NULL"));

    vector<char> chars;
    int i = 0;

    for (auto& c : *s)
        chars.push_back(toupper(c));

    return new string(chars.begin(), chars.end());

}

// returns a pointer to a new string; make sure to delete the
// old string's pointer when not needed anymore
string* strings::to_lower(string* s) {

    if (s == nullptr)
        throw strings_exception(string("string *s == NULL"));

    vector<char> chars;

    for (auto c : *s)
        chars.push_back(tolower(c));

    return new string(chars.begin(), chars.end());
}

string* strings::concat(vector<string*>& s, string& token, bool trim) {

    string cs;
    string result = string("");

    for (auto c : s) {
        cs = *c;
        if (trim)
            cs = strings::trim(cs);

        if (cs.length() == 0)
            continue;

        result.append(cs);
        result.append(token);
    }

    // delete end token, if applicable
    if (result.length() >= token.length()) {

        int token_length = token.length();
        int result_length = result.length();
        int begin = result_length - token_length;
        int end = result_length;
        result = result.erase(begin, end);

    }

    return new string(result);

}

vector<string*>* strings::split(string& s, string& token, bool trim) {

    string str = s;

    if (trim)
        str = strings::trim(str);

    if (str.length() == 0)
        return new vector<string*>(0);

    string delimiter = token;

    vector<string*>* v = new vector<string*>();

    size_t pos = 0;
    std::string tkn;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        tkn = str.substr(0, pos);
        v->push_back(new string(tkn));
        str.erase(0, pos + delimiter.length());
    }
    v->push_back(new string(str));
    return v;
}

string* strings::replace(string& s, char orig, char w, bool trim) {

    string sc = s;
    string repl = string(1, w);

    if (trim)
        sc = strings::trim(sc);

    if (sc.size() == 0)
        return new string(sc);

    for (auto i = 0; i <= sc.length() - 1; i++)
        if (sc.at(i) == orig)
            sc = sc.replace(i, 1, repl);

    return new string(sc);
}

string* strings::replace(string& s, char orig, char w) {

    return strings::replace(s, orig, w, false);
}

string& strings::trim(string& str) {

    if (str.length() == 0)
        return str;

    int begin = 0;
    int end = str.length() - 1;

    // find begin offset

    for (auto c : str) {
        if (c != ' ')
            break;
        begin++;
    }

    for (auto c = str.length() - 1; c >= 0; c--) {
        if (str.at(c) != ' ')
            break;
        end--;
    }

    str = str.erase(end + 1, str.length());
    str = str.erase(0, begin);

    return str;
}

strings_exception::strings_exception(string m) {
    message = m;
}

strings_exception::~strings_exception() {

}