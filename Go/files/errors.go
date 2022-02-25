package getrealgoodutils

type GetRealGoodUtilsErrors int

const (
	NoError GetRealGoodUtilsErrors = iota
	NilError
	EmptyError
	NoopError
	PositiveOverflowError
	NegativeOverflowError
	DivisionByZeroError
)
