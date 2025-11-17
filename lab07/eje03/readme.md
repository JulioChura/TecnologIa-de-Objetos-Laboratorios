# Ejercicio 03 - Conexión simulada a Base de Datos (Singleton)

**Práctica 07 - Patrones de Diseño**
**Tema:** Singleton aplicado a una conexión simulada a base de datos

---

## Descripción

En este ejercicio se implementa una clase `ConexionBD` que simula el funcionamiento básico de una conexión a base de datos.
El objetivo principal es garantizar que **solo exista una conexión activa en todo el programa**, aplicando el patrón de diseño Singleton.

La clase permite realizar acciones como:

* Conectar
* Desconectar
* Consultar el estado actual de la conexión

Cada intento de obtener una nueva conexión siempre retorna la misma instancia, evitando la creación de múltiples conexiones.

---

## Objetivos del ejercicio

* Comprender el patrón Singleton aplicado a la gestión de recursos críticos.
* Asegurar que el sistema mantenga una única conexión activa.
* Implementar métodos para simular operaciones sobre la conexión.
* Verificar que todas las referencias apuntan al mismo objeto `ConexionBD`.

---

## Estructura del proyecto

```
prac07/
└── eje03/
    ├── ConexionBD.java
    ├── Main.java
    └── README.md
```

---

## Concepto clave: Singleton aplicado a una conexión

Este ejercicio muestra cómo el patrón Singleton es útil para manejar recursos que deben ser únicos, como una conexión a base de datos. Permite controlar el acceso y evitar múltiples conexiones simultáneas.

### 1. Constructor privado

Impide crear instancias desde fuera de la clase.

```java
private ConexionBD() {
    conectado = false;
    System.out.println(">>> Creando objeto ConexionBD...");
}
```

### 2. Atributo estático para almacenar la única instancia

```java
private static ConexionBD instancia;
```

### 3. Método de acceso controlado

Garantiza que solo exista una instancia:

```java
public static ConexionBD getInstancia() {
    if (instancia == null) {
        instancia = new ConexionBD();
    }
    return instancia;
}
```

### 4. Métodos de operación

Simulan acciones típicas de una conexión real:

```java
public void conectar() { ... }
public void desconectar() { ... }
public void estado() { ... }
```

---

## Ejemplo de uso en `main`

```java
ConexionBD c1 = ConexionBD.getInstancia();
c1.conectar();
c1.estado();

ConexionBD c2 = ConexionBD.getInstancia();
c2.estado();

if (c1 == c2) {
    System.out.println("Ambas referencias apuntan a la misma instancia.");
}

c2.desconectar();
```

En este caso:

* `c1` y `c2` son referencias distintas.
* Ambas apuntan al **mismo objeto Singleton**.
* La conexión solo se establece una vez.

---

## Salida esperada

Ejemplo aproximado:

```
>>> Creando objeto ConexionBD...
Conexión establecida.
Estado: Conectado
Estado: Conectado
Ambas referencias apuntan a la misma instancia.
Conexión cerrada.
```

---

## Conclusión

Este ejercicio demuestra cómo el patrón Singleton permite controlar el acceso a un recurso crítico, como una conexión a base de datos.
La implementación asegura que solo exista una instancia de la clase `ConexionBD`, evitando múltiples conexiones innecesarias y manteniendo un control centralizado del estado de la conexión.

