package getrealgoodutils

import (
	"strings"
)

type Strings struct {
	errors GetRealGoodUtilsErrors
}

func (s *Strings) ToUpper(str string) (string, GetRealGoodUtilsErrors) {

	return strings.ToUpper(str), GetRealGoodUtilsErrors(NoError)

}

func (s *Strings) ToUpperBatch(str []string) ([]string, GetRealGoodUtilsErrors) {

	if str == nil {
		return nil, GetRealGoodUtilsErrors(NilError)
	}

	if len(str) == 0 {
		return str, GetRealGoodUtilsErrors(EmptyError)
	}

	for i, o := range str {

		str[i] = strings.ToUpper(o)
	}

	return str, GetRealGoodUtilsErrors(NoError)

}

func (s *Strings) ToLower(str string) (string, GetRealGoodUtilsErrors) {

	return strings.ToUpper(str), GetRealGoodUtilsErrors(NoError)

}

func (s *Strings) ToLowerBatch(str []string) ([]string, GetRealGoodUtilsErrors) {

	if str == nil {
		return nil, GetRealGoodUtilsErrors(NilError)
	}

	if len(str) == 0 {
		return str, GetRealGoodUtilsErrors(EmptyError)
	}

	for i, o := range str {
		str[i] = strings.ToLower(o)
	}

	return str, GetRealGoodUtilsErrors(NoError)

}

func (s *Strings) Split(str string, token string, trim bool) ([]string, GetRealGoodUtilsErrors) {

	if trim {
		str = strings.TrimSpace(str)
	}

	if len(str) == 0 {
		return []string{}, GetRealGoodUtilsErrors(EmptyError)
	}

	var strs []string = strings.Split(str, token)

	if trim {
		for i, _ := range strs {
			strs[i] = strings.TrimSpace(strs[i])
		}
	}

	return strs, GetRealGoodUtilsErrors(NoError)

}

func (s *Strings) Concat(strs []string, token string, trim bool) (string, GetRealGoodUtilsErrors) {

	if strs == nil {
		return "", GetRealGoodUtilsErrors(NilError)
	}

	if len(strs) == 0 {
		return "", GetRealGoodUtilsErrors(EmptyError)
	}

	var str string = ""

	for i, v := range strs {
		if trim {
			v = strings.TrimSpace(v)
		}
		str += v
		if i != len(strs)-1 {
			str += token
		}
	}

	return str, GetRealGoodUtilsErrors(NoError)
}

func (s *Strings) Replace(str string, token string, token2 string, trim bool) (string, GetRealGoodUtilsErrors) {

	if len(str) == 0 {
		return str, GetRealGoodUtilsErrors(EmptyError)
	}

	if len(token) == 0 {
		return str, GetRealGoodUtilsErrors(NoopError)
	}

	if len(token2) == 0 {
		return str, GetRealGoodUtilsErrors(NoopError)
	}

	if trim {
		str = strings.TrimSpace(str)
	}

	if len(str) == 0 {
		return str, GetRealGoodUtilsErrors(EmptyError)
	}

	str = strings.Replace(str, token, token2, -1)

	return str, GetRealGoodUtilsErrors(NoError)

}
