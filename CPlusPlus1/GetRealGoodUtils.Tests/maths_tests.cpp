#include "pch.h"
#include "CppUnitTest.h"

#include "maths.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace getrealgoodutils;

namespace getrealgoodutilstests {

    TEST_CLASS(maths_tests)
    {

    public:



        TEST_METHOD(sum_common_longarray_int_long) {

            try
            {
                long values[] = { 10, 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(70 == maths::sum(values, sizeof(values) / sizeof(values[0])));

            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(sum_common_longarray_int_long__1) {

            try {
                long values[] = { 10 };
                Assert::IsTrue(10 == maths::sum(values, sizeof(values) / sizeof(values[0])));

            }
            catch (exception& ex) {
                
                Assert::Assert::Fail();
            }
        }


        TEST_METHOD(sum_exceptional_longarray_int_maths_exception) {

            try
            {
                long values[] = { numeric_limits<long>::max(), numeric_limits<long>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::sum(values, 2); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_exceptional_longarray_int_maths_exception__1) {

            try
            {
                long values[] = { numeric_limits<long>::min(), numeric_limits<long>::min() };
                Assert::ExpectException<overflow_exception>([values] { maths::sum(values, 2); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_special_longarray_int_long) {

            try
            {
                long values[] = { 0,0,0,0,0,0,0 };
                Assert::IsTrue(0 == maths::sum(values, 7));
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_nullable_longnullptr_int_maths_exception) {

            try
            {
                long* values = NULL;
                Assert::ExpectException<maths_exception>([values] { maths::sum(values, 0);});
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_common_doublearray_int_double) {

            try
            {
                double values[] = { 10, 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(70.0 == maths::sum(values, sizeof(values) / sizeof(values[0])));
            }
            catch (maths_exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(sum_common_doublearray_int_double__1) {

            try {
                double values[] = { 10 };
                Assert::IsTrue(10.0 == maths::sum(values, sizeof(values) / sizeof(values[0])));
            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }


        TEST_METHOD(sum_exceptional_doublearray_int_maths_exception) {

            try
            {
                double values[] = { numeric_limits<double>::max(), numeric_limits<double>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::sum(values, 2); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_exceptional_doublearray_int_maths_exception__1) {

            try
            {
                double values[] = { -numeric_limits<double>::max(), -numeric_limits<double>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::sum(values, 2); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_special_doublearray_int_double) {

            try
            {
                long values[] = { 0,0,0,0,0,0,0 };
                Assert::IsTrue(0.0 == maths::sum(values, 7));
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(sum_nullable_doublenullptr_int_maths_exception) {

            try
            {
                double* values = NULL;
                Assert::ExpectException<maths_exception>([values] { maths::sum(values, 0); });
                delete values;
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(subtract_common_long_longarray_int_long) {

            try {
                long values[] = { 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(-50 == maths::subtract(10, values, 6));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(subtract_common_long_longaray_int_long__1) {

            try {
                long value[] = { 10 };
                Assert::IsTrue(0 == maths::subtract(10, value, 1));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(subtract_exceptional_long_longaray_int_math_exception) {

            try {
                long values[] = { numeric_limits<long>::min(), numeric_limits<long>::min() };
                Assert::ExpectException<overflow_exception>([values] { maths::subtract(0, values, 2); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_exceptional_long_longarray_int_math_exception__1) {

            try {
                long values[] = { numeric_limits<long>::max(), numeric_limits<long>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::subtract(0, values, 2); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_nullable_long_longarraynullptr_int_math_exception) {

            try {
                long* values = NULL;
                Assert::ExpectException<maths_exception>([values] { maths::subtract(0, values, 0); });
                delete values;
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_special_long_longarray_int_long) {

            try {
                long values[] = { 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(0 == maths::subtract(0L, values, 6));

            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_common_double_doublearray_int_double) {

            try {
                double values[] = { 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(-50.0 == maths::subtract(10.0, values, 6));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(subtract_common_double_doublearay_int_double__1) {

            try {
                double value[] = { 10 };
                Assert::IsTrue(0.0 == maths::subtract(10.00, value, 1));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(subtract_exceptional_double_doublearray_int_math_exception) {

            try {
                double values[] = { -numeric_limits<double>::max(), -numeric_limits<double>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::subtract(0.0, values, 2); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_exceptional_double_doublearay_int_math_exception__1) {

            try {
                double values[] = { numeric_limits<double>::max(), numeric_limits<double>::max() };
                Assert::ExpectException<overflow_exception>([values] { maths::subtract(0.00, values, 2); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_nullable_double_doublearraynullptr_int_math_exception) {

            try {
                double* values = NULL;
                Assert::ExpectException<maths_exception>([values] { maths::subtract(0.00, values, 0); });
                delete values;
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(subtract_special_double_doublearray_int_double) {

            try {
                double values[] = { 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(0 == maths::subtract(0.00, values, 6));

            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(multiply_common_longarray_int_long) {

            try {

                long values[] = { 10, 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(10000000 == maths::multiply(values, 7));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_common_longarray_int_long__1) {

            try {

                long values[] = { 10 };
                Assert::IsTrue(10 == maths::multiply(values, 1));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_exceptional_longarray_int_maths_exception) {

            try {

                long values[] = { numeric_limits<long>::max(), numeric_limits<long>::max() };

                Assert::ExpectException<overflow_exception>([values] { maths::multiply(values, 2); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_exceptional_longarray_int_maths_exception__1) {

            try {

                long values[] = { numeric_limits<long>::max(), numeric_limits<long>::min() };

                Assert::ExpectException<overflow_exception>([values] { maths::multiply(values, 2); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }


        TEST_METHOD(multiply_nullable_longarraynullptr_int_maths_exception) {

            try {

                long* values = nullptr;
                Assert::ExpectException<maths_exception>([values] { maths::multiply(values, 1); });
                delete values;

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_special_longarray_int_long) {

            try {

                long values[] = { 0, 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(0 == maths::multiply(values, 7));

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_empty_longarray_int_maths_exception) {

            try {
                long* values;

                Assert::ExpectException<maths_exception>([values] { maths::multiply(values, 0); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_common_doublearray_int_double) {

            try {

                double values[] = { 10, 10, 10, 10, 10, 10, 10 };
                Assert::IsTrue(10000000.0 == maths::multiply(values, 7));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_common_doublearray_int_double__1) {

            try {

                double values[] = { 10.0 };
                Assert::IsTrue(10 == maths::multiply(values, 1));

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_exceptional_doublearray_int_maths_exception) {

            try {

                double values[] = { numeric_limits<double>::max(), numeric_limits<double>::max() };

                Assert::ExpectException<overflow_exception>([values] { maths::multiply(values, 2); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_exceptional_doublearray_int_maths_exception__1) {

            try {

                double values[] = { numeric_limits<double>::max(), -numeric_limits<double>::max() };

                Assert::ExpectException<overflow_exception>([values] { maths::multiply(values, 2); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }


        TEST_METHOD(multiply_nullable_doublearraynullptr_int_maths_exception) {

            try {

                double* values = nullptr;
                Assert::ExpectException<maths_exception>([values] { maths::multiply(values, 1); });
                delete values;

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_special_doublearray_int_double) {

            try {

                double values[] = { 0, 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(0 == maths::multiply(values, 7));

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(multiply_empty_doublearray_int_maths_exception) {

            try {
                double* values;

                Assert::ExpectException<maths_exception>([values] { maths::multiply(values, 0); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        /*
        *
        Divide_Nullable_Null_MathsException():void
        Divide_Special_DoubleArray_MathsException():void
        */

        TEST_METHOD(divide_common_doublearray_int_maths_exception) {

            try
            {

                double values[] = { 10, 1, 1, 1, 1, 10 };
                Assert::IsTrue(0.1 == maths::divide(10.0, values, 6));
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(divide_common_doublearray_int_double) {

            try
            {
                double value[] = { 10.0 };
                Assert::IsTrue(1.0 == maths::divide(10.0, value, 1));
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(divide_exceptional_doublearray_int_math_exception) {

            try
            {

                double values[] = { numeric_limits<double>::epsilon() };
                Assert::ExpectException<overflow_exception>([values] { maths::divide(numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(divide_nullable_doublearraynullptr_int_math_exception__1) {

            try
            {

                double values[] = { numeric_limits<double>::epsilon() };
                Assert::ExpectException<overflow_exception>([values] { maths::divide(-numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(divide_exceptional_doublearray_double_math_exception__1) {

            try
            {

                double values[] = { numeric_limits<double>::epsilon() };
                Assert::ExpectException<overflow_exception>([values] { maths::divide(-numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(divide_special_doublearray_int_math_exception__1) {

            try {

                double values[] = { 0, 0, 0, 0, 0, 0 };
                Assert::ExpectException<maths_exception>([values] { maths::divide(1, values, 6); });
            }
            catch (exception ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(divide_empty_doublearray_int_maths_exception) {

            try {
                double* values;

                Assert::ExpectException<maths_exception>([values] { maths::divide(100.0, values, 0); });

            }
            catch (exception& ex) {

                Assert::Fail();
            }
        }

        TEST_METHOD(power_of_common_long_longarray_int_long) {

            try {
                long values[] = { 2, 1, 1, 1, 1, 2 };
                Assert::IsTrue(100000000 == maths::power_of(10L, values, 6));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_common_long_longarray_int_long__1) {

            try {
                long values[] = { 2 };
                Assert::IsTrue(100 == maths::power_of(10L, values, 1));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_nullable_long_longarraynullptr_int_maths_exception) {

            try {
                long* values = nullptr;
                Assert::ExpectException<maths_exception>([values] { maths::power_of(10L, values, 1); });
                delete values;
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_long_longArray_int_maths_exception) {

            try {   
                long values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(numeric_limits<long>::max(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_long_longArray_int_maths_exception__1) {

            try {
                long values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(numeric_limits<long>::min(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_special_long_longArray_int_long) {

            try {
                long values[] = { 0, 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(1 == maths::power_of(10L, values, 7));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_common_double_longarray_int_double) {

            try {
                long values[] = { 2, 1, 1, 1, 1, 2 };
                Assert::IsTrue(100000000.0 == maths::power_of(10.0, values, 6));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_common_double_longarray_int_double__1) {

            try {
                long values[] = { 2 };
                Assert::IsTrue(100.0 == maths::power_of(10.0, values, 1));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_nullable_double_longarraynullptr_int_maths_exception) {

            try {
                long* values = nullptr;
                Assert::ExpectException<maths_exception>([values] { maths::power_of(10.0, values, 1); });
                delete values;
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_double_longArray_int_maths_exception) {

            try {
                long values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_double_longArray_int_maths_exception__1) {

            try {
                long values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(-numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_special_double_longArray_int_double) {

            try {
                long values[] = { 0, 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(1.0 == maths::power_of(10L, values, 7));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }


        TEST_METHOD(power_of_common_double_doublearray_int_double) {

            try {
                double values[] = { 2, 1, 1, 1, 1, 2 };
                Assert::IsTrue(100000000.0 == maths::power_of(10.0, values, 6));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_common_double_doublearray_int_double__1) {

            try {
                double values[] = { 2 };
                Assert::IsTrue(100.0 == maths::power_of(10.0, values, 1));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_nullable_double_doublearraynullptr_int_maths_exception) {

            try {
                double* values = nullptr;
                Assert::ExpectException<maths_exception>([values] { maths::power_of(10.0, values, 1); });
                delete values;
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_double_doublearray_int_maths_exception) {

            try {
                double values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_exceptional_double_doublearray_int_maths_exception__1) {

            try {
                double values[] = { 10 };
                Assert::ExpectException<overflow_exception>([values] { maths::power_of(-numeric_limits<double>::max(), values, 1); });
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(power_of_special_double_doublearray_int_double) {

            try {
                double values[] = { 0, 0, 0, 0, 0, 0, 0 };
                Assert::IsTrue(1.0 == maths::power_of(10L, values, 7));
            }
            catch (exception& ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(quadratic_common_double_double_double_double) {

            try {

                double a = 1.0;
                optional<double> b = 1.0;
                optional<double> c = -1.0;
                vector<optional<double>> result = maths::quadratic(a, b, c);

                if (result.size() == 1)
                    Assert::IsTrue(0.6180339887498949 == result[0].value());
                else {
                    Assert::IsTrue(0.6180339887498949 == result[0].value());
                    Assert::IsTrue(-1.618033988749895 == result[1].value());
                }

            }
            catch (exception& ex) {
                Assert::Fail();
            }
        }

        TEST_METHOD(quadratic_special_double_doublenullopt_double_double) {

            try {

                double a = 1.0;
                optional<double> b = nullopt;
                optional<double> c = -4.00;
                vector<optional<double>> result = maths::quadratic(a, b, c);

                Assert::IsTrue(2.0 == result[0].value());
                Assert::IsTrue(-2.0 == result[1].value());

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(quadratic_special_double_double_doublenullopt_double) {

            try {

                double a = 1.0;
                double b = 2.0;
                optional<double> c = nullopt;
                vector<optional<double>> result = maths::quadratic(a, b, c);

                Assert::IsTrue(0.0 == result[0].value());
                Assert::IsTrue(-2.0 == result[1].value());

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(quadratic_special_double_doublenullopt_doublenullopt_double) {

            try {

                double a = 1.0;
                optional<double> b = nullopt;
                optional<double> c = nullopt;
                vector<optional<double>> result = maths::quadratic(a, b, c);

                Assert::IsTrue(0.0 == result[0].value());

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(quadratic_special_double_doublenullopt_doublenullopt_math_exception) {

            try {

                double a = 0;
                optional<double> b = nullopt;
                optional<double> c = nullopt;
                Assert::ExpectException<maths_exception>([a, b, c] { maths::quadratic(a, b, c); });

            }
            catch (exception& ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(quadratic_exceptional_double_double_double_math_exception) {

            try {

                double a = numeric_limits<double>::max();
                double b = numeric_limits<double>::max();
                double c = -numeric_limits<double>::max();

                Assert::ExpectException<overflow_exception>([a, b, c] { maths::quadratic(a, b, c); });

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(quadratic_exceptional_double_double_double_math_exception__1) {

            try {

                double a = numeric_limits<double>::max();
                double b = numeric_limits<double>::max();
                double c = numeric_limits<double>::max();

                Assert::ExpectException<overflow_exception>([a, b, c] { maths::quadratic(a, b, c); });

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_common_double_double_double) {

            try {

                double nearLine = 3;
                double farLine = 1;

                Assert::IsTrue(std::pow(10, 0.5) == maths::hypotenuse(nearLine, farLine));

            }
            catch (exception& ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_special_double_double_maths_exception) {

            try {

                double nearLine = 0;
                double farLine = 1;

                Assert::ExpectException<maths_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_special_double_double_maths_exception__1) {

            try {

                double nearLine = 1;
                double farLine = 0;

                Assert::ExpectException<maths_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_special_double_double_maths_exception__2) {

            try {

                double nearLine = -1;
                double farLine = 100;

                Assert::ExpectException<maths_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_special_double_double_maths_exception__3) {

            try {

                double nearLine = 100;
                double farLine = -1;

                Assert::ExpectException<maths_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_exceptional_double_double_maths_exception) {

            try {

                double nearLine = numeric_limits<double>::max();
                double farLine = numeric_limits<double>::max();

                Assert::ExpectException<overflow_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

        TEST_METHOD(hypothenuse_exceptional_double_double_maths_exception__1) {

            try {

                double nearLine = -numeric_limits<double>::max();
                double farLine = numeric_limits<double>::max();

                Assert::ExpectException<maths_exception>([nearLine, farLine] { maths::hypotenuse(nearLine, farLine); });

            }
            catch (exception ex) {

                Assert::Fail();

            }
        }

    };

}
