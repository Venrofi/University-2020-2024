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
public aspect Teste2 {

	public pointcut creditarExecution(Conta conta): 
	    this(conta) &&
	    execution(void creditar(double));
	
  	after(Conta conta): creditarExecution(conta) {
		System.out.println("O saldo agora é " + conta.getSaldo());
	}	

}
