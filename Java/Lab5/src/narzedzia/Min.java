package narzedzia;

/**
 * Klasa reprezentujaca funkcje zwracajaca wartosc minimalna
 */
public class Min extends FunkcjaDwuargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		if(argument[0]>argument[1]) return argument[1];
		return argument[0];
	}
}
