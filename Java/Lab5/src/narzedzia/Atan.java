package narzedzia;

/**
 * Klasa reprezentujaca funkcje arctan()
 */
public class Atan extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.toDegrees(Math.atan(Math.toRadians(argument[0])));
	}
}
