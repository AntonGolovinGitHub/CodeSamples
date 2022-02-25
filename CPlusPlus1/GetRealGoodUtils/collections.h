#pragma once

#include <vector>
#include <set>
#include <string>

using std::vector;
using std::set;
using std::string;

namespace getrealgoodutils {

    class collections {
    public:
        template <typename T>
        static bool is_empty(vector<T*>& o);

        template <typename T>
        static bool is_not_empty(vector<T*>& o);

        template <typename T>
        static set<long>* has_nulls_at(vector<T*>& coll);

        template <typename T>
        static bool has_nulls(vector<T*>& coll);

        template <typename T>
        static long has_nulls_count(vector<T*>& coll);

        template <typename T>
        static T* get_max(vector<T*>& coll);

        template <typename T>
        static T* get_min(vector<T*>& coll);

        template <typename T>
        static vector<T*>* get_peaks(vector<T*>& coll);

        template <typename T>
        static vector<T*>* get_troughs(vector<T*>& coll);

    };

    class collections_exception {
    private:
        string message;
    public:
        collections_exception(string m);
        ~collections_exception();
    };
}