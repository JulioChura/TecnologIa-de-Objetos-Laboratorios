public class ConexionBD {

    private static ConexionBD instancia;

    private boolean conectado;

    private ConexionBD() {
        conectado = false;
        System.out.println(">>> Creando objeto ConexionBD...");
    }

    public static ConexionBD getInstancia() {
        if (instancia == null) {
            instancia = new ConexionBD();
        }
        return instancia;
    }

    public void conectar() {
        if (!conectado) {
            conectado = true;
            System.out.println("Conexión establecida.");
        } else {
            System.out.println("Ya existe una conexión activa.");
        }
    }

    public void desconectar() {
        if (conectado) {
            conectado = false;
            System.out.println("Conexión cerrada.");
        } else {
            System.out.println("No hay conexión para cerrar.");
        }
    }

    public void estado() {
        System.out.println(conectado ? "Estado: Conectado" : "Estado: Desconectado");
    }
}