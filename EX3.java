import java.util.ArrayList;
class Vehicule {
    protected final String marque , modele ;
    protected String couleur;
    protected  static  int nb=0;
    Vehicule(String marque,String mod,String coul){
        this.marque = marque ;
        this.modele = mod ;
        this.couleur = coul ;
        nb++;
    }
    @Override
    public String toString() {
        return "Marque :" + marque + "    ||   Modele :" + modele + "   ||    Couleur :" + couleur;
    }
}
final class Moto extends Vehicule {
    private int puissance;
    Moto(String marque, String mod, String coul,int puissance) {
        super(marque, mod, coul) ;
        this.puissance=puissance;
    }
    Moto(String marque, String mod, String coul) {
        super(marque, mod, coul) ;
    }
    public String toString() {
        return "Marque :" + marque + "    ||   Modele :" + modele + "   ||    Couleur :" + couleur
                + "   ||    puissance :" + puissance;
    }
}
final class  Auto extends Vehicule {
    private int cylindree;
    Auto(String marque, String mod, String coul,int cylindree) {
        super(marque, mod, coul) ;
        this.cylindree=cylindree;
    }
    Auto(String marque, String mod, String coul) {
        super(marque, mod, coul) ;
    }
    public String toString() {
        return "Marque :" + marque + "    ||   Modele :" + modele + "   ||    Couleur :" + couleur
                + "   ||    cylindree :" + cylindree;
    }
}

public class Poly
{ public static void main (String arg[]){
    Vehicule v1= new Vehicule("BMW","M4","Grey");
    Auto v2 =new Auto("Peugeot", "508", "blanche") ;
    Moto v3 = new Moto("Honda", "CB500", "blanche") ;
    System.out.println(v1);
    System.out.println(v2);
    System.out.println(v3);
    System.out.println("le nombre de véhicules est "+ Vehicule.nb);

    ArrayList<Vehicule> Vehicule_List = new ArrayList<Vehicule>() ;
    Vehicule_List.add(v1) ;
    Vehicule_List.add(v2) ;
    Vehicule_List.add(v3) ;
    for (int i = 0 ; i < Vehicule_List.size(); i++){
        System.out.println("Vehicule :" + i) ;
        System.out.println(Vehicule_List.get(i)) ;
    }
}}