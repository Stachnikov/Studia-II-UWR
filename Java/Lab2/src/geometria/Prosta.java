package geometria;

class Prosta{
    public final double a,b,c;

    Prosta(double A,double B,double C) throws Exception {

        if (A==0 && B==0)
                throw new Exception("Wspolczynniki A i B nie moga byc jednoczesnie rowne 0");

        this.a = A;
        this.b = B;
        this.c = C;
    }

    public static Prosta przesun(Prosta p1, Wektor v) throws Exception {

        return new Prosta(p1.a,p1.b, (p1.c + v.dy - p1.a*v.dx));
    }

    public static boolean czy_rownolegle(Prosta p1, Prosta p2){

        if(p1.a/p2.a ==p1.b/p2.b)
            return true;
        else
            return false;
    }

    public static boolean czy_prostopadle(Prosta p1,Prosta p2){

        double aa = p1.a/p1.b;
        double bb = p2.a/p2.b;
        if(aa == (-1/bb))
            return true;
        else
            return false;
    }

    public static Punkt przeciecie(Prosta p1,Prosta p2) throws Exception{

        if(Prosta.czy_rownolegle(p1, p2)){
            throw new Exception("Proste nie mogą być równoległe...");
        }
        double x=0,y=0;

        if(p1.b != 0 && p2.b != 0) {
            x = (((p2.c / p2.b) - (p1.c / p1.b)) / ((p1.a / p1.b) - (p2.a / p2.b)));
            y = -((p1.a / p1.b) * (x) + (p1.c / p1.b));
        }
        else if(p1.b == 0) {
            x = p1.c;
            y = p2.c;
        }
        else{
            x = p2.c;
            y = p1.c;
        }

        return new Punkt( x, y);
    }

    public static Prosta prostopadla(Prosta k,Punkt pp) throws Exception {

        if(k.a == 0){
            return new Prosta(-1,0,pp.getx());
        }
        if(k.b == 0){
            return new Prosta(0,-1,pp.gety());
        }

        double co = 1.0/k.a;
        double cc = (-co*-k.b)*pp.getx() - pp.gety();
        return new Prosta(-co*-k.b,-1,-cc);
    }
}
