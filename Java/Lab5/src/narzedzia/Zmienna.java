package narzedzia;

import java.util.TreeMap;

/**
 * Klasa reprezentujaca zmienna
 */
public class Zmienna extends Operand {
	private String klucz;
	final protected static TreeMap<String, Double> zmienne = new TreeMap<>();

	public Zmienna(String klucz) {
		this.klucz = klucz;
	}

	/**
	 * Metoda zwracajaca klucz
	 * @return String klucz
	 */
	public String getKlucz() {
		return klucz;
	}

	/**
	 * Metoda wstawiajaca zmienna wraz z kluczem
	 * @param key klucz
	 * @param value wartosc
	 * @throws WyjatekONP wyjatek ONP gdy klucz nie pasuje do schematu
	 */
	public static void wstaw(String key, double value) throws WyjatekONP{
		if(!key.matches("\\p{Alpha}\\p{Alnum}*"))
			throw new ONP_NieprawidlowaNazwaZmiennej();
		zmienne.put(key, value);
	}

	/**
	 * Metoda czyszczaca TreeMap zmienne
	 */
	public static void wyczysc(){
		zmienne.clear();
	}

	/**
	 * Metoda usuwajaca pare o danym kluczu w TreeMap zmienne
	 * @param key klucz pary ktora chcemy usunac
	 */
	public static void usun(String key){
		zmienne.remove(key);
	}

	@Override
	public double oblicz() throws WyjatekONP {
		if(!zmienne.containsKey(klucz)) throw new ONP_BrakZmiennej();
		return zmienne.get(klucz);
	}
}
