package narzedzia;

/**
 * Klasa reprezentujaca operacje odejmowania
 */
public class Odejmij extends FunkcjaDwuargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return argument[1]-argument[0];
	}
}
