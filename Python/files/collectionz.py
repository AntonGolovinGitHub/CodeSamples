import math
import sys


class CollectionzException(Exception):
    pass

# a is list
class Collectionz:

    @staticmethod
    def is_empty(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        return len(a) == 0

    @staticmethod
    def is_not_empty(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        return len(a) != 0

    @staticmethod
    def has_nulls_at(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        b = []
        for i in range(len(c)):
            if c[i] is None:
                b.append(i)
        return b

    @staticmethod
    def has_nulls(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        for i in range(len(c)):
            if c[i] is None:
                return True
        return False

    @staticmethod
    def has_nulls_count(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        b = []
        for i in range(len(c)):
            if c[i] is None:
                b.append(i)
        return len(b)

    @staticmethod
    def max(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        max = -sys.maxsize
        y = 0
        for i in range(len(c)):
            if c[i] == None:
                continue
            if y == 0:
                max = c[0]
                y = y + 1
                continue
            if c[i] > max:
                max = c[i]
        return max

    @staticmethod
    def min(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        min = sys.maxsize
        y = 0
        for i in range(len(c)):
            if c[i] == None:
                continue
            if y == 0:
                min = c[0]
                y = y + 1
                continue
            if c[i] < min:
                min = c[i]
        return min

    @staticmethod
    def peaks(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        b = []
        max = -sys.maxsize
        y = 0
        for i in range(len(c)):
            if c[i] == None:
                continue
            if y == 0:
                max = c[0]
                b.append(max)
                y = y + 1
                continue
            elif c[i] < max:
                continue
            elif c[i] == max:
                b.append(a[i])
            elif c[i] > max:
                max = c[i]
                b.clear()
                b.append(max)

        return b

    @staticmethod
    def troughs(a):
        if a is None:
            raise CollectionzException("a == None")
        if not isinstance(a, set):
            raise CollectionzException("a must be a set")
        if len(a) == 0:
            raise CollectionzException("len(a) == 0")
        c = list(a)
        b = []
        min = sys.maxsize
        y = 0
        for i in range(len(c)):
            if c[i] == None:
                continue
            if y == 0:
                min = c[0]
                b.append(min)
                y = y + 1
                continue
            elif c[i] > min:
                continue
            elif c[i] == min:
                b.append(c[i])
            elif c[i] < min:
                min = c[i]
                b.clear()
                b.append(min)

        return b
