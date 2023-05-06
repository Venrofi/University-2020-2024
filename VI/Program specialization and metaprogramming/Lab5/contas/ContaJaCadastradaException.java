package contas;

public class ContaJaCadastradaException extends Exception {

	private String numero;

	public ContaJaCadastradaException(String numero) {
		super("Conta já existente!");
		this.numero = numero;
	}

	public String getNumero() {
		return numero;
	}
}