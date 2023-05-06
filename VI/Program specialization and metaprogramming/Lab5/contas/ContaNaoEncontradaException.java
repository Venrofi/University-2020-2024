package contas;

public class ContaNaoEncontradaException extends Exception {
	private String numero;

	public ContaNaoEncontradaException(String numero) {
		super("Conta n�o encontrada!");
		this.numero = numero;
	}

	public String getNumero() {
		return numero;
	}
}
