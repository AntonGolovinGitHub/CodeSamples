using System;
using System.Collections.Generic;

namespace GetRealGood.Utils
{
    /// <summary>
    ///     MathsException is thrown during any exceptional condition for all static methods of the utility Maths class.
    /// </summary>
    public static class Maths
    {
        /// <summary>
        ///     The mathematical E constant.
        /// </summary>
        public const double EConst = 2.7182818284590451;

        /// <summary>
        ///     The mathematical PI constant.
        /// </summary>
        public const double PiConst = 3.1415926535897931;

        /// <summary>
        ///     Sums a series of long integers.
        /// </summary>
        /// <param name="vars">Zero or more long integers to sum.</param>
        /// <returns>The sum of the long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static long Sum(params long[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                return 0;

            long result = 0;

            try
            {
                checked
                {
                    foreach (var v in vars) result += v;
                }
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            return result;
        }

        /// <summary>
        ///     Sums a series of double floats.
        /// </summary>
        /// <param name="vars">Zero or more double floats to sum.</param>
        /// <returns>The sum of the double floats.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double Sum(params double[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                return 0;

            double result = 0;

            try
            {
                foreach (var v in vars) result += v;
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        ///     Subtracts a series of long integers from a long integer.
        /// </summary>
        /// <param name="value">The long integer to subtract from.</param>
        /// <param name="vars">Zero or more long integers to subtract.</param>
        /// <returns>The subtraction of the long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static long Subtract(long value, params long[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null vars parameter passed in");

            if (vars.Length == 0)
                return value;

            var result = value;

            try
            {
                checked
                {
                    foreach (var v in vars) result -= v;
                }
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            return result;
        }

        /// <summary>
        ///     Subtracts a series of double floats from a double float.
        /// </summary>
        /// <param name="value">The double float to subtract from.</param>
        /// <param name="vars">Zero or more double floats to subtract.</param>
        /// <returns>The subtraction of the double floats.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double Subtract(double value, params double[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null vars parameter passed in");

            if (vars.Length == 0)
                return value;

            var result = value;

            try
            {
                foreach (var v in vars) result -= v;
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        ///     Multiplies a series of long integers.
        /// </summary>
        /// <param name="vars">Zero or more long integers to multiply.</param>
        /// <returns>The product of the long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static long Multiply(params long[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                throw new MathsException("Empty value passed in");

            long result = 1;

            try
            {
                checked
                {
                    foreach (var v in vars) result *= v;
                }
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            return result;
        }

        /// <summary>
        ///     Multiplies a series of double floats.
        /// </summary>
        /// <param name="vars">Zero or more double floats to multiply.</param>
        /// <returns>The product of the double floats.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double Multiply(params double[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                throw new MathsException("Empty value passed in");

            double result = 1;

            try
            {
                foreach (var v in vars) result *= v;
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        ///     Divides a long integer by a series of long integers.
        /// </summary>
        /// <param name="value">The long integer to divide.</param>
        /// <param name="vars">Zero or more long integers to divide by.</param>
        /// <returns>The division of the long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static long Divide(long value, params long[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                return value;

            var result = value;

            try
            {
                foreach (var v in vars)
                {
                    if (v == 0L)
                        throw new DivideByZeroException();
                    result /= v;
                }
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (DivideByZeroException ex)
            {
                throw new MathsException(ex.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            return result;
        }

        /// <summary>
        ///     Divides a double float by a series of double floats.
        /// </summary>
        /// <param name="value">The double float to divide.</param>
        /// <param name="vars">Zero or more double floats to divide by.</param>
        /// <returns>The division of the double floats.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double Divide(double value, params double[] vars)
        {
            if (Objects.IsNull(vars))
                throw new MathsException("Null value passed in");

            if (vars.Length == 0)
                return value;

            var result = value;

            try
            {
                foreach (var v in vars)
                {
                    if (v == 0.00D)
                        throw new DivideByZeroException();
                    result /= v;
                }
            }
            catch (OverflowException soEx)
            {
                throw new MathsException(soEx.Message);
            }
            catch (DivideByZeroException ex)
            {
                throw new MathsException(ex.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        ///     Multiplies a long integer by a sum of long integers.
        /// </summary>
        /// <param name="value">The long integer to put to the power of.</param>
        /// <param name="vars">The sum of long integers of the power of.</param>
        /// <returns>The power of long integer to the sum of long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static long PowerOf(long value, params long[] toThePowersOf)
        {
            if (Objects.IsNull(toThePowersOf))
                throw new MathsException("Null value passed in");

            if (toThePowersOf.Length == 0)
                throw new MathsException("Empty value passed in");

            var result = value;

            try
            {
                checked
                {
                    long? totalPowerOf = Sum(toThePowersOf);

                    if (Objects.IsNull(totalPowerOf))
                        throw new Exception();

                    if (totalPowerOf == 0)
                        return 1;

                    if (totalPowerOf == 1)
                        return value;

                    var powerOf = 1;

                    while (powerOf++ < totalPowerOf.Value)
                        result *= value;
                }
            }
            catch (OverflowException oEx)
            {
                throw new MathsException(oEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        ///     Multiplies a double float by a sum of long integers.
        /// </summary>
        /// <param name="value">The double float to put to the power of.</param>
        /// <param name="vars">The sum of long integers of the power of.</param>
        /// <returns>The power of double float to the sum of long integers.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double PowerOf(double value, params long[] toThePowersOf)
        {
            if (Objects.IsNull(toThePowersOf))
                throw new MathsException("Null value passed in");

            if (toThePowersOf.Length == 0)
                throw new MathsException("Empty value passed in");

            double result;

            try
            {
                checked
                {
                    long? totalPowerOf = Sum(toThePowersOf);

                    if (Objects.IsNull(totalPowerOf))
                        throw new Exception();

                    switch (totalPowerOf)
                    {
                        case 0:
                            return 1;
                        case 1:
                            return value;
                        default:
                            result = Math.Pow(value, totalPowerOf.Value);
                            break;
                    }
                }
            }
            catch (OverflowException oEx)
            {
                throw new MathsException(oEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");


            return result;
        }

        /// <summary>
        ///     Multiplies a double float by a sum of double floats.
        /// </summary>
        /// <param name="value">The double float to put to the power of.</param>
        /// <param name="vars">The sum of double floats of the power of.</param>
        /// <returns>The power of double float to the sum of double floats.</returns>
        /// <exception cref="GetRealGood.Utils.MathsException">
        ///     You should catch this exception, it denotes any exceptional
        ///     condition within the method.
        /// </exception>
        public static double PowerOf(double value, params double[] toThePowersOf)
        {
            if (Objects.IsNull(toThePowersOf))
                throw new MathsException("Null value passed in");

            if (toThePowersOf.Length == 0)
                throw new MathsException("Empty value passed in");

            var result = value;

            try
            {
                checked
                {
                    double? totalPowerOf = Sum(toThePowersOf);

                    if (Objects.IsNull(totalPowerOf))
                        throw new Exception();

                    if (totalPowerOf == 0)
                        return 1;

                    if (totalPowerOf == 1)
                        return value;

                    result = Math.Pow(value, totalPowerOf.Value);
                }
            }
            catch (OverflowException oEx)
            {
                throw new MathsException(oEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            if (double.IsPositiveInfinity(result))
                throw new MathsException("Positive overflow");
            if (double.IsNegativeInfinity(result))
                throw new MathsException("Negative overflow");

            return result;
        }

        /// <summary>
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="c"></param>
        /// <returns></returns>
        /// /// <exception cref="MathsException"></exception>
        public static IList<double?> Quadratic(double a, double? b, double? c)
        {
            var result = new double?[2];

            try
            {
                // a is never null or zero
                if (a == 0.00D)
                    throw new MathsException("Coefficient a is zero");

                b = Objects.IsNull(b) ? 0.00D : b;
                c = Objects.IsNull(c) ? 0.00D : c;

                if (b == 0.00D && c == 0.00D)
                    // only one solution
                    return new List<double?> { 0.00D, null };

                checked
                {
                    var partOne = -b;
                    
                    if(double.IsPositiveInfinity(partOne.Value))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(partOne.Value))
                        throw new OverflowException("Underflow detected");
                    
                    var bSquare = b.Value * b.Value;
                    
                    if(double.IsPositiveInfinity(bSquare))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(bSquare))
                        throw new OverflowException("Underflow detected");

                    var fourAC = 4.00D * a * c.Value;
                    
                    if(double.IsPositiveInfinity(fourAC))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(fourAC))
                        throw new OverflowException("Underflow detected");
                    
                    var minus = bSquare - fourAC;
                    
                    if(double.IsPositiveInfinity(minus))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(minus))
                        throw new OverflowException("Underflow detected");

                    if (minus < 0)
                        throw new MathsException("No real-number solutions to the quadratic equation");
                    
                    var partTwo = Math.Sqrt(minus);
                    
                    if(double.IsPositiveInfinity(partTwo))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(partTwo))
                        throw new OverflowException("Underflow detected");
                    
                    var partThree = 2.00D * a;
                    
                    if(double.IsPositiveInfinity(partThree))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(partThree))
                        throw new OverflowException("Underflow detected");

                    result[0] = (partOne + partTwo) / partThree;
                    result[1] = (partOne - partTwo) / partThree;
                    
                    if(double.IsPositiveInfinity(result[0].Value))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(result[0].Value))
                        throw new OverflowException("Underflow detected");
                    
                    if(double.IsPositiveInfinity(result[1].Value))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(result[1].Value))
                        throw new OverflowException("Underflow detected");
                }
            }
            catch (OverflowException ovEx)
            {
                throw new MathsException(ovEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="nearLine"></param>
        /// <param name="farLine"></param>
        /// <returns></returns>
        /// <exception cref="MathsException"></exception>
        public static double Hypotenuse(double nearLine, double farLine)
        {
            if (nearLine <= 0)
                throw new MathsException("Invalid parameter value for nearLine (<=0)");

            if (farLine <= 0)
                throw new MathsException("Invalid parameter value for farLine (<=0)");

            double result;

            try
            {

                checked
                {
                    result = Math.Sqrt(nearLine * nearLine + farLine * farLine);
                    
                    if(double.IsPositiveInfinity(result))
                        throw new OverflowException("Overflow detected");
                    
                    if(double.IsNegativeInfinity(result))
                        throw new OverflowException("Underflow detected");
                }
            }
            catch (OverflowException ovEx)
            {
                throw new MathsException(ovEx.Message);
            }
            catch (Exception ex)
            {
                throw new MathsException(ex.Message);
            }

            
            
            return result;
            
            
        }
    }
}