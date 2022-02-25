import unittest
import sys

from files.arrays import Arrays
from files.arrays import ArraysException

class ArraysTests(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_is_empty_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool(self):
        s = []
        result = Arrays.is_empty(s)
        self.assertEqual(result, True)

    def test_is_empty_Special_set_bool__1(self):
        s = ["", ""]
        result = Arrays.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool__2(self):
        s = [None, None]
        result = Arrays.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool__3(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.is_empty(s)


    def test_is_not_empty_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool(self):
        s = []
        result = Arrays.is_not_empty(s)
        self.assertEqual(result, False)

    def test_is_not_empty_Special_set_bool__1(self):
        s = ["", ""]
        result = Arrays.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool__2(self):
        s = [None, None]
        result = Arrays.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool__3(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.is_not_empty(s)


    def test_has_nulls_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.has_nulls(s)
        self.assertEqual(result, False)

    def test_has_nulls_Common_set_bool__1(self):
        s = [None, 2, 3, 4, 5, 6, 7]
        result = Arrays.has_nulls(s)
        self.assertEqual(result, True)

    def test_has_nulls_Special_set_bool(self):
        s = [None, None, None, None, None, None, None]
        result = Arrays.has_nulls(s)
        self.assertEqual(result, True)

    def test_has_nulls_Special_set_ArraysException(self):
            s = []
            with self.assertRaises(ArraysException):
                Arrays.has_nulls(s)

    def test_has_nulls_Special_set_ArraysException__1(self):
            s = None
            with self.assertRaises(ArraysException):
                Arrays.has_nulls(s)


    def test_has_nulls_at_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.has_nulls_at(s)
        self.assertTrue(len(result) == 0)

    def test_has_nulls_at_Common_set_bool__1(self):
        s = [1, 2, 3, 4, 5, 6, None]
        result = Arrays.has_nulls_at(s)
        self.assertEqual(len(result), 1)
        self.assertEqual(result[0], 6)

    def test_has_nulls_at_Special_set_bool(self):
        s = [None, None, None, None, None, None, None]
        result = Arrays.has_nulls_at(s)
        self.assertEqual(len(result), 7)
        self.assertEqual(result[0], 0)
        self.assertEqual(result[1], 1)
        self.assertEqual(result[2], 2)
        self.assertEqual(result[3], 3)
        self.assertEqual(result[4], 4)
        self.assertEqual(result[5], 5)
        self.assertEqual(result[6], 6)

    def test_has_nulls_at_Special_set_ArraysException(self):
            s = []
            with self.assertRaises(ArraysException):
                Arrays.has_nulls_at(s)

    def test_has_nulls_at_Special_set_ArraysException__1(self):
            s = None
            with self.assertRaises(ArraysException):
                Arrays.has_nulls_at(s)


    def test_has_nulls_count_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.has_nulls_count(s)
        self.assertTrue(result == 0)

    def test_has_nulls_count_Common_set_bool__1(self):
        s = [None, 2, 3, 4, 5, 6, 7]
        result = Arrays.has_nulls_count(s)
        self.assertEqual(result, 1)

    def test_has_nulls_count_Special_set_bool(self):
        s = [None, None, None, None, None, None, None]
        result = Arrays.has_nulls_count(s)
        self.assertEqual(result, 7)

    def test_has_nulls_count_Special_set_ArraysException(self):
            s = []
            with self.assertRaises(ArraysException):
                Arrays.has_nulls_count(s)

    def test_has_nulls_count_Special_set_ArraysException__1(self):
            s = None
            with self.assertRaises(ArraysException):
                Arrays.has_nulls_count(s)


    def test_max_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.max(s)
        self.assertTrue(result == 7)

    def test_max_Special_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, None]
        result = Arrays.max(s)
        self.assertTrue(result == 6)

    def test_max_Special_set_bool__1(self):
        s = [None, None, None, None, None, None]
        result = Arrays.max(s)
        self.assertTrue(result == -sys.maxsize)

    def test_max_Exceptional_set_ArraysException(self):
        s = []
        with self.assertRaises(ArraysException):
            Arrays.max(s)

    def test_max_Exceptional_set_ArraysException(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.max(s)


    def test_min_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.min(s)
        self.assertTrue(result == 1)

    def test_min_Special_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, None]
        result = Arrays.min(s)
        self.assertTrue(result == 1)

    def test_min_Special_set_bool__1(self):
        s = [None, None, None, None, None, None]
        result = Arrays.min(s)
        self.assertTrue(result == sys.maxsize)

    def test_min_Exceptional_set_ArraysException(self):
        s = []
        with self.assertRaises(ArraysException):
            Arrays.min(s)

    def test_min_Exceptional_set_ArraysException(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.min(s)


    def test_peaks_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.peaks(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 7)

    def test_peaks_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7, 7]
        result = Arrays.peaks(s)
        self.assertTrue(len(result) == 2)
        self.assertTrue(result[0] == 7)
        self.assertTrue(result[1] == 7)

    def test_peaks_Special_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, None]
        result = Arrays.peaks(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 6)

    def test_peaks_Special_set_bool__1(self):
        s = [None, None, None, None, None, None]
        result = Arrays.peaks(s)
        self.assertTrue(len(result) == 0)

    def test_peaks_Exceptional_set_ArraysException(self):
        s = []
        with self.assertRaises(ArraysException):
            Arrays.peaks(s)

    def test_peaks_Exceptional_set_ArraysException(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.peaks(s)

    def test_troughs_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7]
        result = Arrays.troughs(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 1)

    def test_troughs_Common_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, 7, 1]
        result = Arrays.troughs(s)
        self.assertTrue(len(result) == 2)
        self.assertTrue(result[0] == 1)
        self.assertTrue(result[1] == 1)

    def test_troughs_Special_set_bool(self):
        s = [1, 2, 3, 4, 5, 6, None]
        result = Arrays.troughs(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 1)

    def test_troughs_Special_set_bool__1(self):
        s = [None, None, None, None, None, None]
        result = Arrays.troughs(s)
        self.assertTrue(len(result) == 0)

    def test_troughs_Exceptional_set_ArraysException(self):
        s = []
        with self.assertRaises(ArraysException):
            Arrays.troughs(s)

    def test_troughs_Exceptional_set_ArraysException(self):
        s = None
        with self.assertRaises(ArraysException):
            Arrays.troughs(s)
