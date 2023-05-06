package aspectos;

public aspect SystemValidate {
    pointcut setPrivateAttributes() : 
    	set(private * *) 
		&& !withincode(* set*(..)) 
		&& !withincode(*.new(..)) 
		&& !withincode(* contas.RepositorioContas.*(..)) 
		&& !withincode(* contas.RepositorioContasArray.*(..))
		&& !withincode(* contas.RepositorioContasLista.*(..));
    
    before() : setPrivateAttributes() {
        System.out.println("Warning: Attempt to change private attribute outside set method detected.");
    }
}