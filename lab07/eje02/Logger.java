import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Logger {

    private static Logger instancia;     
    private static final String ARCHIVO = "bitacora.log";

    private Logger() {}

    public static Logger getInstancia() {
        if (instancia == null) {
            instancia = new Logger();
        }
        return instancia;
    }

    public void log(String mensaje) {
        try (FileWriter writer = new FileWriter(ARCHIVO, true)) {
            String timestamp = LocalDateTime.now()
                    .format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));

            writer.write("[" + timestamp + "] " + mensaje + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
