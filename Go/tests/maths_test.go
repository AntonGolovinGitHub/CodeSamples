package getrealgoodutils

import (
	getrealgoodutils "GRG010GoUnitAsAHabit/files"
	"math"
	"testing"
)

var m = getrealgoodutils.Maths{}

func TestSum_Common_int64_int64(t *testing.T) {

	var result, error = m.SumInt64(10, 10, 10, 10, 10, 10, 10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 70 {
		t.Error("result must be 70")
	}

}
func TestSum_Common_int64_int64__1(t *testing.T) {

	var result, error = m.SumInt64(10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 10 {
		t.Error("result must be 10")
	}

}

func TestSum_Exceptional_int64_PositiveOverflowError(t *testing.T) {

	var _, error = m.SumInt64(math.MaxInt64, math.MaxInt64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestSum_Exceptional_int64_NegativeOverflowError(t *testing.T) {

	var _, error = m.SumInt64(math.MinInt64, math.MinInt64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestSum_Special_int64_int64(t *testing.T) {

	var result, error = m.SumInt64(0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestSum_Nullable_int64_NilError(t *testing.T) {

	var _, error = m.SumInt64()

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestSum_Common_float64_float64(t *testing.T) {

	var result, error = m.SumFloat64(10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 70.0 {
		t.Error("result must be 70.0")
	}

}
func TestSum_Common_float64_float64__1(t *testing.T) {

	var result, error = m.SumFloat64(10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 10.0 {
		t.Error("result must be 10.0")
	}

}

func TestSum_Exceptional_float64_PositiveOverflowError(t *testing.T) {

	var _, error = m.SumFloat64(math.MaxFloat64, math.MaxFloat64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestSum_Exceptional_Float64_NegativeOverflowError(t *testing.T) {

	var _, error = m.SumFloat64(-math.MaxFloat64, -math.MaxFloat64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestSum_Special_float64_float64(t *testing.T) {

	var result, error = m.SumFloat64(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0.0 {
		t.Error("result must be 0.0")
	}

}

func TestSum_Nullable_float64_NilError(t *testing.T) {

	var _, error = m.SumFloat64()

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestSubtract_Common_int64_int64_int64(t *testing.T) {

	var result, error = m.SubtractInt64(10, 10, 10, 10, 10, 10, 10, 10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != -60 {
		t.Error("result must be -60")
	}

}
func TestSubtract_Common_int64_int64_int64__1(t *testing.T) {

	var result, error = m.SubtractFloat64(10, 10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestSubtract_Exceptional_int64_int64_int64(t *testing.T) {

	var result, error = m.SubtractInt64(math.MaxInt64, math.MaxInt64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestSubtract_Exceptional_int64_int64_int64__1(t *testing.T) {

	var result, error = m.SubtractFloat64(math.MinInt64, math.MinInt64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestSubtract_Special_int64_int64_int64(t *testing.T) {

	var result, error = m.SubtractInt64(0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestSubtract_Nullable_int64_int64_NilError(t *testing.T) {

	var _, error = m.SubtractInt64(10)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestSubtract_Exceptional_int64_int64_PositiveOverflowError(t *testing.T) {

	var _, error = m.SubtractInt64(math.MaxInt64, math.MinInt64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestSubtract_Exceptional_int64_int64_PositiveOverflowError__1(t *testing.T) {

	var _, error = m.SubtractInt64(math.MaxInt64, math.MinInt64, math.MinInt64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestSubtract_Common_float64_float64_float64(t *testing.T) {

	var result, error = m.SubtractFloat64(10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != -50.0 {
		t.Error("result must be -50.0")
	}

}
func TestSubtract_Common_float64_float64_float64__1(t *testing.T) {

	var _, error = m.SubtractFloat64(10.0)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestSubtract_Exceptional_float64_float64_PositiveOverflowError(t *testing.T) {

	var result, error = m.SubtractFloat64(math.MaxFloat64, math.MaxFloat64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0.0 {
		t.Error("result must be 0.0")
	}

}

func TestSubtract_Exceptional_float64_float64_NegativeOverflowError(t *testing.T) {

	var _, error = m.SubtractFloat64(0, math.MaxFloat64, math.MaxFloat64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestSubtract_Special_float64_float64_float64(t *testing.T) {

	var result, error = m.SubtractFloat64(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0.0 {
		t.Error("result must be 0.0")
	}

}

func TestSubtract_Nullable_float64_float64_NilError(t *testing.T) {

	var _, error = m.SubtractFloat64(0)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestMultiply_Common_int64_int64(t *testing.T) {

	var result, error = m.MultiplyInt64(10, 10, 10, 10, 10, 10, 10, 10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100000000 {
		t.Error("result must be 100000000")
	}

}

func TestMultiply_Common_int64_int64__1(t *testing.T) {

	var result, error = m.MultiplyInt64(10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 10 {
		t.Error("result must be 10")
	}

}

func TestMultiply_Exceptional_int64_PositiveOverflowError(t *testing.T) {

	var _, error = m.MultiplyInt64(math.MaxInt64, math.MaxInt64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestMultiply_Exceptional_int64_NegativeOverflowError(t *testing.T) {

	var _, error = m.MultiplyInt64(math.MaxInt64, math.MinInt64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestMultiply_Special_int64_int64(t *testing.T) {

	var result, error = m.MultiplyInt64(0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestMultiply_Common_float64_float64(t *testing.T) {

	var result, error = m.MultiplyFloat64(10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100000000.0 {
		t.Error("result must be 100000000.0")
	}

}

func TestMultiply_Common_float64_float64__1(t *testing.T) {

	var result, error = m.MultiplyFloat64(10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 10.0 {
		t.Error("result must be 10.0")
	}

}

func TestMultiply_Exceptional_float64_PositiveOverflowError(t *testing.T) {

	var _, error = m.MultiplyFloat64(math.MaxFloat64, math.MaxFloat64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestMultiply_Exceptional_float64_NegativeOverflowError(t *testing.T) {

	var _, error = m.MultiplyFloat64(math.MaxFloat64, -math.MaxFloat64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestMultiply_Special_float64_float64(t *testing.T) {

	var result, error = m.MultiplyFloat64(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0.0 {
		t.Error("result must be 0.0")
	}

}

func TestDivide_Common_int64_int64_int64(t *testing.T) {

	var result, error = m.DivideInt64(10, 10, 10, 10, 10, 10, 10, 10)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestDivide_Common_int64_int64_int64__1(t *testing.T) {

	var _, error = m.DivideInt64(10)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestDivide_Corner_int64_int64_int64(t *testing.T) {

	var result, error = m.DivideInt64(math.MaxInt64, math.MaxInt64, math.MaxInt64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestDivide_Corner_int64_int64_int64__1(t *testing.T) {

	var result, error = m.DivideInt64(math.MaxInt64, math.MaxInt64, math.MinInt64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestDivide_Special_int64_int64_int64(t *testing.T) {

	var _, error = m.DivideInt64(0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.DivisionByZeroError {
		t.Error(error)
	}

}

func TestDivide_Common_float64_float64_float64(t *testing.T) {

	var result, error = m.DivideFloat64(10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0.0000010000000000000002 { // weird but true
		t.Error("result must be 0.0000010000000000000002")
	}

}

func TestDivide_Common_float64_float64_float64__1(t *testing.T) {

	var _, error = m.DivideFloat64(10)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestDivide_Corner_float64_float64_float64(t *testing.T) {

	var result, error = m.DivideFloat64(math.MaxFloat64, math.MaxFloat64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 1.0 {
		t.Error("result must be 1.0")
	}

}

func TestDivide_Corner_float64_float64_float64__1(t *testing.T) {

	var result, error = m.DivideInt64(math.MaxInt64, math.MaxInt64, math.MinInt64)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 0 {
		t.Error("result must be 0")
	}

}

func TestDivide_Special_float64_float64_float64(t *testing.T) {

	var _, error = m.DivideFloat64(0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.DivisionByZeroError {
		t.Error(error)
	}

}

func TestDivide_Exceptional_float64_float64_float64(t *testing.T) {

	var _, error = m.DivideFloat64(math.MaxFloat64, math.SmallestNonzeroFloat64)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestDivide_Exceptional_float64_float64_float64__1(t *testing.T) {

	var _, error = m.DivideFloat64(-math.MaxFloat64, math.SmallestNonzeroFloat64)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Common_int64_int64_int64(t *testing.T) {

	var result, error = m.PowerOfInt64(10, 2, 1, 1, 1, 1, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100000000 {
		t.Error("result must be 100000000")
	}

}

func TestPowerOf_Common_int64_int64_int64__1(t *testing.T) {

	var result, error = m.PowerOfInt64(10, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100 {
		t.Error("result must be 100")
	}

}

func TestPowerOf_Exceptional_int64_int64_PositiveOverflowError(t *testing.T) {

	var _, error = m.PowerOfInt64(math.MaxInt64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_int64_int64_PositiveOverflowError__1(t *testing.T) {

	var _, error = m.PowerOfInt64(math.MinInt64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_int64_int64_PositiveOverflowError__2(t *testing.T) {

	var _, error = m.PowerOfInt64(-2, 65)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Special_int64_int64_int64(t *testing.T) {

	var result, error = m.PowerOfInt64(10, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 1 {
		t.Error("result must be 1")
	}

}

func TestPowerOf_Common_float64_int64_float64(t *testing.T) {

	var result, error = m.PowerOfFloat64Int64(10, 2, 1, 1, 1, 1, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100000000.0 {
		t.Error("result must be 100000000.0")
	}

}

func TestPowerOf_Common_float64_int64_float64__1(t *testing.T) {

	var result, error = m.PowerOfFloat64Int64(10.0, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100.0 {
		t.Error("result must be 100.0")
	}

}

func TestPowerOf_Exceptional_float64_int64_PositiveOverflowError(t *testing.T) {

	var _, error = m.PowerOfFloat64Int64(math.MaxFloat64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_float64_int64_PositiveOverflowError__1(t *testing.T) {

	var _, error = m.PowerOfFloat64Int64(-math.MaxFloat64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_float64_int64_PositiveOverflowError__2(t *testing.T) {

	var _, error = m.PowerOfFloat64Int64(2.5, 1000)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Special_float64_int64_float64(t *testing.T) {

	var result, error = m.PowerOfFloat64Int64(10.0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 1.0 {
		t.Error("result must be 1.0")
	}

}

func TestPowerOf_Common_float64_float64_float64(t *testing.T) {

	var result, error = m.PowerOfFloat64Float64(10, 2, 1, 1, 1, 1, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100000000.0 {
		t.Error("result must be 100000000.0")
	}

}

func TestPowerOf_Common_float64_float64_float64__1(t *testing.T) {

	var result, error = m.PowerOfFloat64Float64(10.0, 2)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 100.0 {
		t.Error("result must be 100.0")
	}

}

func TestPowerOf_Exceptional_float64_float64_PositiveOverflowError(t *testing.T) {

	var _, error = m.PowerOfFloat64Float64(math.MaxFloat64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_float64_float64_PositiveOverflowError__1(t *testing.T) {

	var _, error = m.PowerOfFloat64Float64(-math.MaxFloat64, 2)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Exceptional_float64_float64_PositiveOverflowError__2(t *testing.T) {

	var _, error = m.PowerOfFloat64Float64(2.5, 1000)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestPowerOf_Special_float64_float64_float64(t *testing.T) {

	var result, error = m.PowerOfFloat64Float64(10.0, 0, 0, 0, 0, 0, 0, 0)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != 1.0 {
		t.Error("result must be 1.0")
	}

}

func TestQuadratic_Common_float64_float64_float64_float64(t *testing.T) {

	var a float64 = 10
	var b float64 = 10
	var c float64 = -10

	var result, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result[0] != 0.6180339887498949 {
		t.Error("result must be 0.6180339887498949")
	}

	if result[1] != -1.618033988749895 {
		t.Error("result must be -1.618033988749895")
	}

}

func TestQuadratic_Special_float64_float64_float64_float64(t *testing.T) {

	var a float64 = 1
	var b float64 = 0
	var c float64 = -4

	var result, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result[0] != 2 {
		t.Error("result must be 0.6180339887498949")
	}

	if result[1] != -2 {
		t.Error("result must be -1.618033988749895")
	}

}

func TestQuadratic_Special_float64_float64_float64_float64__1(t *testing.T) {

	var a float64 = 1
	var b float64 = 2
	var c float64 = 0

	var result, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result[0] != 0 {
		t.Error("result must be 0.6180339887498949")
	}

	if result[1] != -2 {
		t.Error("result must be -1.618033988749895")
	}

}

func TestQuadratic_Special_float64_float64_float64_float64__2(t *testing.T) {

	var a float64 = 1
	var b float64 = 0
	var c float64 = 0

	var result, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result[0] != 0 {
		t.Error("result must be 0.6180339887498949")
	}

}

func TestQuadratic_Special_float64_float64_float64_float64__3(t *testing.T) {

	var a float64 = 0
	var b float64 = 0
	var c float64 = 0

	var _, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NilError {
		t.Error(error)
	}

}

func TestQuadratic_Exceptional_float64_float64_float64_PositiveOverflowError(t *testing.T) {

	var a float64 = math.MaxFloat64
	var b float64 = math.MaxFloat64
	var c float64 = -math.MaxFloat64

	var _, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestQuadratic_Exceptional_float64_float64_float64_NegativeOverflowError(t *testing.T) {

	var a float64 = -math.MaxFloat64
	var b float64 = -math.MaxFloat64
	var c float64 = math.MaxFloat64

	var _, error = m.Quadratic(a, b, c)

	if error != getrealgoodutils.NegativeOverflowError {
		t.Error(error)
	}

}

func TestHypotenuse_Common_float64_float64_float64(t *testing.T) {

	var nearLine float64 = 3
	var farLine float64 = 1

	var result, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoError {
		t.Error(error)
	}

	if result != math.Sqrt(10) {
		t.Error("Must be square root of 10")
	}

}

func TestHypotenuse_Special_float64_float64_float64(t *testing.T) {

	var nearLine float64 = 0
	var farLine float64 = 1

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoopError {
		t.Error(error)
	}

}

func TestHypotenuse_Special_float64_float64_float64__1(t *testing.T) {

	var nearLine float64 = 1
	var farLine float64 = 0

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoopError {
		t.Error(error)
	}

}

func TestHypotenuse_Special_float64_float64_float64__2(t *testing.T) {

	var nearLine float64 = -1
	var farLine float64 = 100

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoopError {
		t.Error(error)
	}

}

func TestHypotenuse_Special_float64_float64_float64__3(t *testing.T) {

	var nearLine float64 = 100
	var farLine float64 = -1

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoopError {
		t.Error(error)
	}

}

func TestHypotenuse_Exceptional_float64_float64_float64(t *testing.T) {

	var nearLine float64 = math.MaxFloat64
	var farLine float64 = math.MaxFloat64

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.PositiveOverflowError {
		t.Error(error)
	}

}

func TestHypotenuse_Exceptional_float64_float64_float64__1(t *testing.T) {

	var nearLine float64 = -math.MaxFloat64
	var farLine float64 = math.MaxFloat64

	var _, error = m.Hypotenuse(nearLine, farLine)

	if error != getrealgoodutils.NoopError {
		t.Error(error)
	}

}
