import sys
import unittest

from files.maths import Maths
from files.maths import MathsException

class MathsTests(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_sum_int64_Common_int_intlist_int(self):
        result = Maths.sum_int64(1, 1, 1, 1, 1)
        self.assertEqual(result, 5)

    def test_sum_int64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.sum_int64(None, 1)

    def test_sum_int64_Special_int_intList_int(self):
        result = Maths.sum_int64(1)
        self.assertEqual(1, 1)

    def test_sum_int64_Special_int_intlist_int__1(self):
        result = Maths.sum_int64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_sum_int64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.sum_int64(sys.maxsize, sys.maxsize)

    def test_sum_int64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.sum_int64(-sys.maxsize - 1, -sys.maxsize - 1)

    def test_sum_int64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.sum_int64(1.01, 1)

    def test_sum_int64_Exceptional_int_intlist_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.sum_int64(1, 1.01)

    def test_sum_float64_Common_int_intlist_int(self):
        result = Maths.sum_float64(1.01, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, 5.05)

    def test_sum_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.sum_float64(None, 1.01)

    def test_sum_float64_Special_int_intList_int(self):
        result = Maths.sum_float64(1.01)
        self.assertEqual(1.01, 1.01)

    def test_sum_float64_Special_int_intlist_int__1(self):
        result = Maths.sum_float64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_sum_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.sum_float64(float('inf'), 1.01)

    def test_sum_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.sum_float64(-float('inf'), 1.01)


    def test_subtract_int64_Common_int_intlist_int(self):
        result = Maths.sum_int64(1, 1, 1, 1, 1)
        self.assertEqual(result, 5)

    def test_subtract_int64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.subtract_int64(None, 1)

    def test_subtract_int64_Special_int_intList_int(self):
        result = Maths.subtract_int64(1)
        self.assertEqual(1, 1)

    def test_subtract_int64_Special_int_intlist_int__1(self):
        result = Maths.subtract_int64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_subtract_int64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.subtract_int64(sys.maxsize, -sys.maxsize)

    def test_subtract_int64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.subtract_int64(-sys.maxsize - 1, sys.maxsize)

    def test_subtract_int64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.subtract_int64(1.01, 1)

    def test_subtract_int64_Exceptional_int_intlist_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.subtract_int64(1, 1.01)

    def test_subtract_float64_Common_int_intlist_int(self):
        result = Maths.subtract_float64(1.01, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, -3.0300000000000002)

    def test_subtract_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.subtract_float64(None, 1.01)

    def test_subtract_float64_Special_int_intList_int(self):
        result = Maths.subtract_float64(1.01)
        self.assertEqual(1.01, 1.01)

    def test_subtract_float64_Special_int_intlist_int__1(self):
        result = Maths.subtract_float64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_subtract_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.subtract_float64(float('inf'), 1.01)

    def test_subtract_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.subtract_float64(-float('inf'), 1.01)


    def test_multiply_int64_Common_int_intlist_int(self):
        result = Maths.multiply_int64(1, 1, 1, 1, 1)
        self.assertEqual(result, 1)

    def test_multiply_int64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.multiply_int64(None, 1)

    def test_multiply_int64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.multiply_int64(1)

    def test_multiply_int64_Special_int_intlist_int__1(self):
        result = Maths.multiply_int64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_multiply_int64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.multiply_int64(sys.maxsize, sys.maxsize)

    def test_multiply_int64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.multiply_int64(-sys.maxsize - 1, -sys.maxsize - 1)

    def test_multiply_int64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.multiply_int64(1.01, 1)

    def test_multiply_int64_Exceptional_int_intlist_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.multiply_int64(1, 1.01)

    def test_multiply_float64_Common_int_intlist_int(self):
        result = Maths.multiply_float64(1.01, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, 1.0510100501)

    def test_multiply_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.multiply_float64(None, 1.01)

    def test_multiply_float64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.multiply_float64(1.01)

    def test_multiply_float64_Special_int_intlist_int__1(self):
        result = Maths.multiply_float64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 0)

    def test_multiply_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.multiply_float64(float('inf'), 1.01)

    def test_multiply_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.multiply_float64(-float('inf'), 1.01)


    def test_divide_int64_Common_int_intlist_int(self):
        result = Maths.divide_int64(1, 1, 1, 1, 1)
        self.assertEqual(result, 1)

    def test_divide_int64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(None, 1)

    def test_divide_int64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(1)

    def test_divide_int64_Special_int_intlist_int__1(self):
        with self.assertRaises(ZeroDivisionError):
            Maths.divide_float64(1, 0)

    def test_divide_int64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(sys.maxsize, 0.99)

    def test_divide_int64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(-sys.maxsize - 1, 0.99)

    def test_divide_int64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(1.01, 1)

    def test_divide_int64_Exceptional_int_intlist_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.divide_int64(1, 1.01)

    def test_divide_float64_Common_int_intlist_int(self):
        result = Maths.divide_float64(1.01, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, 0.9705901479276444)

    def test_divide_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.divide_float64(None, 1.01)

    def test_divide_float64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.divide_float64(1.01)

    def test_divide_float64_Special_int_intlist_int__1(self):
        with self.assertRaises(ZeroDivisionError):
            Maths.divide_float64(1.01, 0.00)

    def test_divide_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.divide_float64(float('inf'), 0.99)

    def test_divide_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.divide_float64(-float('inf'), 0.99)


    def test_power_of_int64_int64_Common_int_intlist_int(self):
        result = Maths.power_of_int64_int64(1, 1, 1, 1, 1)
        self.assertEqual(result, 1)

    def test_power_of_int64_int64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_int64(None, 1)

    def test_power_of_int64_int64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_int64(1)

    def test_power_of_int64_int64_Special_int_intlist_int__1(self):
        result = Maths.power_of_int64_int64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 1)

    def test_power_of_int64_int64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_int64_int64(sys.maxsize, sys.maxsize)

    def test_power_of_int64_int64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_int64_int64(-sys.maxsize - 1, sys.maxsize)

    def test_power_of_int64_int64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_int64(1.01, 1)

    def test_power_of_int64_int64_Exceptional_int_intlist_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_int64(1, 1.01)


    def test_power_of_int64_float64_Common_int_intlist_int(self):
        result = Maths.power_of_int64_float64(1, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, 1)

    def test_power_of_int64_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_float64(None, 1)

    def test_power_of_int64_float64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_float64(1)

    def test_power_of_int64_float64_Special_int_intlist_int__1(self):
        result = Maths.power_of_int64_float64(0, 0, 0, 0, 0, 0, 0)
        self.assertEqual(result, 1)

    def test_power_of_int64_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_int64_float64(float('inf'), 1.01)

    def test_power_of_int64_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_int64_float64(1, float('inf'))

    def test_power_of_int64_float64_Exceptional_int_intlist_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.power_of_int64_float64(1.01, 1)


    def test_power_of_float64_float64_Common_int_intlist_int(self):
        result = Maths.power_of_float64_float64(1.01, 1.01, 1.01, 1.01, 1.01)
        self.assertEqual(result, 1.0410182666018015)

    def test_power_of_float64_float64_Exceptional_intNone_intList_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.power_of_float64_float64(None, 1)

    def test_power_of_float64_float64_Special_int_intList_int(self):
        with self.assertRaises(MathsException):
            Maths.power_of_float64_float64(1.01)

    def test_power_of_float64_float64_Special_int_intlist_int__1(self):
        result = Maths.power_of_float64_float64(0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00)
        self.assertEqual(result, 1.00)

    def test_power_of_float64_float64_Exceptional_int_intlist_OverflowError(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_float64_float64(float('inf'), 1.01)

    def test_power_of_float64_float64_Exceptional_int_intlist_OverflowError__1(self):
        with self.assertRaises(OverflowError):
            Maths.power_of_float64_float64(1.01, float('inf'))

    def test_quadratic_Common_int_int_int_float(self):
        result = Maths.quadratic(1, 4, 1)
        self.assertEqual(result[0], -0.2679491924311228)
        self.assertEqual(result[1], -3.732050807568877)

    def test_quadratic_Special_int_int_int_float(self):
        result = Maths.quadratic(1, None, -4)
        self.assertEqual(result[0], 2)
        self.assertEqual(result[1], -2)

    def test_quadratic_Special_int_int_int_float__1(self):
        result = Maths.quadratic(1, 2, None)
        self.assertEqual(result[0], 0)
        self.assertEqual(result[1], -2)

    def test_quadratic_Special_int_int_int_float__2(self):
        result = Maths.quadratic(1, None, None)
        self.assertEqual(result[0], 0)
        self.assertEqual(result[1], None)

    def test_quadratic_Exceptional_int_int_int_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.quadratic(1, 1, 1)

    def test_quadratic_Exceptional_int_int_int_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.quadratic(0, None, None)

    def test_quadratic_Exceptional_int_int_int_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.quadratic(sys.maxsize, sys.maxsize, sys.maxsize + 1)

    def test_quadratic_Exceptional_int_int_int_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.quadratic(sys.maxsize, sys.maxsize + 1, sys.maxsize)

    def test_hypothenuse_Common_int_int_float(self):
        result = Maths.hypothenuse(1, 4)
        self.assertEqual(result, 4.123105625617661)

    def test_hypothenuse_Exceptional_int_int_MathsException(self):
        with self.assertRaises(MathsException):
            Maths.hypothenuse(0, 1)

    def test_hypothenuse_Exceptional_int_int_MathsException__1(self):
        with self.assertRaises(MathsException):
            Maths.hypothenuse(1, 0)

    def test_hypothenuse_Exceptional_int_int_MathsException__2(self):
        with self.assertRaises(MathsException):
            Maths.hypothenuse(-1, 100)

    def test_hypothenuse_Exceptional_int_int_MathsException__3(self):
        with self.assertRaises(MathsException):
            Maths.hypothenuse(100, -1)

    def test_hypothenuse_Exceptional_int_int_MathsException__4(self):
        with self.assertRaises(OverflowError):
            Maths.hypothenuse(float('inf'), 1)

    def test_hypothenuse_Exceptional_int_int_MathsException__5(self):
        with self.assertRaises(OverflowError):
            Maths.hypothenuse(1, float('inf'))