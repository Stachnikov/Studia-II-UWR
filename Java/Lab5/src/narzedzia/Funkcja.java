package narzedzia;

/**
 * Klasa abstrakcyjna reprezentujaca funkcje
 */
abstract class Funkcja extends Symbol implements Funkcyjny {
	int przyjeteArgumenty=0;
	double[] argument = new double[2];
	@Override
	public void dodajArgument(double arg) throws WyjatekONP {
		argument[przyjeteArgumenty] = arg;
		przyjeteArgumenty++;
	}
	@Override
	public int brakujaceArgumenty() {
		return arnosc()-przyjeteArgumenty;
	}
}
