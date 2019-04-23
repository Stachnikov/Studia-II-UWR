package narzedzia;

/**
 * Klasa reprezentujaca stala phi
 */
public class Phi extends FunkcjaBezargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		return 1.61803399;
	}
}
