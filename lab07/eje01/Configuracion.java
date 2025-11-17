public class Configuracion {
    private static Configuracion instancia;
    private String idioma;
    private String zonaHoraria;

    private Configuracion() {
        this.idioma = "Español";
        this.zonaHoraria = "UTC-5";
    }

    public static Configuracion getInstancia() {
        if (instancia == null) {
            instancia = new Configuracion();
        }
        return instancia;
    }

    public String getIdioma() {
        return idioma;
    }

    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

    public String getZonaHoraria() {
        return zonaHoraria;
    }

    public void setZonaHoraria(String zonaHoraria) {
        this.zonaHoraria = zonaHoraria;
    }

    public void mostrarConfiguracion() {
        System.out.println("Configuración del sistema:");
        System.out.println("Idioma: " + idioma);
        System.out.println("Zona Horaria: " + zonaHoraria);
    }
}