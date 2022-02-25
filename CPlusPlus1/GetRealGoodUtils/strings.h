#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace getrealgoodutils {

    class strings {
    public:
        strings();

        static string* to_upper(string* s);
        static string* to_lower(string* s);
        static vector<string*>* split(string& s, string& token, bool trim);
        static string* concat(vector<string*>& s, string& token, bool trim);
        static string* replace(string& s, char orig, char w, bool trim);
        static string* replace(string& s, char orig, char w);
    private:
        static string& trim(string& s);
    };

    class strings_exception : std::exception {
    private:
        string message;

    public:
        strings_exception(string m);
        ~strings_exception();
    };
}