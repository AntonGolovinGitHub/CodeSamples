package tech.getrealgood.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

/**
 * Set of utility methods for numerical computation.
 */
public final class Maths {

    /**
     * Mathematical E constant.
     */
    public final double EConst = 2.7182818284590451D;

    /**
     * Mathematical PI constant.
     */
    public final double PIConst = 3.1415926535897931D;

    // multiplies 2 long integers with overflow checks, throws MathsException
    private static long multiplyAndCheckOverflow(long a, long b) throws MathsException {
        if (a == 0 || b == 0)
            return 0;

        long result = a * b;

        if (a == result / b)
            return result;
        else
            throw new MathsException("Overflow");
    }

    // adds 2 long integers with overflow checks, throws MathsException
    private static long addAndCheckOverflow(long a, long b) throws MathsException {
        if (a == 0 || b == 0)
            return a + b;

        long result;

        if (a < 0) {
            if (b < 0) {
                // check for negative overflow
                if (Long.MIN_VALUE - b <= a) {
                    result = a + b;
                } else {
                    throw new MathsException("Negative overflow");
                }
            } else {
                result = a + b;
            }
        } else {

            if (b < 0) {
                result = a + b;
            } else {

                // check for positive overflow
                if (Long.MAX_VALUE - b >= a) {
                    result = a + b;
                } else {
                    throw new MathsException("Positive overflow");
                }
            }
        }

        return result;
    }

    // subtracts 2 long integers with overflow checks, throws MathsException
    private static long subtractAndCheckOverflow(long a, long b) throws MathsException {

        if (a == 0 || b == 0)
            return a - b;

        if (b < 0) {
            return addAndCheckOverflow(a, b);
        } else {
            long b1 = -b;
            return addAndCheckOverflow(a, b1);
        }
    }

