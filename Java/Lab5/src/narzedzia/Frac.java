package narzedzia;

/**
 * Klasa reprezentujaca funkcje zwracajaca czesc calkowita z liczby
 */
public class Frac extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return argument[0]- Math.floor(argument[0]);
	}
}
