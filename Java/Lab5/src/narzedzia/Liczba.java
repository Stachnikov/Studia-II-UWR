package narzedzia;

/**
 * Klasa reprezentujaca liczbe
 */
public class Liczba extends Operand {



    private double wartosc;
	public Liczba(double wartosc) {
		this.wartosc = wartosc;
	}
	@Override
	public double oblicz() throws WyjatekONP {
		return wartosc;
	}
}
