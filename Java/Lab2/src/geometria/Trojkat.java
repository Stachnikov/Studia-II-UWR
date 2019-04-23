package geometria;

public class Trojkat{
    private Punkt A,B,C;

    Punkt getA(){
        return A;
    }

    Punkt getB(){
        return B;
    }

    Punkt getC(){
        return C;
    }

    Trojkat(Punkt a, Punkt b, Punkt c) throws Exception{

        double ab=Math.sqrt(Math.pow((b.getx()-a.getx()),2) + Math.pow(b.gety()-a.gety(),2));
        double bc=Math.sqrt(Math.pow((c.getx()-b.getx()),2) + Math.pow(c.gety()-b.gety(),2));
        double ca=Math.sqrt(Math.pow((a.getx()-c.getx()),2) + Math.pow(a.gety()-c.gety(),2));
        if ((ab+bc >ca) && (ab+ca >bc) && (bc+ca > ab)){
            this.A=a;
            this.B=b;
            this.C=c;
        }
        else
            throw new Exception("Taki trójkąt nie istnieje...");
    }

    void przesun(Wektor v){
        A.przesun(v);
        B.przesun(v);
        C.przesun(v);
    }

    void obroc(Punkt p, double kat){
        A.obroc(p,kat);
        B.obroc(p,kat);
        C.obroc(p,kat);
    }

    void odbij(Prosta p) throws Exception{
        A.odbij(p);
        B.odbij(p);
        C.odbij(p);
    }
}

