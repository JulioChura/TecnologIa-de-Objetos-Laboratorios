# Ejercicio 02 - Singleton con recursos compartidos

**Practica 07 - Patrones de Diseño**
**Tema:** Logger Singleton con escritura en archivo

---

## Descripcion

Este ejercicio implementa una clase `Logger` que registra mensajes en un archivo de texto (`bitacora.log`).
El objetivo es garantizar que **solo exista una única instancia** del logger y que todos los mensajes generados desde cualquier punto del programa se almacenen en el mismo archivo, demostrando el uso del patrón Singleton en un recurso compartido.

---

## Objetivos del ejercicio

* Comprender el uso del patrón Singleton aplicado a recursos comunes.
* Controlar la creación de una única instancia encargada del registro de mensajes.
* Agregar información al archivo de log con marca de tiempo.
* Verificar el funcionamiento desde distintos métodos y clases del programa.

---

## Estructura del proyecto

```
prac07/
└── eje02/
    ├── Logger.java
    ├── Main.java
    └── README.md
```

---

## Concepto clave: Singleton aplicado a un recurso compartido

El patrón Singleton asegura que una clase tenga una única instancia y proporcione un punto global de acceso a ella. En este caso, el recurso compartido es un **archivo de log**.

### 1. Constructor privado

Evita que otras clases puedan crear nuevas instancias.

```java
private Logger() {}
```

### 2. Instancia estática única

```java
private static Logger instancia;
```

### 3. Método estático que controla el acceso

```java
public static Logger getInstancia() {
    if (instancia == null) {
        instancia = new Logger();
    }
    return instancia;
}
```

### 4. Método para registrar mensajes con fecha y hora

```java
public void log(String mensaje) {
    ...
}
```

Este método abre el archivo `bitacora.log` en modo *append* y escribe el mensaje con un timestamp.

---

## Prueba en el `main`

```java
Logger logger1 = Logger.getInstancia();
Logger logger2 = Logger.getInstancia();

logger1.log("Inicio del programa");
logger2.log("Este mensaje viene de otra referencia, pero es el mismo Logger");

metodoA();
metodoB();
```

Ambas referencias (`logger1` y `logger2`) apuntan a la **misma instancia**, por lo que todos los mensajes se registran en el mismo archivo.

---

## Resultado esperado en `bitacora.log`

Ejemplo de salida generada:

```
[2025-11-16 22:18:08] Inicio del programa
[2025-11-16 22:18:08] Este mensaje viene de otra referencia, pero es el mismo Logger
[2025-11-16 22:18:08] Mensaje desde metodoA
[2025-11-16 22:18:08] Mensaje desde metodoB
```

Cada entrada incluye:

* Fecha
* Hora
* Mensaje enviado desde cualquier parte del programa

---

## Conclusion

Este ejercicio demuestra cómo aplicar el patrón Singleton para gestionar un recurso compartido: un archivo de log. La implementación garantiza que solo existe un `Logger` en todo el sistema, evitando inconsistencias y permitiendo centralizar el registro de eventos desde distintos puntos del programa.

