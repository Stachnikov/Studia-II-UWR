package narzedzia;

/**
 * Klasa abstrakcyjna reprezentujaca stale czyli funkcje bezargumentowe
 */
abstract class FunkcjaBezargumentowa extends Funkcja implements Funkcyjny{
	@Override
	public int arnosc() {
		return 0;
	}
}
