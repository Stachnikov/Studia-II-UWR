package narzedzia;

/**
 * Klasa reprezentujaca wartosc bezwzgledna
 */
public class Abs extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		if(argument[0]<0) return (-1)*argument[0];
		return argument[0];
	}
}
