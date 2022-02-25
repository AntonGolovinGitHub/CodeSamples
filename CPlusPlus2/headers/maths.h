#define E_CONST 2.7182818284590451
#define PI_CONST 3.1415926535897931

#include <vector>
#include <string>
#include <optional>

#ifndef GRG11GTESTASAHABIT_MATHS_H
#define GRG11GTESTASAHABIT_MATHS_H

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
        static long sum(long arr[], int size);
        static double sum(double vars[], int size);
        static long subtract(long value, long vars[], int size);
        static double subtract(double value, double vars[], int size);
        static long multiply(long vars[], int size);
        static double multiply(double vars[], int size);
        static double divide(long value, long vars[], int size);
        static double divide(double value, double vars[], int size);
        static long power_of(long value, long toThePowersOf[], int size);
        static double power_of(double value, long toThePowersOf[], int size);
        static double power_of(double value, double toThePowersOf[], int size);
        static vector<optional<double>> quadratic(double a, optional<double> b, optional<double> c);
        static double hypotenuse(double nearLine, double farLine);
    };

    class maths_exception : std::exception {
    private:
        string message;
    public:
        maths_exception(string m);
        ~ maths_exception();
    };

    class overflow_exception : private maths_exception {
    public:
        overflow_exception(string m);
        ~ overflow_exception();
    };
}


#endif //GRG11GTESTASAHABIT_MATHS_H
