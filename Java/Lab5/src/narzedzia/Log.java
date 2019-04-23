package narzedzia;

/**
 * Klasa reprezentujaca logarytm
 */
public class Log extends FunkcjaDwuargumentowa implements Funkcyjny {
	@Override
	public void dodajArgument(double arg) throws WyjatekONP {
		if(arg<=0)
			throw new ONP_NieprawidowyLogarytm();
		if(przyjeteArgumenty==0 && arg==1)
			throw new ONP_NieprawidowyLogarytm();
		super.dodajArgument(arg);
	}

	@Override
	public double oblicz() throws WyjatekONP {
		if(brakujaceArgumenty()>0)
			throw new ONP_ZaMaloArgumentow();
		return Math.log(argument[0])/Math.log(argument[1]);
	}
}
