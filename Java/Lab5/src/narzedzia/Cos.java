package narzedzia;

/**
 * Klasa reprezentujaca funkcje cosinus()
 */
public class Cos extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.cos(Math.toRadians(argument[0]));
	}
}
