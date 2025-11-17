import java.util.*;

public class Main {
    public static void main(String[] args) {

        ConexionBD c1 = ConexionBD.getInstancia();
        c1.conectar();
        c1.estado();

        ConexionBD c2 = ConexionBD.getInstancia();
        c2.estado();

        if (c1 == c2) {
            System.out.println("Ambas referencias apuntan a la misma instancia.");
        }

        c2.desconectar();
    }

}
