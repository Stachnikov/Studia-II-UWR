package narzedzia;

/**
 * Klasa reprezentujaca przypisanie
 */
public class Przypisz extends FunkcjaJednoargumentowa implements Funkcyjny {
	private String klucz;

	public void wstaw(String key){
		klucz=key;
	}
	@Override
	public double oblicz() throws WyjatekONP {
		if(klucz==null | brakujaceArgumenty()>0) throw new ONP_NieprawidlowePrzypisanie();
		Zmienna.wstaw(klucz, argument[0]);
		return argument[0];
	}
}
