#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class CalculadoraDrake {
private:
    // Variables estándar de la ecuación
    double R_star;
    double fp;
    double ne;
    double fl;
    double fi;
    double fc;

    // Parámetros de supervivencia y vulnerabilidad
    double L_max;
    double f_aut;
    double f_ext;

    // Colores ANSI
    const std::string AMARILLO = "\033[33m";
    const std::string BLANCO = "\033[37m";
    const std::string ROJO = "\033[31m";
    const std::string VERDE = "\033[32m";
    const std::string RESET = "\033[0m";

public:
    // Constructor
    CalculadoraDrake()
        : R_star(0), fp(0), ne(0), fl(0), fi(0), fc(0),
          L_max(0), f_aut(0), f_ext(0) {}

    // Cambiar el título de la terminal en Linux
    void cambiarTituloTerminal() const {
        std::cout << "\033]0;Ecuacion de Drake Reformulada\007";
    }

    // Limpiar la pantalla
    void limpiarPantalla() const {
        std::cout << "\033[2J\033[H";
    }

    // Pausar hasta que el usuario presione ENTER
    void pausar() const {
        std::cout << "\nPresiona ENTER para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    // Banner principal
    void mostrarBanner() const {
        std::cout << AMARILLO;

        std::cout << "  ____   ____    _     _  _  _____ \n";
        std::cout << " |  _ \\ |  _ \\  / \\   | |// | ____|\n";
        std::cout << " | | | || |_) |/ _ \\  |  /  |  _|  \n";
        std::cout << " | |_| ||  _ </ ___ \\ |  \\  | |___ \n";
        std::cout << " |____/ |_| \\_\\_/   \\_\\|_|\\\\|_____|\n";

        std::cout << " -----------------------------------------------------\n";
        std::cout << "  ECUACION REFORMULADA: FILTROS DE EXTINCION COSMICA\n";
        std::cout << " -----------------------------------------------------\n\n";

        std::cout << BLANCO;
        std::cout << " Programada por Z3r0X\n\n";

        std::cout << RESET;
    }

    // Capturar datos
    void pedirDatos() {
        std::cout << AMARILLO;
        std::cout << " [>] PARAMETROS ASTROFISICOS Y BIOLOGICOS\n";
        std::cout << " -----------------------------------------------------\n";
        std::cout << RESET;

        std::cout << "  -> Tasa de formacion estelar (R*): ";
        std::cin >> R_star;

        std::cout << "  -> Fraccion con planetas (fp) [0-1]: ";
        std::cin >> fp;

        std::cout << "  -> Planetas habitables por sistema (ne): ";
        std::cin >> ne;

        std::cout << "  -> Fraccion donde surge vida (fl) [0-1]: ";
        std::cin >> fl;

        std::cout << "  -> Fraccion con inteligencia (fi) [0-1]: ";
        std::cin >> fi;

        std::cout << "  -> Fraccion con tecnologia (fc) [0-1]: ";
        std::cin >> fc;

        std::cout << "\n";

        std::cout << AMARILLO;
        std::cout << " [>] FILTROS DE SUPERVIVENCIA CRITICA\n";
        std::cout << " -----------------------------------------------------\n";
        std::cout << RESET;

        std::cout << "  -> Longevidad maxima potencial (L_max en anos): ";
        std::cin >> L_max;

        std::cout << "  -> Riesgo de AUTODESTRUCCION (f_aut) [0-1]: ";
        std::cin >> f_aut;

        std::cout << "  -> Riesgo de DESTRUCCION COSMICA (f_ext) [0-1]: ";
        std::cin >> f_ext;
    }

    // Validar rangos
    bool validarDatos() const {
        if (R_star < 0 ||
            fp < 0 || fp > 1 ||
            ne < 0 ||
            fl < 0 || fl > 1 ||
            fi < 0 || fi > 1 ||
            fc < 0 || fc > 1 ||
            L_max < 0 ||
            f_aut < 0 || f_aut > 1 ||
            f_ext < 0 || f_ext > 1) {

            std::cout << "\n" << ROJO;
            std::cout << " [!] ERROR: Se introdujeron valores invalidos.\n";
            std::cout << " [!] Las fracciones y riesgos deben estar entre 0.0 y 1.0.\n";
            std::cout << " [!] R*, ne y L_max no pueden ser negativos.\n";
            std::cout << RESET;

            return false;
        }

        return true;
    }

    // Calcular longevidad efectiva
    double calcularLongevidadEfectiva() const {
        double L_efectiva =
            L_max *
            (1.0 - f_aut) *
            (1.0 - f_ext);

        return (L_efectiva < 0) ? 0 : L_efectiva;
    }

    // Calcular N
    double calcularN() const {
        return R_star *
               fp *
               ne *
               fl *
               fi *
               fc *
               calcularLongevidadEfectiva();
    }

    // Mostrar resultados
    void mostrarResultados() const {
        double L_esperada = calcularLongevidadEfectiva();
        double N = calcularN();

        std::cout << "\n";
        std::cout << AMARILLO;
        std::cout << " =====================================================\n";
        std::cout << "                 RESUMEN DEL ANALISIS\n";
        std::cout << " =====================================================\n";
        std::cout << RESET;

        std::cout << "  * Longevidad promedio real (L):     "
                  << L_esperada << " anos.\n";

        std::cout << "  * Civilizaciones activas (N):       "
                  << N << "\n";

        std::cout << AMARILLO;
        std::cout << " =====================================================\n";
        std::cout << RESET;

        std::cout << "\n";

        std::cout << AMARILLO;
        std::cout << " [CONCLUSION EN BASE AL MODELO]:\n";
        std::cout << RESET;

        if (N < 1.0) {

            std::cout << ROJO;

            std::cout
                << "  Alerta: Los filtros de extincion son demasiado severos.\n"
                << "  Las civilizaciones se extinguen antes de poder coexistir\n"
                << "  o establecer contacto en el tejido espacio-temporal.\n";

            std::cout << RESET;

        } else {

            std::cout << VERDE;

            std::cout
                << "  A pesar de los riesgos cosmicos y existenciales,\n"
                << "  la ventana de persistencia permite la coexistencia\n"
                << "  simultanea de unas "
                << static_cast<int>(N)
                << " civilizaciones en la galaxia.\n";

            std::cout << RESET;
        }

        std::cout << AMARILLO;
        std::cout << " =====================================================\n";
        std::cout << RESET;
    }
};

int main() {

    CalculadoraDrake calculadora;

    // Configuración de la terminal Linux
    calculadora.cambiarTituloTerminal();

    // Formateo de decimales
    std::cout << std::fixed << std::setprecision(4);

    // Limpiar pantalla
    calculadora.limpiarPantalla();

    // Mostrar interfaz
    calculadora.mostrarBanner();

    // Pedir datos
    calculadora.pedirDatos();

    // Validar y calcular
    if (calculadora.validarDatos()) {
        calculadora.mostrarResultados();
    }

    std::cout << "\n";

    // Pausa Linux
    calculadora.pausar();

    return 0;
}
