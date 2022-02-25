package getrealgoodutils

import (
	getrealgoodutils "GRG010GoUnitAsAHabit/files"
	"testing"
)

var c = getrealgoodutils.Collections{}

func TestIsEmpty_Common_map_bool(t *testing.T) {

	var m = map[int]string{1: "Hello, World!"}

	var result, error = c.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Common_map_bool__1(t *testing.T) {

	var result, error = c.IsEmpty(make(map[int]string))

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsEmpty_Special_map_bool(t *testing.T) {

	var m = map[int]string{1: ""}

	var result, error = c.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Special_map_bool__1(t *testing.T) {

	var m = map[int]string{0: ""}

	var result, error = c.IsEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsEmpty_Exceptional_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.IsEmpty(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestIsNotEmpty_Common_map_bool(t *testing.T) {

	var m = map[int]string{1: "Hello, World!"}

	var result, error = c.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Common_map_bool__1(t *testing.T) {

	var result, error = c.IsNotEmpty(make(map[int]string))

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != false {
		t.Error("result must be false")
	}

}

func TestIsNotEmpty_Special_map_bool(t *testing.T) {

	var m = map[int]string{1: ""}

	var result, error = c.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Special_map_bool__1(t *testing.T) {

	var m = map[int]string{0: ""}

	var result, error = c.IsNotEmpty(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != true {
		t.Error("result must be true")
	}

}

func TestIsNotEmpty_Exceptional_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.IsNotEmpty(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMax_Common_map_string(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333"}

	var result, error = c.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Nullable_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.Max(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMax_Special_map_string(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333", 4: "", 5: ""}

	var result, error = c.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Special_map_string__1(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "22", 3: "333", 4: "", 5: ""}

	var result, error = c.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "333" {
		t.Error("result must be 333")
	}

}

func TestMax_Special_map_string__2(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "", 3: "", 4: "", 5: ""}

	var result, error = c.Max(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMax_Empty_map_string(t *testing.T) {

	var m map[int]string = map[int]string{}

	var _, error = c.Max(m)

	if error != getrealgoodutils.EmptyError {
		t.Error(error)
	}

}

func TestMin_Common_map_string(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333"}

	var result, error = c.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "1" {
		t.Error("result must be 1")
	}

}

func TestMin_Nullable_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.Min(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMin_Special_map_string(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333", 4: "", 5: ""}

	var result, error = c.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMin_Empty_map_string(t *testing.T) {

	var m map[int]string = map[int]string{}

	var _, error = c.Min(m)

	if error != getrealgoodutils.EmptyError {
		t.Error(error)
	}

}

func TestMin_Special_map_string__1(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "22", 3: "333", 4: "", 5: ""}

	var result, error = c.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestMin_Special_map_string__2(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "", 3: "", 4: "", 5: ""}

	var result, error = c.Min(m)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != "" {
		t.Error("result must be ''")
	}

}

func TestPeaks_Common_map_stringslc(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333"}

	var result, error = c.Peaks(m)

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

func TestPeaks_Nullable_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.Peaks(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestPeaks_Special_map_stringslc(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333", 4: "333"}

	var result, error = c.Peaks(m)

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

func TestPeaks_Special_map_stringslc__1(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333", 4: "333", 5: "1", 6: "", 7: "", 8: "333", 9: "333", 10: "333"}

	var result, error = c.Peaks(m)

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

func TestPeaks_Special_map_stringslc__2(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "", 3: "", 4: "", 5: ""}

	var result, error = c.Peaks(m)

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

func TestPeaks_Special_map_stringslc__3(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "1", 3: "", 4: "1", 5: ""}

	var result, error = c.Peaks(m)

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

func TestTroughs_Common_map_stringslc(t *testing.T) {

	var m map[int]string = map[int]string{1: "1", 2: "22", 3: "333"}

	var result, error = c.Troughs(m)

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

func TestTroughs_Nullable_mapnil_NilError(t *testing.T) {

	var m map[int]string = nil

	var _, error = c.Troughs(m)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestTroughs_Special_map_stringslc(t *testing.T) {

	var m map[int]string = map[int]string{0: "1", 1: "1", 2: "22", 3: "333", 4: "333"}

	var result, error = c.Troughs(m)

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

func TestTroughs_Special_map_stringslc__1(t *testing.T) {

	var m map[int]string = map[int]string{1: "333", 2: "22", 3: "1", 4: "1", 5: "1", 6: "333", 7: "333", 8: "77", 9: "1", 10: "1"}

	var result, error = c.Troughs(m)

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

func TestTroughs_Special_map_stringslc__2(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "", 3: "", 4: "", 5: ""}

	var result, error = c.Troughs(m)

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

func TestTroughs_Special_map_stringslc__3(t *testing.T) {

	var m map[int]string = map[int]string{1: "", 2: "", 3: "333", 4: "", 5: "333"}

	var result, error = c.Troughs(m)

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
