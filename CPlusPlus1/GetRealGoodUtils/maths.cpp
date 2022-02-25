#include "pch.h"

#include <stdexcept>
#include <limits>
#include "maths.h"

using namespace getrealgoodutils;
using namespace std;

using std::numeric_limits;


long maths::safely_sum(long a, long b) {
    if (a == 0 || b == 0)
        return a + b;

    long result;

    if (a < 0) {
        if (b < 0) {

            // 
            // check for negative overflow
            if (LONG_MIN - b <= a) {
                result = a + b;
            }
            else {
                throw overflow_exception(string("Negative overflow!"));
            }
        }
        else {
            result = a + b;
        }
    }
    else {

        if (b < 0) {
            result = a + b;
        }
        else {

            // check for positive overflow
            if (LONG_MAX - b >= a) {
                result = a + b;
            }
            else {
                throw overflow_exception(string("Positive overflow!"));
            }
        }
    }


    return result;
}

double maths::safely_sum(double a, double b) {

    if (a == 0.0 || b == 0.0)
        return a + b;

    double result = a + b;

    if (result == numeric_limits<double>::infinity())
        throw overflow_exception(string("Positive overflow!"));

    if (result == -numeric_limits<double>::infinity())
        throw overflow_exception(string("Negative overflow!"));

    return result;
}

long maths::safely_subtract(long a, long b) {

    if (a == 0 || b == 0)
        return a - b;

    if (b < 0) {
        return maths::safely_sum(a, b);
    }
    else {
        long b1 = -b;
        return maths::safely_sum(a, b1);
    }
}

double maths::safely_subtract(double a, double b) {

    if (a == 0.0 || b == 0.0)
        return a - b;

    double result = a - b;

    if (result == numeric_limits<double>::infinity())
        throw overflow_exception(string("Positive overflow!"));

    if (result == -numeric_limits<double>::infinity())
        throw overflow_exception(string("Negative overflow!"));

    return result;
}

long maths::safely_multiply(long a, long b) {

    if (a == 0 || b == 0)
        return 0;

    long result = a * b;

    if (a == result / b)
        return result;
    else
        throw overflow_exception(string("Overflow!"));
}

double maths::safely_multiply(double a, double b) {

    if (a == 0.00 || b == 0.00)
        return 0.00;

    double result = a * b;
    if (result == numeric_limits<double>::infinity())
        throw overflow_exception(string("Positive overflow"));

    if (result == -numeric_limits<double>::infinity())
        throw overflow_exception(string("Negative overflow"));

    return result;
}

double maths::safely_divide(long a, long b) {

    if (a == 0L)
        return 0L;
    if (b == 0L)
        throw maths_exception(string("Division by zero"));

    long result = a / b;

    if (result == 0 || a == result * b)
        return result;
    else
        throw overflow_exception(string("Overflow!"));
}

double maths::safely_divide(double a, double b) {
    if (a == 0.00)
        return 0.00;
    if (b == 0.00)
        throw maths_exception(string("Division by zero"));

    double result = a / b;
    if (result == numeric_limits<double>::infinity())
        throw overflow_exception(string("Positive overflow"));

    if (result == -numeric_limits<double>::infinity())
        throw overflow_exception(string("Negative overflow"));

    return result;
}

