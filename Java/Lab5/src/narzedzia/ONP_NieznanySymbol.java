package narzedzia;

/**
 * Klasa reprezentujaca wyjatek dotyczacy nieznanego symbolu
 */
public class ONP_NieznanySymbol extends ONP_BledneWyrazenie {
	String symbol;

	public ONP_NieznanySymbol(String symbol) {
		this.symbol = symbol;
	}

	public String toString(){
		return "Nieznany symbol: "+symbol;
	}
}
