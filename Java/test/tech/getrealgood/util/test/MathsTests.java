package tech.getrealgood.util.test;

import org.junit.jupiter.api.*;
import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;
import tech.getrealgood.util.Maths;
import tech.getrealgood.util.MathsException;

import java.time.Duration;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MathsTests {

    private static final Logger log = LoggerFactory.getLogger(MathsTests.class);

    @Nested
    class SumTests {

        @Test
        void sum_Common_LongArray_Long() {
            try {
                long[] values = new long[]{10, 10, 10, 10, 10, 10, 10};
                assertEquals(70, Maths.sum(values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Common_LongArray_Long__1() {
            try {
                long[] values = new long[]{10, 10, 10, 10, 10, 10, 10};
                assertTimeout(Duration.ofSeconds(1), () -> { Maths.sum(values);});
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Common_LongArray_Long__2() {
            try {
                long[] values = new long[]{10, 10, 10, 10, 10, 10, 10};
                assertTimeoutPreemptively(Duration.ofSeconds(1), () -> { Maths.sum(values);});
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Common_Long_Long() {
            try {
                long value = 10;
                assertEquals(10, Maths.sum(value));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Exceptional_LongArray_MathsException() {
            try {
                long[] values = new long[]{Long.MAX_VALUE, Long.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Exceptional_LongArray_MathsException__1() {
            try {
                long[] values = new long[]{Long.MIN_VALUE, Long.MIN_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Special_LongArray_Long() {
            try {
                long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.sum(values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Nullable_Null_MathsException() {
            try {
                long[] values = null;
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

    }

    @Nested
    class SumTests__1 {
        @Test
        void sum_Common_DoubleArray_Double() {
            try {
                double[] values = new double[]{10, 10, 10, 10, 10, 10, 10};
                assertEquals(70, Maths.sum(values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Common_DoubleArray_Double__1() {
            try {
                double[] values = new double[]{10, 10, 10, 10, 10, 10, 10};
                assertAll(() -> { Maths.sum(values); },
                        () -> { Maths.sum(new double[] {40, 40}); });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Common_Double_Double() {
            try {
                double value = 10;
                assertEquals(10, Maths.sum(value));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Exceptional_DoubleArray_MathsException() {
            try {
                double[] values = new double[]{Double.MAX_VALUE, Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Exceptional_DoubleArray_MathsException__1() {
            try {
                double[] values = new double[]{-Double.MAX_VALUE, -Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Special_DoubleArray_Long() {
            try {
                double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.sum(values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void sum_Nullable_Double_MathsException() {
            try {
                double[] values = null;
                assertThrows(MathsException.class, () -> {
                    Maths.sum(values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

    }

    @Nested
    class SubtractTests {

        @Test
        public void subtract_Common_LongArray_Long() {
            try {
                long[] values = new long[]{10, 10, 10, 10, 10, 10};
                assertEquals(-50, Maths.subtract(10, values));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Common_Long_Long() {
            try {
                long value = 10;
                assertEquals(0, Maths.subtract(10, value));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Exceptional_LongArray_MathsException() {
            try {
                long[] values = new long[]{Long.MIN_VALUE, Long.MIN_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.subtract(0, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Exceptional_LongArray_MathsException__1() {
            try {
                long[] values = new long[]{Long.MAX_VALUE, Long.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.subtract(0, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Nullable_Null_MathsException() {
            try {
                long[] values = null;

                assertThrows(MathsException.class, () -> {
                    Maths.subtract(10, values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Special_LongArray_Long() {
            try {
                long[] values = new long[]{0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.subtract(0, values));

            } catch (Exception ex) {
                fail();
            }
        }
    }

    @Nested
    class SubtractTests__1 {
        @Test
        public void subtract_Common_DoubleArray_Double() {
            try {
                double[] values = new double[]{10, 10, 10, 10, 10, 10};
                assertEquals(-50, Maths.subtract(10, values));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Common_Double_Double() {
            try {
                double value = 10;
                assertEquals(0, Maths.subtract(10, value));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Exceptional_DoubleArray_MathsException() {
            try {
                double[] values = new double[]{-Double.MAX_VALUE, -Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.subtract(0, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Exceptional_DoubleArray_MathsException__1() {
            try {
                double[] values = new double[]{Double.MAX_VALUE, Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.subtract(0, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Nullable_Null_MathsException() {
            try {
                long[] values = null;

                assertThrows(MathsException.class, () -> {
                    Maths.subtract(10, values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void subtract_Special_DoubleArray_Double() {
            try {
                double[] values = new double[]{0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.subtract(0, values));

            } catch (Exception ex) {
                fail();
            }
        }

    }

    @Nested
    class MultiplyTests {

        @Test
        public void multiply_Common_LongArray_Long() {

            try {

                long[] values = new long[]{10, 10, 10, 10, 10, 10, 10};
                assertEquals(10000000, Maths.multiply(values));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Common_Long_Long() {

            try {

                long value = 10;
                assertEquals(10, Maths.multiply(value));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Exceptional_LongArray_MathsException() {

            try {

                long[] values = new long[]{Long.MAX_VALUE, Long.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Exceptional_LongArray_MathsException__1() {

            try {

                long[] values = new long[]{Long.MAX_VALUE, Long.MIN_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Nullable_Null_MathsException() {

            try {

                long[] values = null;
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Special_LongArray_Long() {

            try {

                long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.multiply(values));

            } catch (Exception ex) {
                fail();
            }
        }
    }

    @Nested
    class MultiplyTests__1 {

        @Test
        public void multiply_Common_DoubleArray_Double() {

            try {

                double[] values = new double[]{10, 10, 10, 10, 10, 10, 10};
                assertEquals(10000000, Maths.multiply(values));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Common_Double_Double() {

            try {

                double value = 10;
                assertEquals(10, Maths.multiply(value));

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Exceptional_DoubleArray_MathsException() {

            try {

                double[] values = new double[]{Double.MAX_VALUE, Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Exceptional_DoubleArray_MathsException__1() {

            try {

                double[] values = new double[]{Double.MAX_VALUE, -Double.MAX_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Nullable_Null_MathsException() {

            try {

                double[] values = null;
                assertThrows(MathsException.class, () -> {
                    Maths.multiply(values);
                });

            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void multiply_Special_DoubleArray_Double() {

            try {

                double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(0, Maths.multiply(values));

            } catch (Exception ex) {
                fail();
            }
        }

    }

    @Nested
    class DivideTests {

        @Test
        void divide_Common_DoubleArray_Double() {

            try {

                double[] values = new double[]{10, 1, 1, 1, 1, 10};
                assertEquals(0.1, Maths.divide(10, values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void divide_Common_Double_Double() {

            try {
                long value = 10;
                assertEquals(1, Maths.divide(10, value));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void divide_Exceptional_DoubleArray_MathsException() {

            try {

                double[] values = new double[]{Double.MIN_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.divide(Double.MAX_VALUE, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void divide_Exceptional_DoubleArray_MathsException__1() {

            try {

                double[] values = new double[]{Double.MIN_VALUE};
                assertThrows(MathsException.class, () -> {
                    Maths.divide(-Double.MAX_VALUE, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void divide_Nullable_Null_MathsException() {

            try {

                double[] values = null;
                assertThrows(MathsException.class, () -> {
                    Maths.divide(1, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        void divide_Special_DoubleArray_MathsException() {

            try {

                double[] values = new double[]{0, 0, 0, 0, 0, 0};
                assertThrows(MathsException.class, () -> {
                    Maths.divide(1, values);
                });
            } catch (Exception ex) {
                fail();
            }
        }

    }

    @Nested
    class PowerOfTests {

        @Test
        public void powerOf_Common_Long_LongArray_Long() {

            try {
                long[] values = new long[]{2, 1, 1, 1, 1, 2};
                assertEquals(100000000, Maths.powerOf(10, values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Common_Long_Long_Long() {

            try {
                long value = 2;
                assertEquals(100, Maths.powerOf(10, value));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Nullable_Long_Null_MathsException() {

            try {
                long[] values = null;
                assertThrows(MathsException.class, () -> { Maths.powerOf(10, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Long_LongArray_MathsException() {

            try {
                long[] values = new long[]{10};
                assertThrows(MathsException.class, () -> { Maths.powerOf(Long.MAX_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Long_LongArray_MathsException__1() {

            try {
                long[] values = new long[]{3};
                assertThrows(MathsException.class, () -> { Maths.powerOf(Long.MIN_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Special_Long_LongArray_Long() {

            try {
                long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(1, Maths.powerOf(10, values));
            } catch (Exception ex) {
                fail();
            }
        }
    }

    @Nested
    class PowerOfTests__1 {

        @Test
        public void powerOf_Common_Double_LongArray_Double() {

            try {
                long[] values = new long[]{2, 1, 1, 1, 1, 2};
                assertEquals(100000000, Maths.powerOf(10d, values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Common_Double_Long_Double() {

            try {
                long value = 2;
                assertEquals(100, Maths.powerOf(10d, value));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Nullable_Double_Null_MathsException() {

            try {
                long[] values = null;
                assertThrows(MathsException.class, () -> { Maths.powerOf(10d, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Double_LongArray_MathsException() {

            try {
                long[] values = new long[]{10};
                assertThrows(MathsException.class, () -> { Maths.powerOf(Double.MAX_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Double_LongArray_MathsException__1() {

            try {
                long[] values = new long[]{3};
                assertThrows(MathsException.class, () -> { Maths.powerOf(-Double.MAX_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Special_Double_LongArray_Double() {

            try {
                long[] values = new long[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(1, Maths.powerOf(10d, values));
            } catch (Exception ex) {
                fail();
            }
        }
    }

    @Nested
    class PowerOfTests__2 {

        @Test
        public void powerOf_Common_Double_DoubleArray_Double() {

            try {
                double[] values = new double[]{2, 1, 1, 1, 1, 2};
                assertEquals(100000000d, Maths.powerOf(10d, values));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Common_Double_Double_Double() {

            try {
                double value = 2;
                assertEquals(100d, Maths.powerOf(10d, value));
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Nullable_Double_Null_MathsException() {

            try {
                double[] values = null;
                assertThrows(MathsException.class, () -> { Maths.powerOf(10d, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Double_LongArray_MathsException() {

            try {
                double[] values = new double[]{10};
                assertThrows(MathsException.class, () -> { Maths.powerOf(Double.MAX_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Exceptional_Double_LongArray_MathsException__1() {

            try {
                double[] values = new double[]{3};
                assertThrows(MathsException.class, () -> { Maths.powerOf(-Double.MAX_VALUE, values); });
            } catch (Exception ex) {
                fail();
            }
        }

        @Test
        public void powerOf_Special_Double_LongArray_Long() {

            try {
                double[] values = new double[]{0, 0, 0, 0, 0, 0, 0};
                assertEquals(1d, Maths.powerOf(10d, values));
            } catch (Exception ex) {
                fail();
            }
        }
    }

    @Nested
    class QuadraticTests {

        @Test
        void quadratic_Common_Double_Double_Double_Double() {

            try {

                double a = 1D;
                Double b = 1D;
                Double c = -1D;
                List result = Maths.quadratic(a, b, c);

                assertEquals(0.6180339887498949, result.get(0));
                assertEquals(-1.618033988749895, result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Special_Double_Null_Double_Double() {

            try {

                double a = 1D;
                Double b = null;
                Double c = -4D;
                List result = Maths.quadratic(a, b, c);

                assertEquals(2.0d, result.get(0));
                assertEquals(-2.0d, result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Special_Double_Double_Null_Double() {

            try {

                double a = 1D;
                Double b = 2D;
                Double c = null;
                List result = Maths.quadratic(a, b, c);

                assertEquals(0.0d, result.get(0));
                assertEquals(-2.0d, result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Special_Double_Null_Null_Double() {

            try {

                double a = 1D;
                Double b = null;
                Double c = null;
                List result = Maths.quadratic(a, b, c);

                assertEquals(0.0d, result.get(0));
                assertEquals(null, result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Special_Double_Double_Double_MathsException() {

            try {

                double a = 0;
                Double b = null;
                Double c = null;
                assertThrows(MathsException.class, () -> { Maths.quadratic(a, b, c); });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Exceptional_Double_Double_Double_MathsException() {

            try {

                double a = Double.MAX_VALUE;
                Double b = Double.MAX_VALUE;
                Double c = -Double.MAX_VALUE;
                assertThrows(MathsException.class, () -> { Maths.quadratic(a, b, c); });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        void quadratic_Exceptional_Double_Double_Double_MathsException__1() {

            try {

                double a = -Double.MAX_VALUE;
                Double b = -Double.MAX_VALUE;
                Double c = Double.MAX_VALUE;

                assertThrows(MathsException.class, () -> { Maths.quadratic(a, b, c); }, "Found errors");

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class HypotenuseTests {

        @Test
        public void hypotenuse_Common_Double_Double_Double() {

            try {

                double nearLine = 3;
                double farLine = 1;

                assertEquals(Math.sqrt(10), Maths.hypotenuse(nearLine, farLine));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Special_Double_Double_MathsException() {

            try {

                double nearLine = 0;
                double farLine = 1;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Special_Double_Double_MathsException__1() {

            try {

                double nearLine = 1;
                double farLine = 0;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Special_Double_Double_MathsException__2() {

            try {

                double nearLine = -1;
                double farLine = 100;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Special_Double_Double_MathsException__3() {

            try {

                double nearLine = 100;
                double farLine = -1;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Exceptional_Double_Double_MathsException() {

            try {

                double nearLine = Double.MAX_VALUE;
                double farLine = Double.MAX_VALUE;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hypotenuse_Exceptional_Double_Double_MathsException__1() {

            try {

                double nearLine = -Double.MAX_VALUE;
                double farLine = Double.MAX_VALUE;

                assertThrows(MathsException.class, () -> { Maths.hypotenuse(nearLine, farLine); } );

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }


}