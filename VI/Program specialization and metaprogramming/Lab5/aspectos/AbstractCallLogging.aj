package aspectos;

public abstract aspect AbstractCallLogging extends AbstractLogging{
	public pointcut loggedMethods() :
		call(* *(..));
}
