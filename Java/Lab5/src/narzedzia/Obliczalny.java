package narzedzia;

/**
 * Interfejs dla klas obliczalnych
 */
public interface Obliczalny {
	/**
	 * Metoda zwracajaca ilosc brakujacych argumentow
	 * @return liczba calkowita - ilosc brakujacych argumentow
	 */
	int brakujaceArgumenty();

	/**
	 * Metoda dodajaca argument do funkcji
	 * @param arg argument ktory chcemy dodac
	 * @throws WyjatekONP wyjatek dotyczacy ONP
	 */
	void dodajArgument(double arg) throws WyjatekONP;

	/**
	 * Metoda wyliczajaca
	 * @return obliczona wartosc typu double
	 * @throws WyjatekONP wyjatek dotyczacy ONP
	 */
	double oblicz() throws WyjatekONP;
}