long maths::sum(const long arr[], int size) {

    if (arr == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        return 0;

    long result = 0;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_sum(result, arr[i]);
        }

    }
    catch (maths_exception& ex) {
        ;
        throw ex;
    }

    return result;
}
double maths::sum(const double vars[], int size) {
    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        return 0;

    double result = 0;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_sum(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;
}

long maths::subtract(long value, const long vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        return 0;

    long result = value;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_subtract(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;
}

double maths::subtract(double value, const double vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        return 0;

    double result = value;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_subtract(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;

}

long maths::multiply(const long vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in!"));

    if (size == 0)
        throw maths_exception(string("Empty value passed in!"));

    long result = 1;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_multiply(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;
}

double maths::multiply(const double vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        if (size == 0)
            throw maths_exception(string("Empty value passed in!"));

    double result = 1.00;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_multiply(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;
}

double maths::divide(long value, const long vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        if (size == 0)
            throw maths_exception(string("Empty value passed in!"));

    long result = value;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_divide(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;

}

double maths::divide(double value, const double vars[], int size) {

    if (vars == NULL)
        throw maths_exception(string("Null value passed in"));

    if (size == 0)
        throw maths_exception(string("Empty value passed in!"));

    double result = value;

    try {

        for (int i = 0; i < size; i++) {
            result = safely_divide(result, vars[i]);
        }

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;

}

long maths::power_of(long value, const long toThePowersOf[], int size) {

    if (toThePowersOf == NULL)
        throw maths_exception(string("Null value passed in!"));

    if (size == 0)
        throw maths_exception(string("Empty value passed in!"));

    long result = value;

    try {

        long totalPowerOf = sum(toThePowersOf, size);

        if (totalPowerOf == 0)
            return 1;

        if (totalPowerOf == 1)
            return value;

        int powerOf = 1;

        while (powerOf++ < totalPowerOf)
            result = safely_multiply(result, value);

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    if (result == numeric_limits<long>::infinity())
        throw maths_exception(string("Positive overflow!"));
    if (result == -numeric_limits<long>::infinity())
        throw maths_exception(string("Negative overflow!"));

    return result;
}

double maths::power_of(double value, const long toThePowersOf[], int size) {

    if (toThePowersOf == NULL)
        throw maths_exception(string("Null value passed in!"));

    if (size == 0)
        throw maths_exception(string("Empty value passed in!"));

    double result = value;

    try {

        long totalPowerOf = sum(toThePowersOf, size);

        if (totalPowerOf == 0)
            return 1;

        if (totalPowerOf == 1)
            return value;

        int powerOf = 1;

        while (powerOf++ < totalPowerOf)
            result = safely_multiply(result, value);

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    if (result == numeric_limits<double>::infinity())
        throw maths_exception(string("Positive overflow!"));
    if (result == -numeric_limits<double>::infinity())
        throw maths_exception(string("Negative overflow!"));

    return result;

}

double maths::power_of(double value, const double toThePowersOf[], int size) {

    if (toThePowersOf == NULL)
        throw maths_exception(string("Null value passed in!"));

    if (size == 0)
        throw maths_exception(string("Empty value passed in!"));

    double result = value;

    try {

        long totalPowerOf = sum(toThePowersOf, size);

        if (totalPowerOf == 0)
            return 1;

        if (totalPowerOf == 1)
            return value;

        int powerOf = 1;

        while (powerOf++ < totalPowerOf)
            result = safely_multiply(result, value);

    }
    catch (maths_exception& ex) {
        throw ex;
    }

    if (result == numeric_limits<double>::infinity())
        throw maths_exception(string("Positive overflow!"));
    if (result == -numeric_limits<double>::infinity())
        throw maths_exception(string("Negative overflow!"));

    return result;


}

vector<optional<double>> maths::quadratic(double a, optional<double> b, optional<double> c) {

    auto result = vector<optional<double>>(0);

    try {
        // a is never null or zero
        if (a == 0.00)
            throw maths_exception(string("Coefficient a is zero"));

        auto b1 = !b.has_value() ? 0.00 : b.value();
        auto c1 = !c.has_value() ? 0.00 : c.value();

        if (b1 == 0.00 && c1 == 0.00) {
            // only one solution
            result.push_back(optional<double>(0));

            return result;
        }

        auto partOne = -b1;
        auto partTwo = pow(safely_subtract(safely_multiply(b1, b1),
            safely_multiply(4.00, safely_multiply(a, c1))), 0.5);

        auto partThree = safely_multiply(2.00, a);

        result.push_back(safely_divide(safely_sum(partOne, partTwo), partThree));
        result.push_back(safely_divide(safely_subtract(partOne, partTwo), partThree));
    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;

}

double maths::hypotenuse(double nearLine, double farLine) {

    if (nearLine <= 0)
        throw maths_exception(string("Invalid parameter value for nearLine (<=0)!"));

    if (farLine <= 0)
        throw maths_exception(string("Invalid parameter value for farLine (<=0)!"));

    double result;

    try {

        result = pow(safely_sum(safely_multiply(
            nearLine, nearLine), safely_multiply(farLine, farLine)), 0.5);
    }
    catch (maths_exception& ex) {
        throw ex;
    }

    return result;
}

maths_exception::maths_exception(string m) {
    message = m;
}

maths_exception::~maths_exception() {

}

overflow_exception::overflow_exception(string m) : maths_exception(m) {
}

overflow_exception::~overflow_exception() {
}