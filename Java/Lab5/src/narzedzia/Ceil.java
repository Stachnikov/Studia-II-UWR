package narzedzia;

/**
 * Klasa reprezentujaca funkcje zaokraglajaca w gore
 */
public class Ceil extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.ceil(argument[0]);
	}
}
