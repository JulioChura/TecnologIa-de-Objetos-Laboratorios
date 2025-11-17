public class Main {
    public static void main(String[] args) {

        Logger logger1 = Logger.getInstancia();
        Logger logger2 = Logger.getInstancia();

        logger1.log("Inicio del programa");
        logger2.log("Este mensaje viene de otra referencia, pero es el mismo Logger");
        
        metodoA();
        metodoB();

        System.out.println("Revisa el archivo bitacora.log");
    }

    public static void metodoA() {
        Logger.getInstancia().log("Mensaje desde metodoA");
    }

    public static void metodoB() {
        Logger.getInstancia().log("Mensaje desde metodoB");
    }
}
