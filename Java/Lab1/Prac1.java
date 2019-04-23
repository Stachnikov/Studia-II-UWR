package Lab1;
public class Prac1{

// tablica jednosci
    private static String[] jednosci = {
            "","jeden","dwa","trzy","cztery","pięć","sześć","siedem","osiem","dziewięć"
    };
    // tablica dziesiatek
    private static String[] dziesiatki = {
            "","","dwadzieścia","trzydzieści","czterydzieści","pięćdziesiąt","sześćdziesiąt","siedemdziesiąt","osiemdziesiąt","dziewięćdziesiąt"
    };

    // tablica nastek
    private static String[] nastki = {
            "dziesięć","jedenaście","dwanaście","trzynaście","czterynaście","piętnaście","szesnaście","siedemnaście","osiemnaście","dziewiętnaście"
    };

    // tablica setek
    private static String[] setki = {
            "","sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"
    };

    static String wypisz_liczbe(String liczba){
        StringBuilder wynik = new StringBuilder();
            try{
                int x = Integer.parseInt(liczba);
                System.out.println(x);

                if (x == -2147483648) {
                    wynik.append("minus dwa miliardy sto czterydzieści siedem milionów czterysta osiemdziesiąt trzy tysiące sześćset czterydzieści osiem\n\n");
                    return wynik.toString();
                }
                //Minus---------------------------------------------------------------------------------
                if (x < 0) {
                    wynik.append("minus ");
                    x = -x;
                }
                if (x == 0) {
                    wynik.append("zero");
                    return wynik.toString();
                }
                //Miliard--------------------------------------------------------------------------------
                int miliard = x / 1000000000;
                if (miliard != 0) {
                    if (miliard == 2)
                        wynik.append("dwa miliardy ");
                    else
                        wynik.append("miliard ");
                    x = x - miliard * 1000000000;
                }

                //Setki milionów------------------------------------------------------------------------
                int setki_milionow = x / 100000000;
                if (setki_milionow != 0) {
                    wynik.append(setki[setki_milionow] + " ");
                    x = x - setki_milionow * 100000000;
                    if (x / 1000000 == 0)
                        wynik.append("milionów ");
                }

                //Dziesiatki milinów--------------------------------------------------------------------
                int dziesiatki_milionow = x / 1000000;
                if (dziesiatki_milionow != 0) {
                    x = x - dziesiatki_milionow * 1000000;
                    if (dziesiatki_milionow < 10) {
                        if (dziesiatki_milionow == 1)
                            wynik.append("milion ");
                        else {
                            wynik.append(jednosci[dziesiatki_milionow] + " ");
                            if (dziesiatki_milionow <= 4)
                                wynik.append("miliony ");
                            else
                                wynik.append("milionów ");
                        }
                    } else if (dziesiatki_milionow < 20)
                        wynik.append(nastki[dziesiatki_milionow % 10] + " milionów ");
                    else {
                        wynik.append(dziesiatki[dziesiatki_milionow / 10] + " " + jednosci[dziesiatki_milionow % 10] + " ");
                        if (dziesiatki_milionow % 10 <= 4 && dziesiatki_milionow % 10 >= 2)
                            wynik.append("miliony ");
                        else
                            wynik.append("milionów ");
                    }
                }

                //Setki tysiecy------------------------------------------------------------------------
                int setki_tysiecy = x / 100000;
                if (setki_tysiecy != 0) {
                    wynik.append(setki[setki_tysiecy] + " ");
                    x = x - setki_tysiecy * 100000;
                    if (x / 1000 == 0)
                        wynik.append("tysięcy ");
                }

                //Dziesiatki tysiecy--------------------------------------------------------------------
                int dziesiatki_tysiecy = x / 1000;
                if (dziesiatki_tysiecy != 0) {
                    x = x - dziesiatki_tysiecy * 1000;
                    if (dziesiatki_tysiecy < 10) {
                        if (dziesiatki_tysiecy == 1)
                            wynik.append("tysiąc ");
                        else {
                            wynik.append(jednosci[dziesiatki_tysiecy] + " ");
                            if (dziesiatki_tysiecy <= 4)
                                wynik.append("tysiące ");
                            else
                                wynik.append("tysięcy ");
                        }
                    } else if (dziesiatki_tysiecy < 20)
                        wynik.append(nastki[dziesiatki_tysiecy % 10] + " tysięcy ");
                    else {
                        wynik.append(dziesiatki[dziesiatki_tysiecy / 10] + " " + jednosci[dziesiatki_tysiecy % 10] + " ");
                        if (dziesiatki_tysiecy % 10 <= 4 && dziesiatki_tysiecy % 10 >= 2)
                            wynik.append("tysiące ");
                        else
                            wynik.append("tysięcy ");
                    }
                }

                //Setki------------------------------------------------------------------------
                int set = x / 100;
                if (set != 0) {
                    wynik.append(setki[set] + " ");
                    x = x - set * 100;
                }

                //Dziesiatki--------------------------------------------------------------------
                int dziesiat = x;
                if (dziesiat < 10) {
                    wynik.append(jednosci[dziesiat]);
                } else if (dziesiat < 20)
                    wynik.append(nastki[dziesiat % 10]);
                else {
                    wynik.append(dziesiatki[dziesiat / 10] + " " + jednosci[dziesiat % 10]);
                }
                wynik.append("\n\n\n");
            }
            catch (NumberFormatException e){
                System.err.print("Błędne dane...\nArgument nie jest typu INT\n\n\n");
            }
            return wynik.toString();
    }

    public static void main(String[] args) {
        for (int count = 1; count <= args.length; count++) {
            String liczba = args[count - 1];
            String wynik = wypisz_liczbe(liczba);
            System.out.println(wynik);
        }
    }
}