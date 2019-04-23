package geometria;

public class Odcinek{
    private Punkt A,B;

    Punkt getA(){
        return A;
    }

    Punkt getB(){
        return B;
    }

    Odcinek(Punkt a,Punkt b) throws Exception {
        if(a.getx() == b.getx() && a.gety() == b.gety())
            throw new Exception("Punkty A i B powinny być różne...");
        else{
            this.A=a;
            this.B=b;
        }
    }

    void przesun(Wektor v){
        A.przesun(v);
        B.przesun(v);
    }

    void obroc(Punkt p, double kat){
        A.obroc(p,kat);
        B.obroc(p,kat);
    }

    void odbij(Prosta p) throws Exception{
        A.odbij(p);
        B.odbij(p);
    }
}

