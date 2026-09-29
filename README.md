# Ecuación de Drake Reformulada

Programa de consola desarrollado en C++ que implementa una versión reformulada de la Ecuación de Drake, incorporando factores relacionados con la supervivencia, autodestrucción y posibles eventos de extinción cósmica.

El programa calcula una estimación del número de civilizaciones tecnológicas que podrían coexistir simultáneamente en una galaxia según los parámetros introducidos por el usuario.

> **Nota:** este programa es un modelo matemático experimental y educativo. Los resultados dependen completamente de los valores introducidos y no constituyen una predicción científica demostrada sobre el número real de civilizaciones extraterrestres.

## Características

* Interfaz de consola.
* Banner ASCII.
* Colores ANSI para terminales Linux.
* Cálculo de la longevidad efectiva de una civilización.
* Cálculo del número estimado de civilizaciones activas.
* Validación de los parámetros introducidos.
* Parámetros basados en la Ecuación de Drake.
* Incorporación de factores de autodestrucción y destrucción cósmica.
* Compatible con Linux.
* No requiere bibliotecas externas.
* Licencia MIT.

## Modelo matemático

El programa utiliza dos etapas principales.

### 1. Longevidad efectiva

La longevidad máxima introducida por el usuario se modifica mediante dos factores de riesgo:

```text
L_efectiva = L_max × (1 - f_aut) × (1 - f_ext)
```

Donde:

* `L_max` = longevidad máxima potencial.
* `f_aut` = riesgo de autodestrucción.
* `f_ext` = riesgo de destrucción cósmica.
* `L_efectiva` = longevidad resultante del modelo.

Los valores de `f_aut` y `f_ext` deben estar entre `0` y `1`.

Por ejemplo:

```text
L_max = 10000
f_aut = 0.20
f_ext = 0.10
```

produce:

```text
L_efectiva = 10000 × 0.80 × 0.90
L_efectiva = 7200 años
```

### 2. Número de civilizaciones

El programa utiliza:

```text
N = R* × fp × ne × fl × fi × fc × L_efectiva
```

Donde:

| Parámetro    | Descripción                                      |
| ------------ | ------------------------------------------------ |
| `R*`         | Tasa de formación estelar                        |
| `fp`         | Fracción de estrellas con planetas               |
| `ne`         | Número de planetas habitables por sistema        |
| `fl`         | Fracción donde surge la vida                     |
| `fi`         | Fracción donde surge inteligencia                |
| `fc`         | Fracción que desarrolla tecnología               |
| `L_efectiva` | Longevidad modificada por los factores de riesgo |
| `N`          | Resultado estimado del modelo                    |

## Requisitos

* Linux.
* Compilador C++.
* GCC/G++.
* Terminal compatible con secuencias ANSI.

El programa utiliza únicamente la biblioteca estándar de C++, por lo que no necesita instalar librerías externas.

## Instalación del compilador

En Ryoku Linux y otras distribuciones basadas en Arch Linux:

```bash
sudo pacman -S gcc
```

Comprobar la instalación:

```bash
g++ --version
```

## Compilación

Clonar el repositorio o descargar el código fuente.

Entrar en la carpeta del proyecto:

```bash
cd ruta/del/proyecto
```

Compilar:

```bash
g++ drake.cpp -o drake -std=c++17 -O2
```

El resultado será un ejecutable llamado:

```text
drake
```

## Ejecución

Ejecutar desde la terminal:

```bash
./drake
```

## Uso

Al iniciar el programa se solicitan los parámetros astrofísicos y biológicos:

```text
Tasa de formación estelar (R*)
Fracción con planetas (fp)
Planetas habitables por sistema (ne)
Fracción donde surge vida (fl)
Fracción con inteligencia (fi)
Fracción con tecnología (fc)
```

Después se solicitan los parámetros de supervivencia:

```text
Longevidad máxima potencial (L_max)
Riesgo de AUTODESTRUCCIÓN (f_aut)
Riesgo de DESTRUCCIÓN CÓSMICA (f_ext)
```

Los factores expresados como fracciones deben introducirse entre `0` y `1`.

Por ejemplo:

```text
fp = 0.8
fl = 0.3
fi = 0.1
fc = 0.5
f_aut = 0.2
f_ext = 0.1
```

Una vez introducidos todos los parámetros, el programa calcula la longevidad efectiva y el valor `N`.

## Ejemplo

Una ejecución podría utilizar:

```text
R*   = 2
fp   = 0.8
ne   = 2
fl   = 0.5
fi   = 0.2
fc   = 0.5

L_max = 10000
f_aut = 0.2
f_ext = 0.1
```

El programa calculará primero:

```text
L_efectiva = 10000 × (1 - 0.2) × (1 - 0.1)
```

y posteriormente utilizará esa longevidad en el cálculo de `N`.

## Estructura del proyecto

```text
drake/
├── drake.cpp
├── README.md
└── LICENSE
```

Después de compilar:

```text
drake/
├── drake.cpp
├── README.md
├── LICENSE
└── drake
```

## Compatibilidad

El código fue adaptado para Linux y evita funciones específicas de Windows como:

```cpp
system("cls");
system("pause");
system("color 06");
system("title ...");
```

En su lugar utiliza secuencias ANSI y funciones de la biblioteca estándar de C++.

Por tanto, no necesita:

```text
windows.h
conio.h
Wine
```

## Limitaciones

Este proyecto representa un modelo matemático simplificado.

Los valores de entrada son hipotéticos y pequeñas modificaciones en los parámetros pueden producir grandes diferencias en el resultado.

La ecuación implementada tampoco pretende representar todos los factores que podrían afectar la aparición, desarrollo, supervivencia o desaparición de civilizaciones tecnológicas.

El resultado `N` debe interpretarse como el resultado del modelo introducido, no como una medición observacional del universo.

## Autor

**Z3r0X**

Proyecto desarrollado en C++.

## Licencia

Este proyecto se distribuye bajo la **Licencia MIT**.

Consulta el archivo [`LICENSE`](LICENSE) para conocer el texto completo de la licencia.

Identificador SPDX:

```text
MIT
```
