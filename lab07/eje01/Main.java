public class Main {
    public static void main(String[] args) {
        Configuracion config1 = Configuracion.getInstancia();
        Configuracion config2 = Configuracion.getInstancia();
        Configuracion config3 = Configuracion.getInstancia();

        System.out.println("config1 == config2: " + (config1 == config2));
        System.out.println("config2 == config3: " + (config2 == config3));
        System.out.println("config1 == config3: " + (config1 == config3));

        config1.mostrarConfiguracion();

        config1.setIdioma("English");
        config1.setZonaHoraria("UTC+0");

        System.out.println("\nDespués de modificar config1:");
        config2.mostrarConfiguracion();
        config3.mostrarConfiguracion();
    }
}