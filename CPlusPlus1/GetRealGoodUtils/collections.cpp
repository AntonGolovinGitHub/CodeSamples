#include "pch.h"

#include <string>
#include "collections.h"

using std::string;
using getrealgoodutils::collections;
using getrealgoodutils::collections_exception;

template<typename T>
bool collections::is_empty(vector<T*>& o) {

    if (&o == NULL)
        throw collections_exception(string("o is NULL!"));

    return o.size() == 0;
}

// define a concrete type of template for testing - we'll use string
template bool collections::is_empty<string>(vector<string*>& o);

template<typename T>
bool collections::is_not_empty(vector<T*>& o) {

    if (&o == NULL)
        throw collections_exception(string("o is NULL!"));

    return o.size() != 0;
}

// define a concrete type of template for testing - we'll use string
template bool collections::is_not_empty<string>(vector<string*>& o);

template<typename T>
set<long>* collections::has_nulls_at(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    set<long>* nulls = new set<long>();

    for (long i = 0; i < coll.size(); i++) {
        if (coll.at(i) == NULL)
            nulls->insert(i);
    }

    return nulls;
}

// define a concrete type of template for testing - we'll use string
template set<long>* collections::has_nulls_at<string>(vector<string*>& coll);

template<typename T>
bool collections::has_nulls(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    for (long i = 0; i < coll.size(); i++) {
        if (coll.at(i) == NULL)
            return true;
    }

    return false;

}

// define a concrete type of template for testing - we'll use string
template bool collections::has_nulls<string>(vector<string*>& coll);

template<typename T>
long collections::has_nulls_count(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    long nulls_count = 0L;
    for (long i = 0; i < coll.size(); i++) {
        if (coll.at(i) == NULL)
            nulls_count++;
    }
    return nulls_count;
}

// define a concrete type of template for testing - we'll use string
template long collections::has_nulls_count<string>(vector<string*>& coll);

template<typename T>
T* collections::get_max(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    if (coll.size() == 0)
        throw collections_exception(string("coll cannot be empty!"));

    T* max = coll[0];

    for (auto c : coll) {

        if (c == NULL)
            continue;

        if (*c > *max) {
            max = c;
        }

    }

    return max;

}

// define a concrete type of template for testing - we'll use string
template string* collections::get_max<string>(vector<string*>& coll);

template<typename T>
T* collections::get_min(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    if (coll.size() == 0)
        throw collections_exception(string("coll cannot be empty!"));

    T* min = coll[0];

    for (auto c : coll) {

        if (c == NULL) {
            min = c;
            continue;
        }

        if (*c < *min) {
            min = c;
        }

    }

    return min;
}

// define a concrete type of template for testing - we'll use string
template string* collections::get_min<string>(vector<string*>& coll);

template<typename T>
vector<T*>* collections::get_peaks(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    if (coll.size() == 0)
        throw collections_exception(string("coll cannot be empty!"));

    vector<T*>* peaks = new vector<T*>();

    if (coll.size() == 1) {
        peaks->push_back(coll.at(0));
        return peaks;
    }

    T* max = NULL;
    int i = 0;

    for (auto c : coll) {

        if (c == NULL)
            continue;

        if (i++ == 0)
        {
            max = c;
            peaks->push_back(max);
        }
        else if (*c == *max)
            peaks->push_back(c);
        else if (*c > *max)
        {
            peaks->clear();
            max = c;
            peaks->push_back(max);
        }

    }

    return peaks;
}

// define a concrete type of template for testing - we'll use long
template vector<string*>* collections::get_peaks<string>(vector<string*>& coll);

template<typename T>
vector<T*>* collections::get_troughs(vector<T*>& coll) {

    if (&coll == NULL)
        throw collections_exception(string("coll is NULL!"));

    if (coll.size() == 0)
        throw collections_exception(string("coll cannot be empty!"));

    vector<T*>* troughs = new vector<T*>();

    if (coll.size() == 1) {
        troughs->push_back(coll.at(0));
        return troughs;
    }

    T* min = NULL;
    int i = 0;

    for (auto c : coll) {

        if (c == NULL)
            continue;

        if (i++ == 0) {
            min = c;
            troughs->push_back(min);
        }
        else if (*c == *min)
            troughs->push_back(c);
        else if (*c < *min) {
            troughs->clear();
            min = c;
            troughs->push_back(min);
        }
    }

    return troughs;
}

// define a concrete type of template for testing - we'll use string
template vector<string*>* collections::get_troughs<string>(vector<string*>& coll);

collections_exception::collections_exception(string m) {
    message = m;
}

collections_exception::~collections_exception() {

}