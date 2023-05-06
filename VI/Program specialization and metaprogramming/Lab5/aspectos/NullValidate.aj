package aspectos;

public aspect NullValidate {
	before(Object value, Object t): call(* *(..)) && args(value) && target(t){
		if (value == null || t == null) {
            throw new IllegalArgumentException("Invalid null reference detected.");
        }
	}
}
