package narzedzia;

/**
 * Klasa reprezentujaca logarytm naturalny
 */
public class Ln extends FunkcjaJednoargumentowa implements Funkcyjny{
	@Override
	public void dodajArgument(double arg) throws WyjatekONP {
		if(arg<=0)
			throw new ONP_NieprawidowyLogarytm();
		super.dodajArgument(arg);
	}

	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.log(argument[0]);
	}
}
