# Ejercicio 01 - Patron Singleton
**Practica 07 - Patrones de Diseño**  
**Tema:** Implementacion basica del Singleton en Java

---

## Descripcion

Este ejercicio implementa una clase `Configuracion` que almacena parametros globales del sistema (idioma y zona horaria).  
El proposito es garantizar que **solo exista una unica instancia** accesible desde cualquier parte del programa.

---

## Objetivos del ejercicio

- Comprender la estructura del patron Singleton.  
- Controlar la creacion de un recurso global.  
- Evitar la duplicacion de instancias.  
- Verificar el comportamiento del Singleton mediante pruebas en el `main`.

---

## Estructura del proyecto

```
prac07/
└── eje01/
    ├── Configuracion.java
    ├── Main.java
    └── README.md
```

---

## Concepto clave: Singleton

El patron Singleton requiere tres elementos principales:

### 1. Constructor privado  
Impide crear objetos desde fuera de la clase.

```java
private Configuracion() { ... }
```

### 2. Instancia estatica unica

```java
private static Configuracion instancia;
```

### 3. Metodo que controla el acceso a la instancia

```java
public static Configuracion getInstancia() {
    if (instancia == null) {
        instancia = new Configuracion();
    }
    return instancia;
}
```

---

## Prueba en el `main`

```java
Configuracion c1 = Configuracion.getInstancia();
Configuracion c2 = Configuracion.getInstancia();
System.out.println(c1 == c2); // true
```

Las referencias apuntan al mismo objeto.

---

## Estado compartido

Cambiar la configuracion desde cualquier referencia afecta a todas:

```java
c1.setIdioma("English");
c1.setZonaHoraria("UTC+0");
```

Y al mostrar con `c2.mostrarConfiguracion()`, los cambios se reflejan.

---

## Conclusion

Este ejercicio demuestra como implementar y verificar un Singleton basico en Java, asegurando que solo exista una instancia centralizada para la configuracion del sistema.