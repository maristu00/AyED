#include <iostream>

/*
Elabore una funcion para registro académico Ayed, que solicite Numero de curso y sus
correspondientes notas de periodo.  Cuto prototipo es
int registroAcademico(int(int, int, int, int,int, int, int)
Curso, 1er Parcial, 2do Parcial, 1er Rec 1er P,2do R 1erP, 2do Rec 1er P, 2do R 2doP.
Cero en nota es ausente. Retorna 1..4: promcion, aprobado, no aprobado, ausente
*/

int registroAcademico(int Curso, int p1, int p2, int r1p1, int r2p1, int r1p2, int r2p2) {
    int promedio1 = (p1 + p2 + r1p1 + r2p1 + r1p2 + r2p2) / 6;
    if (promedio1 >= 6) {
        return 1;
    } else if (promedio1 >= 5) {
        return 2;
    } else if (promedio1 >= 4) {
        return 3;
    } else {
        return 4;
    }
}


/*
Elabore una funcion que reciba tres valores enteros que representan un dia, 
un mes y un año de una fecha del siglo 20 o 21  y retorne fecha valida?1:0;
*/

int fechaValida(int dia, int mes, int anio) {

    // Primero valido anio que se encuentre en siglo 20 o 21
    if (anio < 1901 || anio > 2099) {
        return 0;
        }
    // Valido mes
    if (mes < 1 || mes > 12) {
        return 0;
    }
    // Valido dia
    if (dia < 1 || dia > 31) {
        return 0;
    } else {
        return 1;
    }
}



/*
Elabore una funcion que reciba tres valores enteros que representan un dia,
 un mes y un año de una fecha valida  del siglo 20 o 21  un entero fecha de la forma AAAAMMDD
*/

int fechaValidaV2(int dia, int mes, int anio) {

    if (fechaValida(dia, mes, anio) == 1) {
        return anio * 10000 + mes * 100 + dia;
    } else {
        return 0;
    }
}

/* 
Elabore una funcion que reciba una fecha valida  del siglo 20 o 21  
y la descompoga en sus componentes dia, mes y año y devuelva los valores
*/

void descomponerFecha(int fecha, int &dia, int &mes, int &anio) {
    anio = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = fecha % 100;
}


/* 
Desarrollo una funcion que reciba el sueldo bruto de un empleado (float) y retorne el sueldo neto. Considere las siguientes restricciones 
Cada empleado tiene un Nivel (0, 1, 2, 3) y un Sueldo Base (SB).
1. Se le aplican los descuentos de Ley: ISSS (3.1%) y Ganancias (9.3%).
2. Si el Nivel de empleado es 2 o 3, se descuenta el 11.4% del SB en concepto de Seguro 
3. Según el Nivel del empleado se le calcula un Bono (por el esfuerzo hecho) sobre el SB así:
• Nivel 0: un importe fijo en pesos
• Nivel 1: 6.4% del SB
• Nivel 2: 13.94% del SB
• Nivel 3: 21.04% del SB
Defina los patametros y su tipo para una correcta definicion de la funcion
*/

float sueldoNeto(float sueldoBruto, int nivel, float sueldoBase) {
    float sueldoNeto = sueldoBruto - (sueldoBruto * 0.031) - (sueldoBruto * 0.093);
    if (nivel == 2 || nivel == 3) {
        sueldoNeto -= sueldoBase * 0.114;
    }
    if (nivel == 0) {
        sueldoNeto += 100;
    } else if (nivel == 1) {
        sueldoNeto += sueldoBase * 0.064;
    } else if (nivel == 2) {
        sueldoNeto += sueldoBase * 0.1394;
    } else if (nivel == 3) {
        sueldoNeto += sueldoBase * 0.2104;
    }
    return sueldoNeto;
}

/* 

Desarrolle la funcion void potencia(int) que genere en pantalla la tabla de potencias del numero decimal N [1..4] recibido como parámetro. 
Recuerde A n = A * A N-1
Considere las siguientes restricciones
Restricciones:
✔	La base N a recibir en el parámetro solo puede variar entre 1 a 4.
✔	Ante cualquier numero fuera de este rango, la función solo mostrara en
✔	pantalla al mensaje:“ERROR, imposible generar tabla de potencia requerida”
✔	Solo se puede usar operadores de suma (+), resta (-) o los operadorescortos (++ o --). No puede usar al operador de producto (*)
✔	Puede crear otras funciones complementarias a la función solicitada.
*/

void potencia(int N) {
    if (N < 1 || N > 4) {
        std::cout << "ERROR, imposible generar tabla de potencia requerida" << std::endl;
    } else {
        int potencia = 1;
        for (int i = 1; i <= 10; i++) {
            std::cout << N << " ^ " << i << " = " << potencia << std::endl;
            potencia += N;
        }
    }
}

/*
La función trigonométrica Seno de un anguloX se puede calcular por la sumatoria de la siguiente serie infinita de términos:
En donde el angulo x de la formula debe serproporcionado en grados radianes.
Desarrolle una función denominada Seno( ) con los siguientes parámetros: medida del angulo. Y el tipo semedida de angulo (‘s’: grado sexagesimal o ‘r’: grado radian) se
Restricciones:
Para obtener un resultado con una alta precisión, debe utilizar una sumatoria de 12 términos de la serie dada y utilizar tipos de datos decimales de doble precisión (double).
Solo pueden definirse variables de alcance local.
Puede crear otras funciones complementarias a la función Seno solicitada.
*/

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int pow(int base, int exponente) {
    int resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

void seno(double angulo, char tipo) {
    double seno = 0;
    if (tipo == 's') {
        angulo = angulo * 3.1416 / 180;
    }
    for (int i = 0; i < 12; i++) {
        seno += (pow(-1, i) / factorial(2 * i + 1)) * pow(angulo, 2 * i + 1);
    }
    std::cout << "Seno de " << angulo << " = " << seno << std::endl;
}

/* 
Desarrolle una funcion Primos, que genere en pantalla al listado de numeros primos ubicados
entre 1 hasta un numero X (recibido como parametro).
Restricciones:
Puede crear otras funciones complementarias a la función principal (ListaPrimos) solicitada.
*/

void primos(int X) {
    for (int i = 1; i <= X; i++) {
        int contador = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                contador++;
            }
        }
        if (contador == 2) {
            std::cout << i << std::endl;
        }
    }
}

int main(){
    std::cout << "Registro Academico: " << registroAcademico(1, 10, 10, 10, 10, 10, 10) << '\n' << std::endl;
    std::cout << "Fecha Valida: " << fechaValida(31, 12, 2021) << '\n' << std::endl;
    std::cout << "Fecha Valida V2: " << fechaValidaV2(31, 12, 2021) << '\n' << std::endl;
    int dia, mes, anio;
    descomponerFecha(20211231, dia, mes, anio);
    std::cout << "Descomponer Fecha: " << dia << "/" << mes << "/" << anio << '\n' <<std::endl;
    std::cout << "Sueldo Neto: " << sueldoNeto(1000, 3, 1000) << '\n' << std::endl;
    potencia(2);
    seno(90, 's');
    primos(10);
    return 0;
}

// Para compilar, g++ manu.cpp -o manu
