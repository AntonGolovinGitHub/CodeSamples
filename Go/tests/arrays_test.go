package getrealgoodutils

import (
	getrealgoodutils "GRG010GoUnitAsAHabit/files"
	"testing"
)

var a = getrealgoodutils.Arrays{}

func TestIsEmpty_Common_stringslc_bool(t *testing.T) {

	var m = []string{"Hello, World!"}

	var result, error = a.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Common_stringslc_bool__1(t *testing.T) {

	var result, error = a.IsEmpty([]string{})

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsEmpty_Special_stringslc_bool(t *testing.T) {

	var m = []string{""}

	var result, error = a.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Special_stringslc_bool__1(t *testing.T) {

	var m = []string{""}

	var result, error = a.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Exceptional_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.IsEmpty(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestIsNotEmpty_Common_stringslc_bool(t *testing.T) {

	var m = []string{"Hello, World!"}

	var result, error = a.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Common_stringslc_bool__1(t *testing.T) {

	var result, error = a.IsNotEmpty([]string{})

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsNotEmpty_Special_stringslc_bool(t *testing.T) {

	var m = []string{""}

	var result, error = a.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Special_stringslc_bool__1(t *testing.T) {

	var m = []string{""}

	var result, error = a.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Exceptional_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.IsNotEmpty(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMax_Common_stringslc_string(t *testing.T) {

	var m []string = []string{"1", "22", "333"}

	var result, error = a.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Nullable_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.Max(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMax_Special_stringslc_string(t *testing.T) {

	var m []string = []string{"1", "22", "333", "", ""}

	var result, error = a.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Special_stringslc_string__1(t *testing.T) {

	var m []string = []string{"", "22", "333", "", ""}

	var result, error = a.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Special_stringslc_string__2(t *testing.T) {

	var m []string = []string{"", "", "", "", ""}

	var result, error = a.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMax_Empty_stringslc_string(t *testing.T) {

	var m []string = []string{}

	var _, error = a.Max(m)

	if error != getrealgoodutils.EmptyError {
		t.Error(error)
	}

}

func TestMin_Common_stringslc_string(t *testing.T) {

	var m []string = []string{"1", "22", "333"}

	var result, error = a.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "1" {
		t.Error("result must be 1")
	}

}

func TestMin_Nullable_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.Min(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMin_Special_stringslc_string(t *testing.T) {

	var m []string = []string{"1", "22", "333", "", ""}

	var result, error = a.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMin_Empty_stringslc_string(t *testing.T) {

	var m []string = []string{}

	var _, error = a.Min(m)

	if error != getrealgoodutils.EmptyError {
		t.Error(error)
	}

}

func TestMin_Special_stringslc_string__1(t *testing.T) {

	var m []string = []string{"", "22", "333", "", ""}

	var result, error = a.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMin_Special_stringslc_string__2(t *testing.T) {

	var m []string = []string{"", "", "", "", ""}

	var result, error = a.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestPeaks_Common_stringslc_stringslc(t *testing.T) {

	var m []string = []string{"1", "22", "333"}

	var result, error = a.Peaks(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 1 {
		t.Error("result must be 1")
	}

	if result[0] != "333" {
		t.Error("result[0] must be 333")
	}

}

func TestPeaks_Nullable_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.Peaks(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestPeaks_Special_stringslc_stringslc(t *testing.T) {

	var m []string = []string{"1", "22", "333", "333"}

	var result, error = a.Peaks(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 2 {
		t.Error("result must be 2")
	}

	if result[0] != "333" {
		t.Error("result[0] must be 333")
	}

	if result[1] != "333" {
		t.Error("result[1] must be 333")
	}

}

func TestPeaks_Special_stringslc_stringslc__1(t *testing.T) {

	var m []string = []string{"1", "22", "333", "333", "1", "", "", "333", "333", "333"}

	var result, error = a.Peaks(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 5 {
		t.Error("result must be 5")
	}

	if result[0] != "333" {
		t.Error("result[0] must be 333")
	}

	if result[1] != "333" {
		t.Error("result[1] must be 333")
	}

	if result[2] != "333" {
		t.Error("result[2] must be 333")
	}

	if result[3] != "333" {
		t.Error("result[3] must be 333")
	}

	if result[4] != "333" {
		t.Error("result[4] must be 333")
	}

}

func TestPeaks_Special_stringslc_stringslc__2(t *testing.T) {

	var m []string = []string{"", "", "", "", ""}

	var result, error = a.Peaks(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 5 {
		t.Error("result must be 5")
	}

	if result[0] != "" {
		t.Error("result[0] must be ''")
	}

	if result[1] != "" {
		t.Error("result[1] must be ''")
	}

	if result[2] != "" {
		t.Error("result[2] must be ''")
	}

	if result[3] != "" {
		t.Error("result[3] must be ''")
	}

	if result[4] != "" {
		t.Error("result[4] must be ''")
	}

}

func TestPeaks_Special_stringslc_stringslc__3(t *testing.T) {

	var m []string = []string{"1", "1", "", "1", ""}

	var result, error = a.Peaks(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 3 {
		t.Error("result must be 3")
	}

	if result[0] != "1" {
		t.Error("result[0] must be '1'")
	}

	if result[1] != "1" {
		t.Error("result[1] must be '1'")
	}

	if result[2] != "1" {
		t.Error("result[2] must be '1'")
	}

}

func TestTroughs_Common_stringslc_stringslc(t *testing.T) {

	var m []string = []string{"1", "22", "333"}

	var result, error = a.Troughs(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 1 {
		t.Error("result must be 1")
	}

	if result[0] != "1" {
		t.Error("result[0] must be 1")
	}

}

func TestTroughs_Nullable_stringslcnil_NilError(t *testing.T) {

	var m []string = nil

	var _, error = a.Troughs(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestTroughs_Special_stringslc_stringslc(t *testing.T) {

	var m []string = []string{"1", "1", "22", "333", "333"}

	var result, error = a.Troughs(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 2 {
		t.Error("result must be 2")
	}

	if result[0] != "1" {
		t.Error("result[0] must be 1")
	}

	if result[1] != "1" {
		t.Error("result[1] must be 1")
	}

}

func TestTroughs_Special_stringslc_stringslc__1(t *testing.T) {

	var m []string = []string{"333", "22", "1", "1", "1", "333", "333", "77", "1", "1"}

	var result, error = a.Troughs(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 5 {
		t.Error("result must be 5")
	}

	if result[0] != "1" {
		t.Error("result[0] must be 1")
	}

	if result[1] != "1" {
		t.Error("result[1] must be 1")
	}

	if result[2] != "1" {
		t.Error("result[2] must be 1")
	}

	if result[3] != "1" {
		t.Error("result[3] must be 1")
	}

	if result[4] != "1" {
		t.Error("result[4] must be 1")
	}

}

func TestTroughs_Special_stringslc_stringslc__2(t *testing.T) {

	var m []string = []string{"", "", "", "", ""}

	var result, error = a.Troughs(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 5 {
		t.Error("result must be 5")
	}

	if result[0] != "" {
		t.Error("result[0] must be ''")
	}

	if result[1] != "" {
		t.Error("result[1] must be ''")
	}

	if result[2] != "" {
		t.Error("result[2] must be ''")
	}

	if result[3] != "" {
		t.Error("result[3] must be ''")
	}

	if result[4] != "" {
		t.Error("result[4] must be ''")
	}

}

func TestTroughs_Special_stringslc_stringslc__3(t *testing.T) {

	var m []string = []string{"", "", "333", "", "333"}

	var result, error = a.Troughs(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if len(result) != 3 {
		t.Error("result must be 3")
	}

	if result[0] != "" {
		t.Error("result[0] must be ''")
	}

	if result[1] != "" {
		t.Error("result[1] must be ''")
	}

	if result[2] != "" {
		t.Error("result[2] must be ''")
	}

}
