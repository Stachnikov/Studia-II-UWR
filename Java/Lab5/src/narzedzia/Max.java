package narzedzia;

/**
 * Klasa reprezentujaca funkcje zwracajaca wartosc maksymalna
 */
public class Max extends FunkcjaDwuargumentowa implements Funkcyjny {
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		if(argument[0]>argument[1]) return argument[0];
		return argument[1];
	}
}
