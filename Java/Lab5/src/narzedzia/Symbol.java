package narzedzia;


/**
 * Klasa abstrakcyjna reprezentujaca symbol
 */
abstract public class Symbol implements Obliczalny{

	/**
	 * Metoda wypisujaca
	 * @return String bedacy wynikiem obliczania
	 */
	public String toString(){
		try {
			return "" + this.oblicz();
		}catch(WyjatekONP ex){
			return ex.toString();
		}
	}
}
