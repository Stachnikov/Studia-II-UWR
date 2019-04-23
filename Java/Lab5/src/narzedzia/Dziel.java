package narzedzia;

/**
 * Klasa reprezentujaca operacje dzielenia
 */
public class Dziel extends FunkcjaDwuargumentowa implements Funkcyjny {

	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		if(argument[0] == 0){
			throw new ONP_DzieleniePrzez0();
		}
		return argument[1]/argument[0];
	}
}
