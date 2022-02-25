package getrealgoodutils

import (
	getrealgoodutils "GRG010GoUnitAsAHabit/files"
	"testing"
)

var o = getrealgoodutils.Objects{}

func TestIsNil_Common_Object_bool(t *testing.T) {

	if o.IsNil(string("Hi")) {
		t.Error("string Hi must return false here")
	}
}

func TestIsNil_Special_Objectnil_bool(t *testing.T) {

	if !o.IsNil(nil) {
		t.Error("nil must return true here")
	}
}

func TestIsNotNil_Common_Object_bool(t *testing.T) {

	if !o.IsNotNil(string("Hi")) {
		t.Error("string Hi must return true here")
	}
}

func TestIsNotNil_Special_Objectnil_bool(t *testing.T) {

	if o.IsNotNil(nil) {
		t.Error("nil must return false here")
	}
}
