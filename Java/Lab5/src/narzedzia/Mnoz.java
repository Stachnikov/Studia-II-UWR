package narzedzia;

/**
 * Klasa reprezentujaca operacje mnozenia
 */
public class Mnoz extends FunkcjaDwuargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return argument[0]*argument[1];
	}
}
