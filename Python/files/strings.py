
class Strings:

    @staticmethod
    def toupper(o):
        if o is None:
            raise StringsException("o is None")
        return o.upper()

    @staticmethod
    def tolower(o):
        if o is None:
            raise StringsException("o is None")
        return o.lower()

    @staticmethod
    def split(str, token="", trim=False):
        if str is None:
            raise StringsException("str is None")
        if token is None:
            raise StringsException("token is None")
        if token == "":
            raise StringsException("token is empty")
        if str == "":
            return str
        if trim:
            str = str.strip()
        return str.split(token)

    @staticmethod
    def concat(strList, token="", trim=False):
        if strList is None:
            raise StringsException("strList is None")
        if len(strList) == 0:
            raise StringsException("strList is empty")
        result = ""
        for str in strList:
            if trim:
                str = str.strip()
            result += str
            result += token
        result = result[0 : len(result) - len(token)]
        return result

    @staticmethod
    def replace(str, token1="", token2="", trim=False):
        if str is None:
            raise StringsException("str is None")
        if token1 == "":
            raise StringsException("token1 is empty")
        if token2 == "":
            raise StringsException("token2 is empty")
        if len(str) == 0:
            return str
        if trim:
            str = str.strip()
        return str.replace(token1, token2)

class StringsException(Exception):
    pass
