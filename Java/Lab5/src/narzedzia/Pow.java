package narzedzia;

/**
 * Klasa reprezentujaca potegowanie
 */
public class Pow extends FunkcjaDwuargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.pow(argument[1], argument[0]);
	}
}
