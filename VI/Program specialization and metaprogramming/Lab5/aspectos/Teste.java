package aspectos;

import contas.Conta;

/**
 * @author scbs
 *
 * To change this generated comment edit the template variable "typecomment":
 * Window>Preferences>Java>Templates.
 * To enable and disable the creation of type comments go to
 * Window>Preferences>Java>Code Generation.
 */
public aspect Teste {

	public pointcut creditarCalls(): 
	    call(void Conta.creditar(double));

	before(): creditarCalls() {
		System.out.println("Vou creditar");
	}

}
