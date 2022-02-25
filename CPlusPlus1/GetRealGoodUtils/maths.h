#pragma once

#define E_CONST 2.7182818284590451
#define PI_CONST 3.1415926535897931

#include <vector>
#include <string>
#include <optional>

using std::vector;
using std::string;
using std::optional;

namespace getrealgoodutils {

    class maths {
    private:
        static long safely_sum(long a, long b);
        static double safely_sum(double a, double b);
        static long safely_subtract(long a, long b);
        static double safely_subtract(double a, double b);
        static long safely_multiply(long a, long b);
        static double safely_multiply(double a, double b);
        static double safely_divide(long a, long b);
        static double safely_divide(double a, double b);
    public:
        static long sum(const long arr[], int size);
        static double sum(const double vars[], int size);
        static long subtract(long value, const long vars[], int size);
        static double subtract(double value, const double vars[], int size);
        static long multiply(const long vars[], int size);
        static double multiply(const double vars[], int size);
        static double divide(long value, const long vars[], int size);
        static double divide(double value, const double vars[], int size);
        static long power_of(long value, const long toThePowersOf[], int size);
        static double power_of(double value, const long toThePowersOf[], int size);
        static double power_of(double value, const double toThePowersOf[], int size);
        static vector<optional<double>> quadratic(double a, optional<double> b, optional<double> c);
        static double hypotenuse(double nearLine, double farLine);
    };

    class maths_exception : std::exception {
    private:
        string message;
    public:
        maths_exception(string m);
        ~maths_exception();
    };

    class overflow_exception : private maths_exception {
    public:
        overflow_exception(string m);
        ~overflow_exception();
    };
}