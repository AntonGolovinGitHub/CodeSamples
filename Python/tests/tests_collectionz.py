import unittest
import sys

from files.collectionz import Collectionz
from files.collectionz import CollectionzException

class CollectionzTests(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_is_empty_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool(self):
        s = set({})
        result = Collectionz.is_empty(s)
        self.assertEqual(result, True)

    def test_is_empty_Special_set_bool__1(self):
        s = set({"", ""})
        result = Collectionz.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool__2(self):
        s = set({None, None})
        result = Collectionz.is_empty(s)
        self.assertEqual(result, False)

    def test_is_empty_Special_set_bool__3(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.is_empty(s)


    def test_is_not_empty_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool(self):
        s = set({})
        result = Collectionz.is_not_empty(s)
        self.assertEqual(result, False)

    def test_is_not_empty_Special_set_bool__1(self):
        s = set({"", ""})
        result = Collectionz.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool__2(self):
        s = set({None, None})
        result = Collectionz.is_not_empty(s)
        self.assertEqual(result, True)

    def test_is_not_empty_Special_set_bool__3(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.is_not_empty(s)


    def test_has_nulls_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.has_nulls(s)
        self.assertEqual(result, False)

    def test_has_nulls_Common_set_bool__1(self):
        s = set({None, 2, 3, 4, 5, 6, 7})
        result = Collectionz.has_nulls(s)
        self.assertEqual(result, True)

    def test_has_nulls_Special_set_bool(self):
        s = set({None, None, None, None, None, None, None})
        result = Collectionz.has_nulls(s)
        self.assertEqual(result, True)

    def test_has_nulls_Special_set_CollectionzException(self):
            s = set({})
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls(s)

    def test_has_nulls_Special_set_CollectionzException__1(self):
            s = None
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls(s)


    def test_has_nulls_at_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.has_nulls_at(s)
        self.assertTrue(len(result) == 0)

    def test_has_nulls_at_Common_set_bool__1(self):
        s = set({1, 2, 3, 4, 5, 6, None})
        result = Collectionz.has_nulls_at(s)
        self.assertEqual(len(result), 1)
        self.assertEqual(result[0], 6)

    def test_has_nulls_at_Special_set_bool(self):
        s = set({None, None, None, None, None, None, None})
        result = Collectionz.has_nulls_at(s)
        self.assertEqual(len(result), 1)
        self.assertEqual(result[0], 0)

    def test_has_nulls_at_Special_set_CollectionzException(self):
            s = set({})
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls_at(s)

    def test_has_nulls_at_Special_set_CollectionzException__1(self):
            s = None
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls_at(s)


    def test_has_nulls_count_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.has_nulls_count(s)
        self.assertTrue(result == 0)

    def test_has_nulls_count_Common_set_bool__1(self):
        s = set({None, 2, 3, 4, 5, 6, 7})
        result = Collectionz.has_nulls_count(s)
        self.assertEqual(result, 1)

    def test_has_nulls_count_Special_set_bool(self):
        s = set({None, None, None, None, None, None, None})
        result = Collectionz.has_nulls_count(s)
        self.assertEqual(result, 1)

    def test_has_nulls_count_Special_set_CollectionzException(self):
            s = set({})
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls_count(s)

    def test_has_nulls_count_Special_set_CollectionzException__1(self):
            s = None
            with self.assertRaises(CollectionzException):
                Collectionz.has_nulls_count(s)


    def test_max_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.max(s)
        self.assertTrue(result == 7)

    def test_max_Special_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, None})
        result = Collectionz.max(s)
        self.assertTrue(result == 6)

    def test_max_Special_set_bool__1(self):
        s = set({None, None, None, None, None, None})
        result = Collectionz.max(s)
        self.assertTrue(result == -sys.maxsize)

    def test_max_Exceptional_set_CollectionzException(self):
        s = set({})
        with self.assertRaises(CollectionzException):
            Collectionz.max(s)

    def test_max_Exceptional_set_CollectionzException(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.max(s)


    def test_min_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.min(s)
        self.assertTrue(result == 1)

    def test_min_Special_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, None})
        result = Collectionz.min(s)
        self.assertTrue(result == 1)

    def test_min_Special_set_bool__1(self):
        s = set({None, None, None, None, None, None})
        result = Collectionz.min(s)
        self.assertTrue(result == sys.maxsize)

    def test_min_Exceptional_set_CollectionzException(self):
        s = set({})
        with self.assertRaises(CollectionzException):
            Collectionz.min(s)

    def test_min_Exceptional_set_CollectionzException(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.min(s)


    def test_peaks_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.peaks(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 7)

    def test_peaks_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7, 7})
        result = Collectionz.peaks(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 7)

    def test_peaks_Special_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, None})
        result = Collectionz.peaks(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 6)

    def test_peaks_Special_set_bool__1(self):
        s = set({None, None, None, None, None, None})
        result = Collectionz.peaks(s)
        self.assertTrue(len(result) == 0)

    def test_peaks_Exceptional_set_CollectionzException(self):
        s = set({})
        with self.assertRaises(CollectionzException):
            Collectionz.peaks(s)

    def test_peaks_Exceptional_set_CollectionzException(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.peaks(s)

    def test_troughs_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7})
        result = Collectionz.troughs(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 1)

    def test_troughs_Common_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, 7, 1})
        result = Collectionz.troughs(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 1)

    def test_troughs_Special_set_bool(self):
        s = set({1, 2, 3, 4, 5, 6, None})
        result = Collectionz.troughs(s)
        self.assertTrue(len(result) == 1)
        self.assertTrue(result[0] == 1)

    def test_troughs_Special_set_bool__1(self):
        s = set({None, None, None, None, None, None})
        result = Collectionz.troughs(s)
        self.assertTrue(len(result) == 0)

    def test_troughs_Exceptional_set_CollectionzException(self):
        s = set({})
        with self.assertRaises(CollectionzException):
            Collectionz.troughs(s)

    def test_troughs_Exceptional_set_CollectionzException(self):
        s = None
        with self.assertRaises(CollectionzException):
            Collectionz.troughs(s)
