using NUnit.Framework;
using System;
using System.Collections.Generic;
using NUnit.Framework.Internal;

namespace GetRealGood.Utils.Tests
{
    public class MathsTests
    {
        [OneTimeSetUp]
        public void SetupAll()
        {
        }

        [OneTimeTearDown]
        public void TearDownAll()
        {
        }

        
        [SetUp]
        public void Setup()
        {
        }

        [TearDown]
        public void TearDown()
        {
        }

        class SumTests
        {

            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }

            
            [Test]
            public void Sum_Common_LongArray_Long()
            {
                try
                {
                    long[] values = new long[] {10, 10, 10, 10, 10, 10, 10};
                    Assert.AreEqual(Maths.Sum(values), 70);
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Common_Long_Long()
            {
                try
                {
                    long value = 10;
                    Assert.AreEqual(Maths.Sum(value), 10);
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Exceptional_LongArray_MathsException()
            {
                try
                {
                    long[] values = new long[] {long.MaxValue, long.MaxValue};
                    Assert.Throws(typeof(MathsException), delegate { Maths.Sum(values); });
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Exceptional_LongArray_MathsException__1()
            {
                try
                {
                    long[] values = new long[] {long.MinValue, long.MinValue};
                    Assert.Throws(typeof(MathsException), delegate { Maths.Sum(values); });
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Special_LongArray_Long()
            {
                try
                {
                    long[] values = new long[] {0, 0, 0, 0, 0, 0, 0};
                    Assert.AreEqual(Maths.Sum(values), 0);
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Nullable_Null_MathsException()
            {
                try
                {
                    long[] values = null;
                    Assert.Throws(typeof(MathsException), delegate { Maths.Sum(values); });
                }
                catch (Exception ex)
                {
                    Assert.Fail();
                }
            }

        }
        
        class SumTests__1 {
            [Test]
            public void Sum_Common_DoubleArray_Double() {
                try {
                    double[] values = new double[]{10, 10, 10, 10, 10, 10, 10};
                    Assert.AreEqual(Maths.Sum(values), 70);

                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Common_Double_Double() {
                try {
                    double value = 10;
                    Assert.AreEqual(Maths.Sum(value), 10);

                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Exceptional_DoubleArray_MathsException() {
                try {
                    double[] values = new double[]{double.MaxValue, double.MaxValue};
                    Assert.Throws(typeof(MathsException), delegate {
                        Maths.Sum(values);
                    });
                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Exceptional_DoubleArray_MathsException__1() {
                try {
                    double[] values = new double[]{double.MinValue, double.MinValue};
                    Assert.Throws(typeof(MathsException), delegate {
                        Maths.Sum(values);
                    });
                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Special_DoubleArray_Long() {
                try {
                    double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                    Assert.AreEqual(Maths.Sum(values), 0);
                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

            [Test]
            public void Sum_Nullable_Double_MathsException() {
                try {
                    double[] values = null;
                    Assert.Throws(typeof(MathsException), delegate {
                        Maths.Sum(values);
                    });
                } catch (Exception ex) {
                    Assert.Fail();
                }
            }

        }
        
        class SubtractTests {

        [Test]
        public void Subtract_Common_LongArray_Long() {
            try {
                long[] values = new long[]{10, 10, 10, 10, 10, 10};
                Assert.AreEqual( -50, Maths.Subtract(10, values));

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Common_Long_Long() {
            try {
                long value = 10;
                Assert.AreEqual(0, Maths.Subtract(10, value));

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Exceptional_LongArray_MathsException() {
            try {
                long[] values = new long[]{long.MinValue, long.MinValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(0, values);
                });
            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Exceptional_LongArray_MathsException__1() {
            try {
                long[] values = new long[]{long.MaxValue, long.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(0, values);
                });
            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Nullable_Null_MathsException() {
            try {
                long[] values = null;

                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(10, values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Special_LongArray_Long() {
            try {
                long[] values = new long[] {0, 0, 0, 0, 0, 0};
                Assert.AreEqual(Maths.Subtract(0L, values), 0);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }
    }
        
        class SubtractTests__1 {
        [Test]
        public void Subtract_Common_DoubleArray_Double() {
            try {
                double[] values = new double[]{10, 10, 10, 10, 10, 10};
                Assert.AreEqual(Maths.Subtract(10, values), -50);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Common_Double_Double() {
            try {
                double value = 10;
                Assert.AreEqual(Maths.Subtract(10, value), 0);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Exceptional_DoubleArray_MathsException() {
            try {
                double[] values = new double[]{-double.MaxValue, -double.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(0, values);
                });
            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Exceptional_DoubleArray_MathsException__1() {
            try {
                double[] values = new double[]{double.MaxValue, double.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(0, values);
                });
            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Nullable_Null_MathsException() {
            try {
                long[] values = null;

                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Subtract(10, values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Subtract_Special_DoubleArray_Double() {
            try {
                double[] values = new double[]{0, 0, 0, 0, 0, 0};
                Assert.AreEqual(Maths.Subtract(0, values), 0);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

    }
        
         class MultiplyTests {

        [Test]
        public void Multiply_Common_LongArray_Long() {

            try {

                long[] values = new long[]{10, 10, 10, 10, 10, 10, 10};
                Assert.AreEqual(Maths.Multiply(values), 10000000);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Common_Long_Long() {

            try {

                long value = 10;
                Assert.AreEqual(Maths.Multiply(value), 10);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Exceptional_LongArray_MathsException() {

            try {

                long[] values = new long[]{long.MaxValue, long.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Exceptional_LongArray_MathsException__1() {

            try {

                long[] values = new long[]{long.MaxValue, long.MinValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Nullable_Null_MathsException() {

            try {

                long[] values = null;
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Special_LongArray_Long() {

            try {

                long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                Assert.AreEqual(Maths.Multiply(values), 0);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }
    }

         class MultiplyTests__1 {

        [Test]
        public void Multiply_Common_DoubleArray_Double() {

            try {

                double[] values = new double[]{10, 10, 10, 10, 10, 10, 10};
                Assert.AreEqual(Maths.Multiply(values), 10000000);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Common_Double_Double() {

            try {

                double value = 10;
                Assert.AreEqual(Maths.Multiply(value), 10);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Exceptional_DoubleArray_MathsException() {

            try {

                double[] values = new double[]{double.MaxValue, double.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Exceptional_DoubleArray_MathsException__1() {

            try {

                double[] values = new double[]{double.MaxValue, -double.MaxValue};
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Nullable_Null_MathsException() {

            try {

                double[] values = null;
                Assert.Throws(typeof(MathsException), delegate {
                    Maths.Multiply(values);
                });

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

        [Test]
        public void Multiply_Special_DoubleArray_Double() {

            try {

                double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                Assert.AreEqual(Maths.Multiply(values), 0);

            } catch (Exception ex) {
                Assert.Fail();
            }
        }

    }

         class DivideTests
         {

             [Test]
             public void Divide_Common_DoubleArray_Double()
             {

                 try
                 {

                     double[] values = new double[] {10, 1, 1, 1, 1, 10};
                     Assert.AreEqual(Maths.Divide(10, values), 0.1);
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

             [Test]
             public void Divide_Common_Double_Double()
             {

                 try
                 {
                     long value = 10;
                     Assert.AreEqual(Maths.Divide(10, value), 1);
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

             [Test]
             public void Divide_Exceptional_DoubleArray_MathsException()
             {

                 try
                 {

                     double[] values = new double[] {double.Epsilon};
                     Assert.Throws(typeof(MathsException), delegate { Maths.Divide(double.MaxValue, values); });
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

             [Test]
             public void Divide_Exceptional_DoubleArray_MathsException__1()
             {

                 try
                 {

                     double[] values = new double[] {double.Epsilon};
                     Assert.Throws(typeof(MathsException), delegate { Maths.Divide(-double.MaxValue, values); });
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

             [Test]
             public void Divide_Nullable_Null_MathsException()
             {

                 try
                 {

                     double[] values = null;
                     Assert.Throws(typeof(MathsException), delegate { Maths.Divide(1, values); });
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

             [Test]
             public void Divide_Special_DoubleArray_MathsException()
             {

                 try
                 {

                     double[] values = new double[] {0, 0, 0, 0, 0, 0};
                     Assert.Throws(typeof(MathsException), delegate { Maths.Divide(1, values); });
                 }
                 catch (Exception ex)
                 {
                     Assert.Fail();
                 }
             }

         }
         
         class PowerOfTests {

             [Test]
             public void PowerOf_Common_Long_LongArray_Long() {

                 try {
                     long[] values = new long[]{2, 1, 1, 1, 1, 2};
                     Assert.AreEqual(Maths.PowerOf(10, values), 100000000);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Common_Long_Long_Long() {

                 try {
                     long value = 2;
                     Assert.AreEqual(Maths.PowerOf(10, value), 100);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Nullable_Long_Null_MathsException() {

                 try {
                     long[] values = null;
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(10, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Long_LongArray_MathsException() {

                 try {
                     long[] values = new long[]{10};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(long.MaxValue, values); });
                 } catch (Exception ex) {
                    Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Long_LongArray_MathsException__1() {

                 try {
                     long[] values = new long[]{3};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(long.MinValue, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Special_Long_LongArray_Long() {

                 try {
                     long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                     Assert.AreEqual(Maths.PowerOf(10, values), 1);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }
         }
         
         class PowerOfTests__1 {

             [Test]
             public void PowerOf_Common_Double_LongArray_Double() {

                 try {
                     long[] values = new long[]{2, 1, 1, 1, 1, 2};
                     Assert.AreEqual(Maths.PowerOf(10d, values), 100000000);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Common_Double_Long_Double() {

                 try {
                     long value = 2;
                     Assert.AreEqual(Maths.PowerOf(10d, value), 100);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Nullable_Double_Null_MathsException() {

                 try {
                     long[] values = null;
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(10d, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Double_LongArray_MathsException() {

                 try {
                     long[] values = new long[]{10};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(double.MaxValue, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Double_LongArray_MathsException__1() {

                 try {
                     long[] values = new long[]{3};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(-double.MaxValue, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Special_Double_LongArray_Double() {

                 try {
                     long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                     Assert.AreEqual(Maths.PowerOf(10d, values), 1);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }
         }
         
         class PowerOfTests__2 {

             [Test]
             public void PowerOf_Common_Double_DoubleArray_Double() {

                 try {
                     double[] values = new double[]{2, 1, 1, 1, 1, 2};
                     Assert.AreEqual(Maths.PowerOf(10d, values), 100000000d);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Common_Double_Double_Double() {

                 try {
                     double value = 2;
                     Assert.AreEqual(Maths.PowerOf(10d, value), 100d);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Nullable_Double_Null_MathsException() {

                 try {
                     double[] values = null;
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(10d, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Double_LongArray_MathsException() {

                 try {
                     double[] values = new double[]{10};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(double.MaxValue, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Exceptional_Double_LongArray_MathsException__1() {

                 try {
                     double[] values = new double[]{3};
                     Assert.Throws(typeof(MathsException), delegate { Maths.PowerOf(-double.MaxValue, values); });
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }

             [Test]
             public void PowerOf_Special_Double_LongArray_Long() {

                 try {
                     double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                     Assert.AreEqual(Maths.PowerOf(10d, values), 1d);
                 } catch (Exception ex) {
                     Assert.Fail();
                 }
             }
         }
         
          class QuadraticTests {

        [Test]
        public void Quadratic_Common_Double_Double_Double_Double() {

            try {

                double a = 1D;
                Double b = 1D;
                Double c = -1D;
                IList<double?> result = Maths.Quadratic(a, b, c);

                Assert.AreEqual(0.6180339887498949, result[0]);
                Assert.AreEqual(-1.618033988749895, result[1]);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Special_Double_Null_Double_Double() {

            try {

                double a = 1D;
                double? b = null;
                double c = -4D;
                IList<double?> result = Maths.Quadratic(a, b, c);

                Assert.AreEqual(2, result[0]);
                Assert.AreEqual(-2, result[1]);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Special_Double_Double_Null_Double() {

            try {

                double a = 1D;
                double? b = 2D;
                double? c = null;
                IList<double?> result = Maths.Quadratic(a, b, c);

                Assert.AreEqual(0, result[0]);
                Assert.AreEqual(-2, result[1]);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Special_Double_Null_Null_Double() {

            try {

                double a = 1D;
                double? b = null;
                double? c = null;
                IList<double?> result = Maths.Quadratic(a, b, c);

                Assert.AreEqual(0, result[0]);
                Assert.AreEqual(null, result[1]);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Special_Double_Double_Double_MathsException() {

            try {

                double a = 0;
                double? b = null;
                double? c = null;
                Assert.Throws(typeof(MathsException), delegate { Maths.Quadratic(a, b, c); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Exceptional_Double_Double_Double_MathsException() {

            try {

                double a = double.MaxValue;
                double? b = double.MaxValue;
                double? c = double.MinValue;
                Assert.Throws(typeof(MathsException), delegate { Maths.Quadratic(a, b, c); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Quadratic_Exceptional_Double_Double_Double_MathsException__1() {

            try {

                double a = double.MinValue;
                double? b = double.MinValue;
                double? c = double.MaxValue;

                Assert.Throws(typeof(MathsException), delegate { Maths.Quadratic(a, b, c); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

    }
          
          class HypotenuseTests {

        [Test]
        public void Hypotenuse_Common_Double_Double_Double() {

            try {

                double nearLine = 3;
                double farLine = 1;

                Assert.AreEqual(Math.Sqrt(10), Maths.Hypotenuse(nearLine, farLine));

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Special_Double_Double_MathsException() {

            try {

                double nearLine = 0;
                double farLine = 1;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Special_Double_Double_MathsException__1() {

            try {

                double nearLine = 1;
                double farLine = 0;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Special_Double_Double_MathsException__2() {

            try {

                double nearLine = -1;
                double farLine = 100;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Special_Double_Double_MathsException__3() {

            try {

                double nearLine = 100;
                double farLine = -1;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Exceptional_Double_Double_MathsException() {

            try {

                double nearLine = double.MaxValue;
                double farLine = double.MaxValue;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void Hypotenuse_Exceptional_Double_Double_MathsException__1() {

            try {

                double nearLine = -double.MaxValue;
                double farLine = double.MaxValue;

                Assert.Throws(typeof(MathsException), delegate { Maths.Hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }
          
    }
          
    }
    }
    