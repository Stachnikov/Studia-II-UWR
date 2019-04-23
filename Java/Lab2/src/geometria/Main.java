package geometria;

public class Main {

    public static void main(String[] args) throws Exception {
        //PUNKT-------------------------------------------------------------------------
        System.out.println("PUNKT-------------------------------------------------------");
        Punkt a = new Punkt(1,2);
	    System.out.printf("Punkt a = ( " + "%.2f , %.2f )\n", a.getx(),a.gety());

        //OBRÓT PUNKTU (DODATNI W LEWO UJEMNY W PRAWO
	    a.obroc(new Punkt(0,0),90);
        System.out.printf("Punkt a po obrocie o 90 = ( " + "%.2f , %.2f )\n",a.getx(),a.gety());

        //PRZESUNIĘCIE PUNKTU
        a.przesun(new Wektor(1,1));
        System.out.printf("Punkt a o wektor <1,1> = ( " + "%.2f , %.2f )\n\n\n",a.getx(),a.gety());

        //ODBICIE PUNKTU
        Punkt b = new Punkt(2,0);
        System.out.printf("Punkt b = ( " + "%.2f , %.2f )\n\n\n",b.getx(),b.gety());
        b.odbij(new Prosta(-2,-1,9));
        System.out.printf("Punkt b odbity względem prostej 0 = -2x -1y + 9 b' = ( " + "%.2f , %.2f )\n\n\n",b.getx(),b.gety());

        //ODCINEK-------------------------------------------------------------------------
        Punkt oa = new Punkt(0,4);
        Punkt ob = new Punkt(0,8);
        System.out.println("\n\nOdcinek AB:");
        System.out.printf("\nPunkt A = ( " + "%.2f , %.2f )\n", oa.getx(),oa.gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ob.getx(),ob.gety());
        Odcinek AB = new Odcinek(oa,ob);

        //OBRÓT ODCINKA
        AB.obroc(new Punkt(0,0),90);
        oa = AB.getA();
        ob = AB.getB();
        System.out.println("\n\nOdcinek AB obrócony o 90 stopni :");
        System.out.printf("\nPunkt A = ( " + "%.2f , %.2f )\n", oa.getx(),oa.gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ob.getx(),ob.gety());

        //PRZESUNIĘCIE ODCINKA
        AB.przesun(new Wektor(1,1));
        oa = AB.getA();
        ob = AB.getB();
        System.out.println("\n\nOdcinek AB po przesunięciu o wektor <1,1>:");
        System.out.printf("\nPunkt A = ( " + "%.2f , %.2f )\n", oa.getx(),oa.gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ob.getx(),ob.gety());

        //ODBICIE PUNKTU
        AB.odbij(new Prosta(4,-8,1));
        oa = AB.getA();
        ob = AB.getB();
        System.out.println("\n\nOdcinek AB po dobiciu względem prostej 0 = 4x -8y +1:");
        System.out.printf("\n\nPunkt A = ( " + "%.2f , %.2f )\n", oa.getx(),oa.gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ob.getx(),ob.gety());

        //TROJKAT
        Punkt A = new Punkt(-3,0);
        Punkt B = new Punkt(0,0);
        Punkt C = new Punkt(0,4);
        Trojkat ABC = new Trojkat(A,B,C);
        System.out.println("\n\nTrojkat ABC:");
        System.out.printf("\n\nPunkt A = ( " + "%.2f , %.2f )\n", ABC.getA().getx(),ABC.getA().gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ABC.getB().getx(),ABC.getB().gety());
        System.out.printf("Punkt C = ( " + "%.2f , %.2f )\n", ABC.getC().getx(),ABC.getC().gety());

        //OBROT TROJKATA
        ABC.obroc(new Punkt(0,0),90);

        System.out.println("\n\nTrojkat ABC po obrocie o 90 :");
        System.out.printf("\n\nPunkt A = ( " + "%.2f , %.2f )\n", ABC.getA().getx(),ABC.getA().gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ABC.getB().getx(),ABC.getB().gety());
        System.out.printf("Punkt C = ( " + "%.2f , %.2f )\n", ABC.getC().getx(),ABC.getC().gety());

        //PRZESUNIĘCIE TROJKATA
        ABC.przesun(new Wektor(1,1));
        System.out.println("\n\nTrojkat ABC po przesunieciu o wektor <1,1>:");
        System.out.printf("\n\nPunkt A = ( " + "%.2f , %.2f )\n", ABC.getA().getx(),ABC.getA().gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ABC.getB().getx(),ABC.getB().gety());
        System.out.printf("Punkt C = ( " + "%.2f , %.2f )\n", ABC.getC().getx(),ABC.getC().gety());

        //ODBICIE TROJKATA
        ABC.odbij(new Prosta(-1,0,2));
        System.out.println("\n\nTrojkat ABC po odbiciu względem prostej 0 = -x +2:");
        System.out.printf("\n\nPunkt A = ( " + "%.2f , %.2f )\n", ABC.getA().getx(),ABC.getA().gety());
        System.out.printf("Punkt B = ( " + "%.2f , %.2f )\n", ABC.getB().getx(),ABC.getB().gety());
        System.out.printf("Punkt C = ( " + "%.2f , %.2f )\n", ABC.getC().getx(),ABC.getC().gety());


        //EKSTRA
        System.out.println("Prosta przesunięta o wektor...");
        Prosta pro = new Prosta(12,-6,3);
        Wektor sklad1 = new Wektor(0,1);
        Wektor sklad2 = new Wektor(1,0);
        Wektor zlozony = Wektor.zloz_wektory(sklad1,sklad2);
        pro = Prosta.przesun(pro,zlozony);
        System.out.printf("\n\nProsta pro = ( " + "%.2f , %.2f , %.2f )\n", pro.a,pro.b,pro.c);
        /*Punkt aa = new Punkt(1,1);
        Punkt bb = new Punkt(1,1);
        Odcinek aB = new Odcinek(aa,bb);
        Punkt c = new Punkt(2,1);
        Trojkat aBC = new Trojkat(aa,bb,c);
        aa.przesun(zlozony);
        System.out.printf("Punkt aa = ( " + "%.2f , %.2f )\n", aa.getx(),aa.gety());*/

    }
}

