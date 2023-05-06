package aspectos;

public abstract aspect AbstractLogging {
	public abstract pointcut loggedMethods();

	before(): loggedMethods() {
		System.out.println(thisJoinPoint);
	}
	
	after(): loggedMethods() {
		System.out.println(thisJoinPoint);
	}
}
