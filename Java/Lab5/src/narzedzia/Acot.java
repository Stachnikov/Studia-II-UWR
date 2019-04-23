package narzedzia;

/**
 * Klasa reprezentujaca arccot()
 */
public class Acot extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.toDegrees(Math.atan(1/Math.toRadians(argument[0])));
	}
}
