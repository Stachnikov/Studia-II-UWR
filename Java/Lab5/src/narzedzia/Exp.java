package narzedzia;

/**
 * Klasa reprezentujaca e^x
 */
public class Exp extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.exp(argument[0]);
	}
}
