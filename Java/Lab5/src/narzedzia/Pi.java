package narzedzia;

/**
 * Klasa reprezentujaca stala pi
 */
public class Pi extends FunkcjaBezargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		return Math.PI;
	}
}
