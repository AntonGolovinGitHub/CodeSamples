import unittest
from files.objects import Objects

class ObjectsTests(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_isnull_Common_object_bool(self):
        v = object
        assert Objects.isnull(v) == False

    def test_isnull_Nullable_objectNone_bool(self):
        v = None
        assert Objects.isnull(v) == True

    def test_isnotnull_Common_object_bool(self):
        v = object
        assert Objects.isnotnull(v) == True

    def test_isnotnull_Nullable_objectNone_bool(self):
        v = None
        assert Objects.isnotnull(v) == False
