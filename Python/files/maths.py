import math
import sys

class Maths:

    @staticmethod
    def sum_int64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                return a
            result = a
            for i in b:
                if int(i) != i:
                    raise MathsException("b must contain ints")
                result = result + i
                if result > sys.maxsize:
                    raise OverflowError
                if result < (-sys.maxsize - 1):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def sum_float64(a, *b):
            try:
                if a is None:
                    raise MathsException("a is None")
                if float(a) != a:
                    raise MathsException("a must be float")
                if len(b) == 0:
                    return a
                result = a
                for i in b:
                    if float(i) != i:
                        raise MathsException("b must contain floats")
                    result = result + i
                    if result >= float('inf'):
                        raise OverflowError
                    if result <= -float('inf'):
                        raise OverflowError
                return result
            except OverflowError as err:
                raise err
            except MathsException as ex:
                raise ex
            finally:
                pass

    @staticmethod
    def subtract_int64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                return a
            result = a
            for i in b:
                if int(i) != i:
                    raise MathsException("b must contain ints")
                result = result - i
                if result > sys.maxsize:
                    raise OverflowError
                if result < (-sys.maxsize - 1):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def subtract_float64(a, *b):
            try:
                if a is None:
                    raise MathsException("a is None")
                if float(a) != a:
                    raise MathsException("a must be float")
                if len(b) == 0:
                    return a
                result = a
                for i in b:
                    if float(i) != i:
                        raise MathsException("b must contain floats")
                    result = result - i
                    if result >= float('inf'):
                        raise OverflowError
                    if result <= -float('inf'):
                        raise OverflowError
                return result
            except OverflowError as err:
                raise err
            except MathsException as ex:
                raise ex
            finally:
                pass

    @staticmethod
    def multiply_int64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                raise MathsException("No b is provided")
            result = a
            for i in b:
                if int(i) != i:
                    raise MathsException("b must contain ints")
                result = result * i
                if result > sys.maxsize:
                    raise OverflowError
                if result < (-sys.maxsize - 1):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def multiply_float64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if float(a) != a:
                raise MathsException("a must be float")
            if len(b) == 0:
                raise MathsException("No b is provided")
            result = a
            for i in b:
                if float(i) != i:
                    raise MathsException("b must contain floats")
                result = result * i
                if result >= float('inf'):
                    raise OverflowError
                if result <= -float('inf'):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def divide_int64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                raise MathsException("No b is provided")
            result = a
            for i in b:
                if int(i) != i:
                    raise MathsException("b must contain ints")
                if i == 0:
                    raise ZeroDivisionError
                result = result / i
                if result > sys.maxsize:
                    raise OverflowError
                if result < (-sys.maxsize - 1):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except ZeroDivisionError as zde:
            raise zde
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def divide_float64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if float(a) != a:
                raise MathsException("a must be float")
            if len(b) == 0:
                raise MathsException("No b is provided")
            result = a
            for i in b:
                if float(i) != i:
                    raise MathsException("b must contain floats")
                if i == 0:
                    raise ZeroDivisionError
                result = result / i
                if result >= float('inf'):
                    raise OverflowError
                if result <= -float('inf'):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except ZeroDivisionError as zde:
            raise zde
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def power_of_int64_int64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                raise MathsException("No b is provided")
            total_power_of = 0
            for i in b:
                if int(i) != i:
                    raise MathsException("a must be int")
                total_power_of = total_power_of + i
                if total_power_of > sys.maxsize:
                    raise OverflowError
                if total_power_of < -sys.maxsize - 1:
                    raise OverflowError
            result = 1
            for i in range(total_power_of):
                if int(i) != i:
                    raise MathsException("a must be int")
                result = result * a
                if result > sys.maxsize:
                    raise OverflowError
                if result < (-sys.maxsize - 1):
                    raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def power_of_int64_float64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if int(a) != a:
                raise MathsException("a must be int")
            if len(b) == 0:
                raise MathsException("No b is provided")
            total_power_of = 0
            for i in b:
                if float(i) != i:
                    raise MathsException("a must be float")
                total_power_of = total_power_of + i
                if total_power_of >= float('inf'):
                    raise OverflowError
                if total_power_of <= -float('inf'):
                    raise OverflowError
            result = a**total_power_of
            if result >= float('inf'):
                raise OverflowError
            if result <= -float('inf'):
                raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    @staticmethod
    def power_of_float64_float64(a, *b):
        try:
            if a is None:
                raise MathsException("a is None")
            if float(a) != a:
                raise MathsException("a must be float")
            if len(b) == 0:
                raise MathsException("No b is provided")
            total_power_of = 0
            for i in b:
                if float(i) != i:
                    raise MathsException("a must be float")
                total_power_of = total_power_of + i
                if total_power_of >= float('inf'):
                    raise OverflowError
                if total_power_of <= -float('inf'):
                    raise OverflowError
            result = 1
            result = a**total_power_of
            if result >= float('inf'):
                raise OverflowError
            if result <= -float('inf'):
                raise OverflowError
            return result
        except OverflowError as err:
            raise err
        except MathsException as ex:
            raise ex
        finally:
            pass

    def quadratic(a, b, c):
        try:
            if a == 0.00:
                raise MathsException("a cannot be 0")
            if b is None:
                b = 0.00
            if c is None:
                c = 0.00
            if b == 0.00 and c == 0.00:
                return 0.00, None
            result = (0, None)
            # let's calculate the answer now
            part_one = -b
            if part_one == math.inf or part_one == -math.inf:
                raise OverflowError
            b_squared = b * b
            if b_squared == math.inf or b_squared == -math.inf:
                raise OverflowError
            four_ac = 4.00 * a * c
            if four_ac == math.inf or four_ac == -math.inf:
                raise OverflowError
            minus = b_squared - four_ac
            if minus == math.inf or minus == -math.inf:
                raise OverflowError
            if minus < 0:
                raise MathsException("No real-number solutions to the quadratic equations")
            part_two = math.sqrt(minus)
            if part_two == math.inf or part_two == -math.inf:
                raise OverflowError
            part_three = 2.00 * a
            if part_three == math.inf or part_three == -math.inf:
                raise OverflowError
            if part_three == 0.00:
                raise ZeroDivisionError
            result0 = (part_one + part_two) / part_three
            result1 = (part_one - part_two) / part_three
            result = result0, result1
            return result
        except OverflowError as oe:
            raise oe
        except ZeroDivisionError as zde:
            raise zde
        except MathsException as me:
            raise me
        finally:
            pass

    def hypothenuse(a, b):
        try:
            if a == 0.00 or a < 0.00:
                raise MathsException("a cannot be <= 0")
            if b == 0.00 or b < 0.00:
                raise MathsException("b cannot be <= 0")
            part_one = a * a
            if part_one >= float('inf'):
                raise OverflowError
            part_two = b * b
            if part_two >= float('inf'):
                raise OverflowError
            part_three = part_one + part_two
            if part_three >= float('inf'):
                raise OverflowError
            result = math.sqrt(part_three)
            return result
        except OverflowError as oe:
            raise oe
        except MathsException as me:
            raise me
        finally:
            pass


class MathsException(Exception):
    pass
