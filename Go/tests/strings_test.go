package getrealgoodutils

import (
	getrealgoodutils "GRG010GoUnitAsAHabit/files"
	"testing"
)

var s = getrealgoodutils.Strings{}

func TestToUpper_Common_string_string(t *testing.T) {

	var str string = "Hello, World!"

	var result, error = s.ToUpper(str)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToUpper(str)")
	}

	if result != "HELLO, WORLD!" {
		t.Error("Must equal HELLO, WORLD")
	}

}

func TestToUpper_Empty_string_string(t *testing.T) {

	var str string = ""

	var result, error = s.ToUpper(str)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToUpper(str)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestToUpperBatch_Common_stringslc_string(t *testing.T) {

	var strs []string = []string{"Hello, World!", "Hello, World!"}

	var result, error = s.ToUpperBatch(strs)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToUpperBatch(str)")
	}

	if result[0] != "HELLO, WORLD!" {
		t.Error("Must equal HELLO, WORLD!")
	}

	if result[1] != "HELLO, WORLD!" {
		t.Error("Must equal HELLO, WORLD!")
	}

}

func TestToUpperBatch_Empty_stringslc_string(t *testing.T) {

	var strs []string = []string{"", "Hello, World!"}

	var result, error = s.ToUpperBatch(strs)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToUpperBatch(str)")
	}

	if result[0] != "" {
		t.Error("Must equal empty string")
	}

	if result[1] != "HELLO, WORLD!" {
		t.Error("Must equal HELLO, WORLD!")
	}

}

func TestToUpperBatch_Empty_stringslc_string__1(t *testing.T) {

	var strs []string = []string{}

	var result, error = s.ToUpperBatch(strs)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from ToUpperBatch(str)")
	}

	if len(result) != 0 {
		t.Error("Must equal 0")
	}

}

func TestToUpperBatch_Nullable_stringslcnil_string(t *testing.T) {

	var strs []string = nil

	var result, error = s.ToUpperBatch(strs)

	if error != getrealgoodutils.NilError {
		t.Error("NilError must be returned from ToUpperBatch(str)")
	}

	if result != nil {
		t.Error("Must equal nil")
	}

}

func TestToLower_Common_string_string(t *testing.T) {

	var str string = "Hello, World!"

	var result, error = s.ToLower(str)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToLower(str)")
	}

	if result != "HELLO, WORLD!" {
		t.Error("Must equal hello, world!")
	}

}

func TestToLower_Empty_string_string(t *testing.T) {

	var str string = ""

	var result, error = s.ToLower(str)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToLower(str)")
	}

	if result != "" {
		t.Error("Must equal empty string!")
	}

}

func TestToLowerBatch_Common_stringslc_string(t *testing.T) {

	var strs []string = []string{"Hello, World!", "Hello, World!"}

	var result, error = s.ToLowerBatch(strs)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToLowerBatch(str)")
	}

	if result[0] != "hello, world!" {
		t.Error("Must equal hello, world!")
	}

	if result[1] != "hello, world!" {
		t.Error("Must equal hello, world!")
	}

}

func TestToLowerBatch_Empty_stringslc_string(t *testing.T) {

	var strs []string = []string{"", "Hello, World!"}

	var result, error = s.ToLowerBatch(strs)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from ToLowerBatch(str)")
	}

	if result[0] != "" {
		t.Error("Must equal empty string")
	}

	if result[1] != "hello, world!" {
		t.Error("Must equal hello, world!")
	}

}
func TestToLowerBatch_Empty_stringslc_string__1(t *testing.T) {

	var strs []string = []string{}

	var result, error = s.ToLowerBatch(strs)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from ToLowerBatch(str)")
	}

	if len(result) != 0 {
		t.Error("Must equal 0")
	}

}

