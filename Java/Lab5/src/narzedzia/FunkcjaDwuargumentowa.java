package narzedzia;

/**
 * Klasa abstrakcyjna reprezentujaca funkcje dwuargumentowe
 */
abstract class FunkcjaDwuargumentowa extends Funkcja implements Funkcyjny {
	@Override
	public int arnosc() {
		return 2;
	}
}
