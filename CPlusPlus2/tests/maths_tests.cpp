#include "gtest/gtest.h"
#include "../headers/maths.h"
#include <math.h>

using namespace std;
using namespace getrealgoodutils;

class maths_tests : public ::testing::Test {

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

TEST_F(maths_tests, sum_common_longarray_int_long){

    try
    {
        long values[] = {10, 10, 10, 10, 10, 10, 10};
        ASSERT_EQ(70, maths::sum(values, sizeof(values) / sizeof(values[0])));

    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, sum_common_longarray_int_long__1) {

    try {
        long values[] = {10};
        ASSERT_EQ(10, maths::sum(values, sizeof(values) / sizeof(values[0])));

    }
    catch (exception &ex) {
        FAIL();
    }
}


TEST_F(maths_tests, sum_exceptional_longarray_int_maths_exception) {

        try
        {
            long values[] = {numeric_limits<long>::max(), numeric_limits<long>::max()};
            ASSERT_THROW(maths::sum(values, 2), overflow_exception);
        }
        catch (exception &ex)
        {
            FAIL();
        }
}

TEST_F(maths_tests, sum_exceptional_longarray_int_maths_exception__1) {

    try
    {
        long values[] = {numeric_limits<long>::min(), numeric_limits<long>::min()};
        ASSERT_THROW(maths::sum(values, 2), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_special_longarray_int_long) {

    try
    {
        long values[] = {0,0,0,0,0,0,0};
        ASSERT_EQ(0, maths::sum(values, 7));
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_nullable_longnullptr_int_maths_exception) {

    try
    {
        long *values = NULL;
        ASSERT_THROW(maths::sum(values, 0), maths_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_common_doublearray_int_double){

    try
    {
        double values[] = {10, 10, 10, 10, 10, 10, 10};
        ASSERT_EQ(70.0, maths::sum(values, sizeof(values) / sizeof(values[0])));
    }
    catch (maths_exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, sum_common_doublearray_int_double__1) {

    try {
        double values[] = {10};
        ASSERT_EQ(10.0, maths::sum(values, sizeof(values) / sizeof(values[0])));
    }
    catch (exception &ex) {
        FAIL();
    }
}


TEST_F(maths_tests, sum_exceptional_doublearray_int_maths_exception) {

    try
    {
        double values[] = {numeric_limits<double>::max(), numeric_limits<double>::max()};
        ASSERT_THROW(maths::sum(values, 2), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_exceptional_doublearray_int_maths_exception__1) {

    try
    {
        double values[] = {-numeric_limits<double>::max(), -numeric_limits<double>::max()};
        ASSERT_THROW(maths::sum(values, 2), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_special_doublearray_int_double) {

    try
    {
        long values[] = {0,0,0,0,0,0,0};
        ASSERT_EQ(0.0, maths::sum(values, 7));
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, sum_nullable_doublenullptr_int_maths_exception) {

    try
    {
        double *values = NULL;
        ASSERT_THROW(maths::sum(values, 0), maths_exception);
        delete values;
    }
    catch (exception &ex)
    {
        FAIL();
    }
}

TEST_F(maths_tests, subtract_common_long_longarray_int_long) {

    try {
        long values[] = {10, 10, 10, 10, 10, 10};
        ASSERT_EQ( -50, maths::subtract(10, values, 6));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, subtract_common_long_longaray_int_long__1) {

    try {
            long value[] = {10};
            ASSERT_EQ(0, maths::subtract(10, value, 1));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, subtract_exceptional_long_longaray_int_math_exception) {

    try {
        long values[] = {numeric_limits<long>::min(), numeric_limits<long>::min()};
        ASSERT_THROW(maths::subtract(0, values, 2), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_exceptional_long_longarray_int_math_exception__1) {

    try {
        long values[] = {numeric_limits<long>::max(), numeric_limits<long>::max()};
        ASSERT_THROW(maths::subtract(0, values, 2), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_nullable_long_longarraynullptr_int_math_exception) {

    try {
        long *values = NULL;
        ASSERT_THROW(maths::subtract(0, values, 0), maths_exception);
        delete values;
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_special_long_longarray_int_long) {

    try {
        long values[] = {0, 0, 0, 0, 0, 0};
        ASSERT_EQ(maths::subtract(0L, values, 6), 0);

    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_common_double_doublearray_int_double) {

    try {
        double values[] = {10, 10, 10, 10, 10, 10};
        ASSERT_EQ( -50.0, maths::subtract(10.0, values, 6));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, subtract_common_double_doublearay_int_double__1) {

    try {
        double value[] = {10};
        ASSERT_EQ(0.0, maths::subtract(10.00, value, 1));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, subtract_exceptional_double_doublearray_int_math_exception) {

    try {
        double values[] = {-numeric_limits<double>::max(), -numeric_limits<double>::max()};
        ASSERT_THROW(maths::subtract(0.0, values, 2), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_exceptional_double_doublearay_int_math_exception__1) {

    try {
        double values[] = {numeric_limits<double>::max(), numeric_limits<double>::max()};
        ASSERT_THROW(maths::subtract(0.00, values, 2), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_nullable_double_doublearraynullptr_int_math_exception) {

    try {
        double *values = NULL;
        ASSERT_THROW(maths::subtract(0.00, values, 0), maths_exception);
        delete values;
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, subtract_special_double_doublearray_int_double) {

    try {
        double values[] = {0, 0, 0, 0, 0, 0};
        ASSERT_EQ(maths::subtract(0.00, values, 6), 0);

    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, multiply_common_longarray_int_long) {

        try {

            long values[] = {10, 10, 10, 10, 10, 10, 10};
            ASSERT_EQ(10000000, maths::multiply(values, 7));

        } catch (exception &ex) {
            FAIL();
        }
}

TEST_F(maths_tests, multiply_common_longarray_int_long__1) {

    try {

        long values[] = {10 };
        ASSERT_EQ(10, maths::multiply(values, 1));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, multiply_exceptional_longarray_int_maths_exception) {

    try {

        long values[] = {numeric_limits<long>::max(), numeric_limits<long>::max()};

        ASSERT_THROW(maths::multiply(values, 2), overflow_exception);

    } catch (exception &ex) {

    FAIL();
    }
}

TEST_F(maths_tests, multiply_exceptional_longarray_int_maths_exception__1) {

    try {

        long values[] = {numeric_limits<long>::max(), numeric_limits<long>::min()};

        ASSERT_THROW(maths::multiply(values, 2), overflow_exception);

    } catch (exception &ex) {

        FAIL();
    }
}


TEST_F(maths_tests, multiply_nullable_longarraynullptr_int_maths_exception) {

    try {

        long *values = nullptr;
        ASSERT_THROW(maths::multiply(values, 1), maths_exception);
        delete values;

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_special_longarray_int_long) {

    try {

        long values[] = {0, 0, 0, 0, 0, 0, 0};
        ASSERT_EQ(0, maths::multiply(values, 7));

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_empty_longarray_int_maths_exception) {

    try {
        long values[] = {};

        ASSERT_THROW(maths::multiply(values, 0), maths_exception);

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_common_doublearray_int_double) {

    try {

        double values[] = {10, 10, 10, 10, 10, 10, 10};
        ASSERT_EQ(10000000.0, maths::multiply(values, 7));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, multiply_common_doublearray_int_double__1) {

    try {

        double values[] = {10.0 };
        ASSERT_EQ(10, maths::multiply(values, 1));

    } catch (exception &ex) {
        FAIL();
    }
}

TEST_F(maths_tests, multiply_exceptional_doublearray_int_maths_exception) {

    try {

        double values[] = {numeric_limits<double>::max(), numeric_limits<double>::max()};

        ASSERT_THROW(maths::multiply(values, 2), overflow_exception);

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_exceptional_doublearray_int_maths_exception__1) {

    try {

        double values[] = {numeric_limits<double>::max(), -numeric_limits<double>::max()};

        ASSERT_THROW(maths::multiply(values, 2), overflow_exception);

    } catch (exception &ex) {

        FAIL();
    }
}


TEST_F(maths_tests, multiply_nullable_doublearraynullptr_int_maths_exception) {

    try {

        double *values = nullptr;
        ASSERT_THROW(maths::multiply(values, 1), maths_exception);
        delete values;

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_special_doublearray_int_double) {

    try {

        double values[] = {0, 0, 0, 0, 0, 0, 0};
        ASSERT_EQ(0, maths::multiply(values, 7));

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, multiply_empty_doublearray_int_maths_exception) {

    try {
        double values[] = {};

        ASSERT_THROW(maths::multiply(values, 0), maths_exception);

    } catch (exception &ex) {

        FAIL();
    }
}

/*
*
Divide_Nullable_Null_MathsException():void
Divide_Special_DoubleArray_MathsException():void
*/

TEST_F(maths_tests, divide_common_doublearray_int_maths_exception) {

    try
    {

        double values[] = {10, 1, 1, 1, 1, 10};
        ASSERT_EQ(0.1, maths::divide(10.0, values, 6));
    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, divide_common_doublearray_int_double) {

    try
    {
        double value[] = {10.0};
        ASSERT_EQ(1.0, maths::divide(10.0, value, 1));
    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, divide_exceptional_doublearray_int_math_exception) {

    try
    {

        double values[] =  {numeric_limits<double>::epsilon()};
        ASSERT_THROW(maths::divide(numeric_limits<double>::max(), values, 1), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, divide_nullable_doublearraynullptr_int_math_exception__1) {

    try
    {

        double values[] =  {numeric_limits<double>::epsilon()};
        ASSERT_THROW(maths::divide(-numeric_limits<double>::max(), values, 1), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, divide_exceptional_doublearray_double_math_exception__1) {

    try
    {

        double values[] =  {numeric_limits<double>::epsilon()};
        ASSERT_THROW(maths::divide(-numeric_limits<double>::max(), values, 1), overflow_exception);
    }
    catch (exception &ex)
    {
        FAIL();
    }

}

TEST_F(maths_tests, divide_special_doublearray_int_math_exception__1) {

    try {

        double values[] = {0, 0, 0, 0, 0, 0 };
        ASSERT_THROW(maths::divide(1, values, 6), maths_exception);
    }
    catch (exception ex) {
        FAIL();
    }
}

TEST_F(maths_tests, divide_empty_doublearray_int_maths_exception) {

    try {
        double values[] = {};

        ASSERT_THROW(maths::divide(100.0, values, 0), maths_exception);

    } catch (exception &ex) {

        FAIL();
    }
}

TEST_F(maths_tests, power_of_common_long_longarray_int_long) {

    try {
            long values[] = {2, 1, 1, 1, 1, 2};
            ASSERT_EQ(100000000, maths::power_of(10L, values, 6));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_common_long_longarray_int_long__1) {

    try {
        long values[] = {2};
        ASSERT_EQ(100, maths::power_of(10L, values, 1));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_nullable_long_longarraynullptr_int_maths_exception) {

    try {
        long *values = nullptr;
        ASSERT_THROW(maths::power_of(10L, values, 1), maths_exception);
        delete values;
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_long_longArray_int_maths_exception) {

    try {
        long values[] = {10};
        ASSERT_THROW(maths::power_of(numeric_limits<long>::max(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_long_longArray_int_maths_exception__1) {

    try {
        long values[] = {10};
        ASSERT_THROW(maths::power_of(numeric_limits<long>::min(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_special_long_longArray_int_long) {

    try {
        long values[] = {0, 0, 0, 0, 0, 0, 0};
        ASSERT_EQ(maths::power_of(10L, values, 7), 1);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_common_double_longarray_int_double) {

    try {
        long values[] = {2, 1, 1, 1, 1, 2};
        ASSERT_EQ(100000000.0, maths::power_of(10.0, values, 6));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_common_double_longarray_int_double__1) {

    try {
        long values[] = {2};
        ASSERT_EQ(100.0, maths::power_of(10.0, values, 1));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_nullable_double_longarraynullptr_int_maths_exception) {

    try {
        long *values = nullptr;
        ASSERT_THROW(maths::power_of(10.0, values, 1), maths_exception);
        delete values;
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_double_longArray_int_maths_exception) {

    try {
        long values[] = {10};
        ASSERT_THROW(maths::power_of(numeric_limits<double>::max(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_double_longArray_int_maths_exception__1) {

    try {
        long values[] = {10};
        ASSERT_THROW(maths::power_of(-numeric_limits<double>::max(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_special_double_longArray_int_double) {

    try {
        long values[] = {0, 0, 0, 0, 0, 0, 0};
        ASSERT_EQ(1.0, maths::power_of(10L, values, 7));
    } catch (exception &ex) {
        FAIL();
    }

}


TEST_F(maths_tests, power_of_common_double_doublearray_int_double) {

    try {
        double values[] = {2, 1, 1, 1, 1, 2};
        ASSERT_EQ(100000000.0, maths::power_of(10.0, values, 6));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_common_double_doublearray_int_double__1) {

    try {
        double values[] = {2};
        ASSERT_EQ(100.0, maths::power_of(10.0, values, 1));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_nullable_double_doublearraynullptr_int_maths_exception) {

    try {
        double *values = nullptr;
        ASSERT_THROW(maths::power_of(10.0, values, 1), maths_exception);
        delete values;
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_double_doublearray_int_maths_exception) {

    try {
        double values[] = {10};
        ASSERT_THROW(maths::power_of(numeric_limits<double>::max(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_exceptional_double_doublearray_int_maths_exception__1) {

    try {
        double values[] = {10};
        ASSERT_THROW(maths::power_of(-numeric_limits<double>::max(), values, 1), overflow_exception);
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, power_of_special_double_doublearray_int_double) {

    try {
        double values[] = {0, 0, 0, 0, 0, 0, 0};
        ASSERT_EQ(1.0, maths::power_of(10L, values, 7));
    } catch (exception &ex) {
        FAIL();
    }

}

TEST_F(maths_tests, quadratic_common_double_double_double_double) {

    try {

        double a = 1.0;
        optional<double> b = 1.0;
        optional<double> c = -1.0;
        vector<optional<double>> result = maths::quadratic(a, b, c);

        if (result.size() == 1)
            ASSERT_EQ(0.6180339887498949, result[0].value());
        else {
            ASSERT_EQ(0.6180339887498949, result[0].value());
            ASSERT_EQ(-1.618033988749895, result[1].value());
        }

    } catch (exception &ex) {
        FAIL();
    }
}

    TEST_F(maths_tests, quadratic_special_double_doublenullopt_double_double) {

    try {

        double a = 1.0;
        optional<double> b = nullopt;
        optional<double> c = -4.00;
        vector<optional<double>> result = maths::quadratic(a, b, c);

        ASSERT_EQ(2.0, result[0].value());
        ASSERT_EQ(-2.0, result[1].value());

    } catch (exception &ex) {

        FAIL();

    }
}

    TEST_F(maths_tests, quadratic_special_double_double_doublenullopt_double) {

        try {

            double a = 1.0;
            double b = 2.0;
            optional<double> c = nullopt;
            vector<optional<double>> result = maths::quadratic(a, b, c);

            ASSERT_EQ(0.0, result[0].value());
            ASSERT_EQ(-2.0, result[1].value());

        } catch (exception &ex) {

            FAIL();

        }
    }

TEST_F(maths_tests, quadratic_special_double_doublenullopt_doublenullopt_double) {

    try {

        double a = 1.0;
        optional<double> b = nullopt;
        optional<double> c = nullopt;
        vector<optional<double>> result = maths::quadratic(a, b, c);

        ASSERT_EQ(0.0, result[0].value());

    } catch (exception &ex) {

        FAIL();

    }
}

TEST_F(maths_tests, quadratic_special_double_doublenullopt_doublenullopt_math_exception) {

    try {

        double a = 0;
        optional<double> b = nullopt;
        optional<double> c = nullopt;
        ASSERT_THROW(maths::quadratic(a, b, c), maths_exception);

    } catch (exception &ex) {

        FAIL();

    }

}

TEST_F(maths_tests, quadratic_exceptional_double_double_double_math_exception) {

    try {

        double a = numeric_limits<double>::max();
        double b = numeric_limits<double>::max();
        double c = -numeric_limits<double>::max();

        ASSERT_THROW(maths::quadratic(a, b, c), overflow_exception);

    } catch (exception &ex) {

        FAIL();

    }
}

TEST_F(maths_tests, quadratic_exceptional_double_double_double_math_exception__1) {

    try {

        double a = numeric_limits<double>::max();
        double b = numeric_limits<double>::max();
        double c = numeric_limits<double>::max();

        ASSERT_THROW(maths::quadratic(a, b, c), overflow_exception);

    } catch (exception &ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_common_double_double_double) {

    try {

        double nearLine = 3;
        double farLine = 1;

        ASSERT_EQ(std::pow(10, 0.5), maths::hypotenuse(nearLine, farLine));

    } catch (exception &ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_special_double_double_maths_exception) {

    try {

        double nearLine = 0;
        double farLine = 1;

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), maths_exception);

    } catch (exception ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_special_double_double_maths_exception__1) {

    try {

        double nearLine = 1;
        double farLine = 0;

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), maths_exception);

    } catch (exception ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_special_double_double_maths_exception__2) {

    try {

        double nearLine = -1;
        double farLine = 100;

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), maths_exception);

    } catch (exception ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_special_double_double_maths_exception__3) {

    try {

        double nearLine = 100;
        double farLine = -1;

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), maths_exception);

    } catch (exception ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_exceptional_double_double_maths_exception) {

    try {

        double nearLine = numeric_limits<double>::max();
        double farLine = numeric_limits<double>::max();

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), overflow_exception);

    } catch (exception ex) {

        FAIL();

    }
}

TEST_F(maths_tests, hypothenuse_exceptional_double_double_maths_exception__1) {

    try {

        double nearLine = -numeric_limits<double>::max();
        double farLine = numeric_limits<double>::max();

        ASSERT_THROW(maths::hypotenuse(nearLine, farLine), maths_exception);

    } catch (exception ex) {

        FAIL();

    }
}



