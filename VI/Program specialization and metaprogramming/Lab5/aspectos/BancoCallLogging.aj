package aspectos;

public aspect BancoCallLogging extends AbstractCallLogging{
	public pointcut loggedMethods() :
		call(* *(..)) && (within(contas..*) || within(fachada..*) || within(gui..*));
}
