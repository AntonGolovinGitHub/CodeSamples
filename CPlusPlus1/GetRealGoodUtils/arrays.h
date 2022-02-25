#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace getrealgoodutils {

    class arrays {
    public:
        template <typename T>
        static bool is_empty(T* o[], int size);

        template <typename T>
        static bool is_not_empty(T* o[], int size);

        template <typename T>
        static vector<long>* has_nulls_at(T* o[], int size);

        template <typename T>
        static bool has_nulls(T* o[], int size);

        template <typename T>
        static long has_nulls_count(T* o[], int size);

        template <typename T>
        static T* get_max(T* o[], int size);

        template <typename T>
        static T* get_min(T* o[], int size);

        template <typename T>
        static vector<T*>* get_peaks(T* o[], int size);

        template <typename T>
        static vector<T*>* get_troughs(T* o[], int size);
    };

    class arrays_exception {
    private:
        string message;
    public:
        arrays_exception(string m);
        ~arrays_exception();
    };

}