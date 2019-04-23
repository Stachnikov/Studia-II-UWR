package narzedzia;

/**
 * Klasa reprezentujaca funkcje zaokraglajaca w dol
 */
public class Floor extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.floor(argument[0]);
//		int x= (int) argument[0];
//		if(argument[0]>= 0)
//			return x;
//		return ((double) x == argument[0]) ? x : x-1;
	}
}