    // multiplies 2 double floats with overflow checks, throws MathsException
    private static double multiplyAndCheckOverflow(double a, double b) throws MathsException {

        if (a == 0D || b == 0D)
            return 0D;

        double result = a * b;
        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");

        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    // divides 2 long integers with overflow checks, throws MathsException
    private static long divideAndCheckOverflow(long a, long b) throws MathsException {
        if (a == 0L)
            return 0L;
        if (b == 0L)
            throw new MathsException("Division by zero");

        long result = a / b;

        if (result == 0 || a == result * b)
            return result;
        else
            throw new MathsException("Overflow");
    }

    // divides 2 double floats with overflow checks, throws MathsException
    private static double divideAndCheckOverflow(double a, double b) throws MathsException {

        if (a == 0D)
            return 0D;
        if (b == 0D)
            throw new MathsException("Division by zero");

        double result = a / b;
        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");

        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    // adds 2 double floats with overflow checks, throws MathsException
    private static double addAndCheckOverflow(double a, double b) throws MathsException {

        if (a == 0D || b == 0D)
            return a + b;

        double result = a + b;
        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");

        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    // subtracts 2 double floats with overflow checks, throws MathsException
    private static double subtractAndCheckOverflow(double a, double b) throws MathsException {

        if (a == 0D || b == 0D)
            return a - b;

        double result = a - b;
        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");

        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    /**
     * Sums a variable-length argument list with overflow checks.
     *
     * @param vars The variable-length long-integer argument list.
     * @return The long-integer sum of long integers.
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static long sum(long... vars) throws MathsException {
        if (Objects.isNull(vars))
            throw new MathsException("Null value passed in");

        if (vars.length == 0)
            return 0;

        long result = 0;

        try {

            for (var v : vars) {

                result = addAndCheckOverflow(result, v);
            }

        } catch (Exception soEx) {
            throw new MathsException(soEx.getMessage());
        }

        return result;
    }

    /**
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static double sum(double... vars) throws MathsException {
        if (Objects.isNull(vars))
            throw new MathsException("Null value passed in");

        if (vars.length == 0)
            return 0;

        double result = 0;

        try {

            for (var v : vars) {
                result = addAndCheckOverflow(result, v);
            }
        } catch (Exception soEx) {
            throw new MathsException(soEx.getMessage());
        }

        return result;
    }

    /**
     * @param value
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static long subtract(long value, long... vars) throws MathsException {

        if (Objects.isNull(vars))
            throw new MathsException("Null vars value passed in");

        if (vars.length == 0)
            return value;

        long result = value;

        try {

            for (var v : vars) {
                result = subtractAndCheckOverflow(result, v);
            }
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param value
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static double subtract(double value, double... vars) throws MathsException {
        if (Objects.isNull(vars))
            throw new MathsException("Null vars value passed in");

        if (vars.length == 0)
            return value;

        double result = value;

        try {
            for (var v : vars) {
                result = subtractAndCheckOverflow(result, v);
            }
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static long multiply(long... vars) throws MathsException {
        if (Objects.isNull(vars))
            throw new MathsException("Null value passed in");

        if (vars.length == 0)
            throw new MathsException("Empty value passed in");

        long result = 1;

        try {
            for (var v : vars) {
                result = multiplyAndCheckOverflow(result, v);
            }
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static double multiply(double... vars) throws MathsException {
        if (Objects.isNull(vars))
            throw new MathsException("Null value passed in");

        if (vars.length == 0)
            throw new MathsException("Null value passed in");

        double result = 1;

        try {

            for (var v : vars) {
                result = multiplyAndCheckOverflow(result, v);
            }
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param value
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static long divide(long value, long... vars) throws MathsException {
        if (Objects.isNull(vars))
            return value;

        if (vars.length == 0)
            return value;

        long result = value;

        try {

            for (var v : vars) {
                if (v == 0L)
                    throw new MathsException("Division by zero");
                result = divideAndCheckOverflow(result, v);
            }

        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param value
     * @param vars
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    public static double divide(double value, double... vars) throws MathsException {

        if (Objects.isNull(vars))
            throw new MathsException("Null vars value passed in");

        if (vars.length == 0)
            return value;

        double result = value;

        try {

            for (var v : vars) {
                if (v == 0d)
                    throw new MathsException("Division by zero");
                result = divideAndCheckOverflow(result, v);
            }

        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param value
     * @param toThePowersOf
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    // Equivalent to: value^toThePowersOf[0] * value^toThePowersOf[1] ...
    public static long powerOf(long value, long... toThePowersOf) throws MathsException {

        if (Objects.isNull(toThePowersOf))
            throw new MathsException("Null value passed in");

        if (toThePowersOf.length == 0)
            throw new MathsException("Empty value passed in");

        long result = value;

        try {

            long totalPowerOf = sum(toThePowersOf);

            if (Objects.isNull(totalPowerOf))
                throw new MathsException("Null value for sum of powers");

            if (totalPowerOf == 0)
                return 1;

            if (totalPowerOf == 1)
                return value;

            int powerOf = 1;

            while (powerOf++ < totalPowerOf)
                result = multiplyAndCheckOverflow(result, value);

        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");
        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    /**
     * @param value
     * @param toThePowersOf
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    // Equivalent to: value^toThePowersOf[0] * value^toThePowersOf[1] ...
    public static double powerOf(double value, long... toThePowersOf) throws MathsException {
        if (Objects.isNull(toThePowersOf))
            throw new MathsException("Null value passed in");

        if (toThePowersOf.length == 0)
            throw new MathsException("Empty value passed in");

        double result = value;

        try {

            long totalPowerOf = sum(toThePowersOf);

            if (Objects.isNull(totalPowerOf))
                throw new MathsException("Null value for sum of powers");

            if (totalPowerOf == 0)
                return 1;

            if (totalPowerOf == 1)
                return value;

            result = Math.pow(result, totalPowerOf);

        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");
        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    /**
     * @param value
     * @param toThePowersOf
     * @return
     * @throws MathsException Thrown on any exceptional condition; the message states the reason.
     */
    // Equivalent to: value^toThePowersOf[0] * value^toThePowersOf[1] ...
    public static double powerOf(double value, double... toThePowersOf) throws MathsException {
        if (Objects.isNull(toThePowersOf))
            throw new MathsException("Null value passed in");

        if (toThePowersOf.length == 0)
            throw new MathsException("Empty value passed in");

        double result = value;

        try {

            double totalPowerOf = sum(toThePowersOf);

            if (Objects.isNull(totalPowerOf))
                throw new MathsException("Null value passed in");

            if (totalPowerOf == 0)
                return 1;

            if (totalPowerOf == 1)
                return value;

            result = Math.pow(result, totalPowerOf);

        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        if (result == Double.POSITIVE_INFINITY)
            throw new MathsException("Positive overflow");
        if (result == Double.NEGATIVE_INFINITY)
            throw new MathsException("Negative overflow");

        return result;
    }

    /**
     * @param a
     * @param b
     * @param c
     * @return
     * @throws MathsException
     */
    public static List<Double> quadratic(double a, Double b, Double c) throws MathsException {

        var result = new ArrayList<Double>(2);

        try {
            // a is never null or zero
            if (a == 0.00D)
                throw new MathsException("Coefficient a is zero");

            b = Objects.isNull(b) ? 0.00D : b;
            c = Objects.isNull(c) ? 0.00D : c;

            if (b == 0.00D && c == 0.00D || ((b == null) && (c == null))) {
                // only one solution
                result.add(0, 0.00D);
                result.add(1, null);
                return result;
            }

            var partOne = -b;
            var minus =
                    subtractAndCheckOverflow(multiplyAndCheckOverflow(b, b),
                            multiplyAndCheckOverflow(4.00D, multiplyAndCheckOverflow(a, c)));
            if (minus < 0)
                throw new MathsException("No real-number solution to the quadratic equation");
            var partTwo = Math.sqrt(minus);
            var partThree = multiplyAndCheckOverflow(2.00D, a);

            result.add(0, (divideAndCheckOverflow(addAndCheckOverflow(partOne, partTwo), partThree)));
            result.add(1, (divideAndCheckOverflow(subtractAndCheckOverflow(partOne, partTwo), partThree)));
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

    /**
     * @param nearLine
     * @param farLine
     * @return
     * @throws MathsException
     */
    public static double hypotenuse(double nearLine, double farLine) throws MathsException {
        if (nearLine <= 0)
            throw new MathsException("Invalid parameter value for nearLine (<=0)");

        if (farLine <= 0)
            throw new MathsException("Invalid parameter value for farLine (<=0)");

        double result;

        try {

            result = Math.sqrt(
                    addAndCheckOverflow(multiplyAndCheckOverflow(
                            nearLine, nearLine), multiplyAndCheckOverflow(farLine, farLine)));
        } catch (Exception ex) {
            throw new MathsException(ex.getMessage());
        }

        return result;
    }

}