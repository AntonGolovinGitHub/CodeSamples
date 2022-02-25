#include "pch.h"

#include "arrays.h"

using std::string;
using getrealgoodutils::arrays;
using getrealgoodutils::arrays_exception;

template<typename T>
bool arrays::is_empty(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string(""));

    return size == 0;
}

// define a concrete type of template for testing - we'll use string
template bool arrays::is_empty<string>(string* o[], int size);

template<typename T>
bool arrays::is_not_empty(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string(""));

    return size != 0;
}

// define a concrete type of template for testing - we'll use string
template bool arrays::is_not_empty<string>(string* o[], int size);

template<typename T>
vector<long>* arrays::has_nulls_at(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o is NULL!"));

    vector<long>* nulls = new vector<long>();

    for (long i = 0; i < size; i++) {
        if (o[i] == NULL)
            nulls->push_back(i);
    }

    return nulls;
}

// define a concrete type of template for testing - we'll use string
template vector<long>* arrays::has_nulls_at<string>(string* o[], int size);

template<typename T>
bool arrays::has_nulls(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o is NULL!"));

    for (long i = 0; i < size; i++) {
        if (o[i] == NULL)
            return true;
    }

    return false;

}
// define a concrete type of template for testing - we'll use string
template bool arrays::has_nulls<string>(string* o[], int size);


template<typename T>
long arrays::has_nulls_count(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o is NULL!"));

    long nulls_count = 0L;
    for (long i = 0; i < size; i++) {
        if (o[i] == NULL)
            nulls_count++;
    }
    return nulls_count;
}

// define a concrete type of template for testing - we'll use string
template long arrays::has_nulls_count<string>(string* o[], int size);

template<typename T> T* arrays::get_max(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o is NULL!"));

    if (size == 0)
        throw arrays_exception(string("o cannot be empty!"));

    T* max = o[0];

    for (auto c = 0; c < size; c++) {

        if (o[c] == NULL)
            continue;

        if (*o[c] > *max) {
            max = o[c];
        }

    }

    if (max == NULL)
        throw arrays_exception(string("o contains only NULLs!"));

    return max;

}

// define a concrete type of template for testing - we'll use string
template string* arrays::get_max<string>(string* o[], int size);

template<typename T>
T* arrays::get_min(T* o[], int size) {

    if (size == 0)
        throw arrays_exception(string("o cannot be empty!"));

    T* min = o[0];

    for (auto c = 0; c < size; c++) {

        if (o[c] == NULL)
            continue;

        if (*o[c] < *min) {
            min = o[c];
        }

    }

    if (min == NULL)
        throw arrays_exception(string("o contains only NULLs!"));

    return min;
}

// define a concrete type of template for testing - we'll use string
template string* arrays::get_min<string>(string* o[], int size);

template<typename T>
vector<T*>* arrays::get_peaks(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o cannot be NULL!"));

    if (size == 0)
        throw arrays_exception(string("o cannot be empty!"));

    vector<T*>* peaks = new vector<T*>();

    if (size == 1) {
        peaks->push_back(o[0]);
        return peaks;
    }

    T* max = NULL;
    int i = 0;

    for (auto c = 0; c < size; c++) {

        if (o[c] == NULL)
            continue;

        if (i++ == 0)
        {
            max = o[c];
            peaks->push_back(max);
        }
        else if (*o[c] == *max)
            peaks->push_back(o[c]);
        else if (*o[c] > *max)
        {
            peaks->clear();
            max = o[c];
            peaks->push_back(max);
        }

    }

    return peaks;
}

// define a concrete type of template for testing - we'll use string
template vector<string*>* arrays::get_peaks<string>(string* o[], int size);

template<typename T>
vector<T*>* arrays::get_troughs(T* o[], int size) {

    if (o == NULL)
        throw arrays_exception(string("o is NULL!"));

    if (size == 0)
        throw arrays_exception(string("coll cannot be empty!"));

    vector<T*>* troughs = new vector<T*>();

    if (size == 1) {
        troughs->push_back(o[0]);
        return troughs;
    }

    T* min = NULL;
    int i = 0;

    for (auto c = 0; c < size; c++) {

        if (o[c] == NULL)
            continue;

        if (i++ == 0) {
            min = o[c];
            troughs->push_back(min);
        }
        else if (*o[c] == *min)
            troughs->push_back(o[c]);
        else if (*o[c] < *min) {
            troughs->clear();
            min = o[c];
            troughs->push_back(min);
        }
    }

    return troughs;
}

// define a concrete type of template for testing - we'll use string
template vector<string*>* arrays::get_troughs<string>(string* o[], int size);

arrays_exception::arrays_exception(string m) {
    message = m;
}

arrays_exception::~arrays_exception() {

}





