package narzedzia;

/**
 * Klasa reprezentujaca funkcje zwracajaca znak
 */
public class Sgn extends FunkcjaJednoargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		if(argument[0]>0) return 1;
		if(argument[0]==0) return 0;
		return -1;
	}
}
