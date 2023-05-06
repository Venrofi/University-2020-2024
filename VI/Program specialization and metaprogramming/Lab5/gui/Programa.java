package gui;
import contas.*;
import fachada.Banco;
import util.Util;

public class Programa {

	public static void main(String[] args) {
		RepositorioContas repositorio = new RepositorioContasArray();
		Banco fachada = new Banco(repositorio);
		Programa.menu(fachada);
	}

	public static void menu(Banco fachada) {
		String numero = null;
		double valor = 0.0;
		Conta conta = null;
		int opcao = 1;
		while (opcao != 0) {
			try {
				System.out.println("Press <Enter> to continue");
				Util.waitEnter();
				System.out.println("\n\n\n\n\n\n\n");
				System.out.println("Choose one of the options below:");
				System.out.println("1 - Create Account");
				System.out.println("2 - Credit");
				System.out.println("3 - Debit");
				System.out.println("4 - Transfer");
				System.out.println("5 - Check Balance");
				System.out.println("0 - Quit");
				opcao = Util.readInt();
				switch (opcao) {
					case 1 :
						System.out.println(
							"Enter the number of the account to be created:");
						numero = Util.readStr();
						conta = new Conta(numero);
						fachada.cadastrar(conta);
						System.out.println("Successfully registered account");
						break;
					case 2 :
						System.out.println("Enter the account number:");
						numero = Util.readStr();
						System.out.println("Enter the value to be credited:");
						valor = Util.readDbl();
						fachada.creditar(numero, valor);
						System.out.println("Credit made successfully");
						break;
					case 3 :
						System.out.println("Enter the account number:");
						numero = Util.readStr();
						System.out.println("Enter the value to be debited:");
						valor = Util.readDbl();
						fachada.debitar(numero, valor);
						System.out.println("Debit made successfully");
						break;
					case 4 :
						System.out.println(
							"Enter the number of the source account:");
						numero = Util.readStr();
						System.out.println(
							"Enter the number of the destination account:");
						String numeroAux = Util.readStr();
						System.out.println(
							"Enter the value to be transferred:");
						valor = Util.readDbl();
						fachada.transferir(numero, numeroAux, valor);
						System.out.println(
							"Transfer made successfully");
						break;
					case 5 :
						System.out.println("Enter the account number:");
						numero = Util.readStr();
						System.out.println(
							"The balance is " + fachada.saldo(numero));
						break;
					case 0 :
						System.out.println("Exiting...");
						break;
					default :
						System.out.println(
							"Incorrect option! Choose one of the menu options!\n");
						break;
				}
			} catch (Exception exception) {
				System.out.println(exception.getMessage());
			}
		}
	}
}
