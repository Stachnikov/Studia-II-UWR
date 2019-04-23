package narzedzia;

/**
 * Klasa reprezentujaca operand
 */
abstract class Operand extends Symbol implements Obliczalny {
	@Override
	public void dodajArgument(double arg) throws WyjatekONP {
	}

	@Override
	public int brakujaceArgumenty() {
		return 0;
	}
}
