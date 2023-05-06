package contas;

public class ContaJaCadastradaException extends Exception {

	private String numero;

	public ContaJaCadastradaException(String numero) {
		super("Conta j� existente!");
		this.numero = numero;
	}

	public String getNumero() {
		return numero;
	}
}