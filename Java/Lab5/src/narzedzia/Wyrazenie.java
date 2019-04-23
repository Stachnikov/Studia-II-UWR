package narzedzia;

import java.util.ArrayDeque;
import java.util.TreeMap;

/**
 * Klasa reprezentujaca wyrazenie
 */
public class Wyrazenie{
	private ArrayDeque<Symbol> kolejka = new ArrayDeque<>();
	private ArrayDeque<Double> stos = new ArrayDeque<>();
	final private static TreeMap<String, Double> zmienne = Zmienna.zmienne;


	public Wyrazenie(String[] str) throws WyjatekONP{
		for(int i=0; i<str.length; i++) {
			Symbol sym = translate(str[i]);
			kolejka.offerLast(sym);
		}
	}

	public double oblicz() throws WyjatekONP {
		Symbol sym;
		while(!kolejka.isEmpty()){
			sym=kolejka.pollFirst();
			if(sym.getClass()== Zmienna.class)
				if (!kolejka.isEmpty())
					if (kolejka.getFirst().getClass() == Przypisz.class) {
						Zmienna z = (Zmienna) sym;
						Przypisz p = (Przypisz) kolejka.pollFirst();
						p.wstaw(z.getKlucz());
						sym = p;
					}
					while (sym.brakujaceArgumenty() > 0) {
						if (stos.isEmpty())
							throw new ONP_ZlaLiczbaArgumentow();
						sym.dodajArgument(stos.pollFirst());
					}
			stos.offerFirst(sym.oblicz());
		}
		if(stos.size()!=1)
			throw new ONP_ZlaLiczbaArgumentow();
		return stos.getFirst();
	}

	/**
	 * Metoda zamieniajaca string na konkretne obiekty
	 * @param str String reprezentujacy Ssymbol
	 * @return Obiekt odpowiedniej klasy
	 * @throws WyjatekONP wyjatek dotyczacy ONP
	 */
	private Symbol translate(String str) throws WyjatekONP{
		if(str.matches("="))
			return new Przypisz();
		if(str.matches("\\+"))
			return new Dodaj();
		if(str.matches("\\*"))
			return new Mnoz();
		if(str.matches("-"))
			return new Odejmij();
		if(str.matches("/"))
			return new Dziel();
		if(str.matches("min"))
			return new Min();
		if(str.matches("max"))
			return new Max();
		if(str.matches("log"))
			return new Log();
		if(str.matches("power"))
			return new Pow();
		if(str.matches("abs"))
			return new Abs();
		if(str.matches("sgn"))
			return new Sgn();
		if(str.matches("floor"))
			return new Floor();
		if(str.matches("ceil"))
			return new Ceil();
		if(str.matches("frac"))
			return new Frac();
		if(str.matches("sin"))
			return new Sin();
		if(str.matches("cos"))
			return new Cos();
		if(str.matches("arctg"))
			return new Atan();
		if(str.matches("arccos"))
			return new Acot();
		if(str.matches("ln"))
			return new Ln();
		if(str.matches("exp"))
			return new Exp();
		if(str.matches("E"))
			return new E();
		if(str.matches("Pi"))
			return new Pi();
		if(str.matches("Phi"))
			return new Phi();
		if(str.matches("\\d+\\.?\\d*")) {
			return new Liczba(Double.parseDouble(str));
		}
		if(str.matches("\\p{Alpha}\\p{Alnum}*"))
			return new Zmienna(str);
		throw new ONP_NieznanySymbol(str);
	}
}
