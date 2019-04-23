import obliczenia.*;

public class Main {

    public static void main(String[] args){

        Wyrazenie w1,w2,w3,w4,w5;
        // w1 = 3+5
        w1 = new Dodaj(
                new Liczb(3),
                new Liczb(5));

        // w2 = 2+x*7
        w2 = new Dodaj(
                new Liczb(2),
                new Pomnoz(
                        new Zmienna("x"),
                        new Liczb(7)));
        // w3 = (3*11-1)/(7+5)
        w3 = new Podziel(
                new Odejmij(
                        new Pomnoz(
                                new Liczb(3),
                                new Liczb(11)),
                        new Liczb(1)),
                new Dodaj(
                        new Liczb(7),
                        new Liczb(5)));

        // w4 = arctan(((x+13)*x)/2)
        w4 = new Arctan(
                new Podziel(
                        new Pomnoz(
                                new Dodaj(
                                        new Zmienna("x"),
                                        new Liczb(13)),
                                new Zmienna("x")),
                        new Liczb(2)));

        // w5 = pow(2,5)+x*log(2,y)
        w5 = new Dodaj(
                new Potega(
                        new Liczb(2),
                        new Liczb(5)),
                new Pomnoz(
                        new Zmienna("x"),
                        new Log(
                                new Liczb(2),
                                new Zmienna("y"))));

        Wyrazenie ww1 = new Podziel(new Pomnoz(new Odejmij(new Zmienna("x"),new Liczb(1)),new Zmienna("x")),new Liczb(2));
        Wyrazenie ww2 = new Podziel(new Dodaj(new Liczb(3),new Liczb(5)),new Dodaj(new Liczb (2),new Pomnoz(new Zmienna("x"),new Liczb(7))));
        Wyrazenie ww3 = new Odejmij(new Dodaj(new Liczb(2),new Pomnoz(new Zmienna("x"),new Liczb(7))),new Dodaj(new Pomnoz(new Zmienna("y"),new Liczb(3)),new Liczb(5)));
        Wyrazenie ww4 = new Podziel(new Cosinus(new Pomnoz(new Dodaj(new Zmienna("x"),new Liczb(1)),new Zmienna("x"))),new WartBezw(new Potega(new Zmienna("x"),new Liczb(2))));

        Zmienna.ustaw("x",1);
        Zmienna.ustaw("y",2);

        System.out.println(w1 + " = " + w1.oblicz());
        System.out.println(w2+ " = " + w2.oblicz());
        System.out.println(w3 + " = " + w3.oblicz());
        System.out.println(w4 + " = " + w4.oblicz());
        System.out.println(w5 + " = " + w5.oblicz());


        System.out.println("\n");


        System.out.println(ww1+ " = " + ww1.oblicz());
        System.out.println(ww2 + " = " + ww2.oblicz());
        System.out.println(ww3 + " = " + ww3.oblicz());
        System.out.println(ww4 + " = " + ww4.oblicz());
    }
}

