package narzedzia;

/**
 * Klasa reprezentujaca stala e
 */
public class E extends FunkcjaBezargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		return Math.E;
	}
}
