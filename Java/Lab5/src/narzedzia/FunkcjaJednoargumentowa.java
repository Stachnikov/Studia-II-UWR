package narzedzia;

/**
 * Klasa abstrakcyjna reprezentujaca funkcje jednoargumentowe
 */
abstract class FunkcjaJednoargumentowa extends Funkcja implements Funkcyjny{
	@Override
	public int arnosc() {
		return 1;
	}
}