func TestToLowerBatch_Nullable_stringslcnil_string(t *testing.T) {

	var strs []string = nil

	var result, error = s.ToLowerBatch(strs)

	if error != getrealgoodutils.NilError {
		t.Error("NilError must be returned from ToLowerBatch(str)")
	}

	if result != nil {
		t.Error("Must equal nil")
	}

}

func TestSplit_Common_string_string_bool_string(t *testing.T) {

	var str string = "Hi, how are you?"
	var token string = " "

	var result, error = s.Split(str, token, false)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Split(str, token, false)")
	}

	if len(result) != 4 {
		t.Error("len(result) equals 4")
	}

	if result[0] != "Hi," {
		t.Error("Must equal Hi,")
	}

	if result[1] != "how" {
		t.Error("Must equal how")
	}

	if result[2] != "are" {
		t.Error("Must equal are")
	}

	if result[3] != "you?" {
		t.Error("Must equal you?")
	}

}

func TestSplit_Common_string_string_bool_string__1(t *testing.T) {

	var str string = "Hi, how are you?"
	var token string = " "

	var result, error = s.Split(str, token, true)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Split(str, token, false)")
	}

	if len(result) != 4 {
		t.Error("len(result) equals 4")
	}

	if result[0] != "Hi," {
		t.Error("Must equal Hi,")
	}

	if result[1] != "how" {
		t.Error("Must equal how")
	}

	if result[2] != "are" {
		t.Error("Must equal are")
	}

	if result[3] != "you?" {
		t.Error("Must equal you?")
	}

}

func TestSplit_Common_string_string_bool_string__2(t *testing.T) {

	var str string = " Hi, how are you? "
	var token string = " "

	var result, error = s.Split(str, token, true)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Split(str, token, false)")
	}

	if len(result) != 4 {
		t.Error("len(result) equals 4")
	}

	if result[0] != "Hi," {
		t.Error("Must equal Hi,")
	}

	if result[1] != "how" {
		t.Error("Must equal how")
	}

	if result[2] != "are" {
		t.Error("Must equal are")
	}

	if result[3] != "you?" {
		t.Error("Must equal you?")
	}

}

func TestSplit_Empty_string_string_bool_string(t *testing.T) {

	var str string = ""
	var token string = " "

	var result, error = s.Split(str, token, false)

	if error != getrealgoodutils.EmptyError {
		t.Error("Must return EmptyError from Split(str, token, false)")
	}

	if len(result) != 0 {
		t.Error("len(result) equals 1")
	}

}

func TestSplit_Empty_string_string_bool_string__1(t *testing.T) {

	var str string = ""
	var token string = " "

	var result, error = s.Split(str, token, true)

	if error != getrealgoodutils.EmptyError {
		t.Error("Must return EmptyError from Split(str, token, false)")
	}

	if len(result) != 0 {
		t.Error("len(result) equals 1")
	}

}

func TestSplit_Empty_string_string_bool_string__2(t *testing.T) {

	var str string = " "
	var token string = " "

	var result, error = s.Split(str, token, true)

	if error != getrealgoodutils.EmptyError {
		t.Error("Must return EmptyError from Split(str, token, false)")
	}

	if len(result) != 0 {
		t.Error("len(result) equals 1")
	}

}

