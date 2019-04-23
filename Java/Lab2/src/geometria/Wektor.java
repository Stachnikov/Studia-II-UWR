package geometria;

class Wektor{
    public final double dx,dy;


    Wektor(double x, double y) {
        this.dx = x;
        this.dy = y;
    }

    static Wektor zloz_wektory(Wektor w1, Wektor w2){       //TO DO
        Wektor zlozony = new Wektor(w1.dx + w2.dx,w1.dy + w2.dy);

        return zlozony;
    }
}

