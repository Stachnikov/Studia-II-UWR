package narzedzia;

/**
 * Klasa reprezentujaca funkcje sinus
 */
public class Sin extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.sin(Math.toRadians(argument[0]));
	}
}