func TestConcat_Common_stringslc_string_bool_string(t *testing.T) {

	var strs []string = []string{"Hi,", "how", "are", "you?"}
	var token string = " "

	var result, error = s.Concat(strs, token, false)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Concat(strs, token, false)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestConcat_Common_stringslc_string_bool_string__1(t *testing.T) {

	var strs []string = []string{"Hi,", "how", "are", "you?"}
	var token string = " "

	var result, error = s.Concat(strs, token, true)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Concat(strs, token, true)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestConcat_Common_stringslc_string_bool_string__2(t *testing.T) {

	var strs []string = []string{"Hi,", "how", "are", "you? "}
	var token string = " "

	var result, error = s.Concat(strs, token, true)

	if error != getrealgoodutils.NoError {
		t.Error("Error returned from Concat(strs, token, true)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestConcat_Empty_stringslc_string_bool_EmptyError(t *testing.T) {

	var strs []string = []string{}
	var token string = " "

	var result, error = s.Concat(strs, token, false)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from Concat(strs, token, false)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestConcat_Empty_stringslc_string_bool_EmptyError__1(t *testing.T) {

	var strs []string = []string{}
	var token string = " "

	var result, error = s.Concat(strs, token, true)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from Concat(strs, token, true)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestConcat_Nullable_stringslcnil_string_bool_NilError(t *testing.T) {

	var strs []string = nil
	var token string = " "

	var result, error = s.Concat(strs, token, false)

	if error != getrealgoodutils.NilError {
		t.Error("NilError must be returned from Concat(strs, token, false)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestConcat_Nullable_stringslcnil_string_bool_NilError__1(t *testing.T) {

	var strs []string = nil
	var token string = " "

	var result, error = s.Concat(strs, token, true)

	if error != getrealgoodutils.NilError {
		t.Error("NilError must be returned from Concat(strs, token, true)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestReplace_Common_string_string_string_bool_string(t *testing.T) {

	var str string = "Hello, World!"
	var token1 string = "H"
	var token2 string = "C"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Cello, World!" {
		t.Error("Must equal Cello, World!")
	}

}

func TestReplace_Common_string_string_string_bool_string__1(t *testing.T) {

	var str string = "Hello, World! "
	var token1 string = "H"
	var token2 string = "C"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Cello, World! " {
		t.Error("Must equal Cello, World! ")
	}

}

func TestReplace_Common_string_string_string_bool_string__2(t *testing.T) {

	var str string = "Hello, World! "
	var token1 string = "H"
	var token2 string = "C"

	var result, error = s.Replace(str, token1, token2, true)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, true)")
	}

	if result != "Cello, World!" {
		t.Error("Must equal Cello, World!")
	}

}

func TestReplace_Empty_string_string_string_bool_string(t *testing.T) {

	var str string = ""
	var token1 string = "H"
	var token2 string = "C"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}

func TestReplace_Empty_string_string_string_bool_string__1(t *testing.T) {

	var str string = "Hi, how are you?"
	var token1 string = "z"
	var token2 string = "c"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestReplace_Empty_string_string_string_bool_string__2(t *testing.T) {

	var str string = "Hi, how are you?"
	var token1 string = ""
	var token2 string = "c"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoopError {
		t.Error("NoopError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestReplace_Empty_string_string_string_bool_string__3(t *testing.T) {

	var str string = "Hi, how are you?"
	var token1 string = "z"
	var token2 string = ""

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoopError {
		t.Error("NoopError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Hi, how are you?" {
		t.Error("Must equal Hi, how are you?")
	}

}

func TestReplace_Empty_string_string_string_bool_string__4(t *testing.T) {

	var str string = " Hi, how are you?  "
	var token1 string = "H"
	var token2 string = "T"

	var result, error = s.Replace(str, token1, token2, false)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, false)")
	}

	if result != " Ti, how are you?  " {
		t.Error("Must equal  Ti, how are you?  ")
	}

}

func TestReplace_Empty_string_string_string_bool_string__5(t *testing.T) {

	var str string = " Hi, how are you?  "
	var token1 string = "H"
	var token2 string = "T"

	var result, error = s.Replace(str, token1, token2, true)

	if error != getrealgoodutils.NoError {
		t.Error("NoError must be returned from Replace(str, token1, token2, false)")
	}

	if result != "Ti, how are you?" {
		t.Error("Must equal Ti, how are you?")
	}

}

func TestReplace_Empty_string_string_string_bool_string__6(t *testing.T) {

	var str string = " "
	var token1 string = "H"
	var token2 string = "T"

	var result, error = s.Replace(str, token1, token2, true)

	if error != getrealgoodutils.EmptyError {
		t.Error("EmptyError must be returned from Replace(str, token1, token2, true)")
	}

	if result != "" {
		t.Error("Must equal empty string")
	}

}
