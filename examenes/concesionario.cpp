//examen concesionario (examen 2 wuolah)


//operadores  
#define NORMALPILOTO 1
#define DESPLAZADOPILOTO 2
#define NORMALCOPI 3
#define ABATIDOCOPI 4
#define DESPLAZADOCOPI 5
#define NORMALMIZQ 6
#define ABATIDOMIZQ 7
#define DESPLAZADOMIZQ 8
#define NORMALMCEN 9
#define ABATIDOMCEN 10
#define DESPLAZADOMCEN 11
#define NORMALMDER 12
#define ABATIDOMDER 13
#define DESPLAZADOMDER 14
#define NORMALATRASIZQ 15
#define ABATIDOATRASIZQ 16
#define DESPLAZADOATRASIZQ 17
#define NORMALATRASDER 18
#define ABATIDOATRASDER 19
#define DESPLAZADOATRASDER 20

//definicion del tEstado
typedef struct tEstado
{
    char asientos[3][3];
    int heuristica;
};

//definicion estado inicial
static char asientosInicial[3][3]=
{
    {3, 3, 0},
    {1, 1, 1},
    {2, 2, 0}
};

//definicion estado final
static char asientosFinal[3][3]=
{
    {1, 1, 0},
    {2, 2, 2},
    {1, 1, 0}
};

int testObjetivo (tEstado *estado)
{
    int boleano = 1;
    
    int i = 0, j = 0;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            boleano = (estado ->asientos[i][j] == asientosFinal[i][j]);

    return boleano;
}

int esValido (tEstado *estado, unsigned operador)
{
    int boleano = 1;

    switch (operador)
    {
        case NORMALPILOTO:
            if (estado -> asientos[0][0] == 1)      //esta primera comprobacion es la misma para todos los asientos
                boleano = 0;                        //mira si el asiento esta ya en posicion normal
            break;

        case DESPLAZADOPILOTO:
            if (estado -> asientos[1][0] != 1 || estado -> asientos[1][1] != 1) //comprueba que los asientos de detras (mizq y mmcen) esten normal
                boleano = 0;
            break;

        case NORMALCOPI:
            if (estado -> asientos[0][1] == 1)  
                boleano = 0;
            break;
        
        case ABATIDOCOPI:
            if (estado -> asientos[1][2] != 2)  //comprueba que el asiento de detras (mder) este abatido
                boleano = 0;
            break;

        case DESPLAZADOCOPI:
            if (estado -> asientos[1][2] != 1)
                boleano = 0;
            break;

        case NORMALMIZQ:
            if (estado -> asientos[1][0] == 1)
                boleano = 0;
            break;
        
        case ABATIDOMIZQ:
            if (estado -> asientos[1][0] != 1)  //estas y las sucesivas de abatido y desplazado son iguales porque comprueban que esten en posicion normal
                boleano = 0;
            break;

        case DESPLAZADOMIZQ:
            if (estado -> asientos[1][0] != 1)
                boleano = 0;
            break;

        case NORMALMCEN:
            if (estado -> asientos[1][1] == 1)
                boleano = 0;
            break;
        
        case ABATIDOMCEN:
            if (estado -> asientos[1][1] != 1)
                boleano = 0;
            break;

        case DESPLAZADOMCEN:
            if (estado -> asientos[1][1] != 1)
                boleano = 0;
            break;

        case NORMALMDER:
            if (estado -> asientos[1][2] == 1)
                boleano = 0;
            break;
        
        case ABATIDOMDER:
            if (estado -> asientos[1][2] != 1)
                boleano = 0;
            break;

        case DESPLAZADOMDER:
            if (estado -> asientos[1][2] != 1)
                boleano = 0;
            break;

        case NORMALATRASIZQ:
            if (estado -> asientos[2][0] == 1)
                boleano = 0;
            break;
        
        case ABATIDOATRASIZQ:
            if (estado -> asientos[2][0] != 1)
                boleano = 0;
            break;

        case DESPLAZADOATRASIZQ:
            if (estado -> asientos[2][0] != 1)
                boleano = 0;
            break;

        case NORMALATRASDER:
            if (estado -> asientos[2][1] == 1)
                boleano = 0;
            break;
        
        case ABATIDOATRASDER:
            if (estado -> asientos[2][1] != 1)
                boleano = 0;
            break;

        case DESPLAZADOATRASDER:
            if (estado -> asientos[2][1] != 1)
                boleano = 0;
            break;
        
        default:
            break;
    }

    return boleano;
}

void aplicaOperador (tEstado *estado, unsigned operador)
{

    switch (operador)
    {
        case NORMALPILOTO:
            if (esValido(estado, operador))
                estado -> asientos[0][0] = NORMALPILOTO;
            break;

        case DESPLAZADOPILOTO:
            if (esValido(estado, operador))
                estado -> asientos[0][0] = DESPLAZADOPILOTO;
            break;

        case NORMALCOPI:
            if (esValido(estado, operador))
                estado -> asientos[0][1] = NORMALCOPI;
            break;
        
        case ABATIDOCOPI:
            if (esValido(estado, operador))
                estado -> asientos[0][1] = ABATIDOCOPI;
            break;

        case DESPLAZADOCOPI:
            if (esValido(estado, operador))
                estado -> asientos[0][1] = DESPLAZADOCOPI;
            break;

        case NORMALMIZQ:
            if (esValido(estado, operador))
                estado -> asientos[1][0] = NORMALMIZQ;
            break;
        
        case ABATIDOMIZQ:
            if (esValido(estado, operador))
                estado -> asientos[1][0] = ABATIDOMIZQ;
            break;

        case DESPLAZADOMIZQ:
            if (esValido(estado, operador))
                estado -> asientos[1][0] = DESPLAZADOMIZQ;
            break;

        case NORMALMCEN:
            if (esValido(estado, operador))
                estado -> asientos[1][1] = NORMALMCEN;
            break;
        
        case ABATIDOMCEN:
            if (esValido(estado, operador))
                estado -> asientos[1][1] = ABATIDOMCEN;
            break;

        case DESPLAZADOMCEN:
            if (esValido(estado, operador))
                estado -> asientos[1][1] = DESPLAZADOMCEN;
            break;

        case NORMALMDER:
            if (esValido(estado, operador))
                estado -> asientos[1][2] = NORMALMDER;
            break;
        
        case ABATIDOMDER:
            if (esValido(estado, operador))
                estado -> asientos[1][2] = ABATIDOMDER;
            break;

        case DESPLAZADOMDER:
            if (esValido(estado, operador))
                estado -> asientos[1][2] = DESPLAZADOMDER;
            break;

        case NORMALATRASIZQ:
            if (esValido(estado, operador))
                estado -> asientos[2][0] = NORMALATRASIZQ;
            break;
        
        case ABATIDOATRASIZQ:
            if (esValido(estado, operador))
                estado -> asientos[2][0] = ABATIDOATRASIZQ;
            break;

        case DESPLAZADOATRASIZQ:
            if (esValido(estado, operador))
                estado -> asientos[2][0] = DESPLAZADOATRASIZQ;
            break;

        case NORMALATRASDER:
            if (esValido(estado, operador))
                estado -> asientos[2][1] = NORMALATRASDER;
            break;
        
        case ABATIDOATRASDER:
            if (esValido(estado, operador))
                estado -> asientos[2][1] = ABATIDOATRASDER;
            break;

        case DESPLAZADOATRASDER:
            if (esValido(estado, operador))
                estado -> asientos[2][1] = DESPLAZADOATRASDER;
            break;
        
        default:
            break;
    }
}

int calculaCoste (tEstado *estado, unsigned operador)
{
    int coste = 0;

    //coste = 1 si desplazar o volver a normal desde desplazado
    //coste = 2 si abatir o volver a normal desde abatido

    switch (operador)
    {
        case NORMALPILOTO:
            if (estado -> asientos [0][0] == DESPLAZADOPILOTO)
                coste = 1;
            break;

        case DESPLAZADOPILOTO:
            if (estado -> asientos [0][0] == NORMALPILOTO)
                coste = 1;
            break;

        case NORMALCOPI:
            if (estado -> asientos [0][1] == DESPLAZADOCOPI)
                coste = 1;
            else if (estado -> asientos [0][1] == ABATIDOCOPI)
                coste = 2;
            break;
        
        case ABATIDOCOPI:
            if (estado -> asientos [0][1] == NORMALCOPI)
                coste = 2;
            break;

        case DESPLAZADOCOPI:
            if (estado -> asientos [0][1] == NORMALCOPI)
                coste = 1;
            break;

        case NORMALMIZQ:
            if (estado -> asientos [1][0] == DESPLAZADOMIZQ)
                coste = 1;
            else if (estado -> asientos [1][0] == ABATIDOMIZQ)
                coste = 2;
            break;
        
        case ABATIDOMIZQ:
            if (estado -> asientos [1][0] == NORMALMIZQ)
                coste = 2;
            break;

        case DESPLAZADOMIZQ:
            if (estado -> asientos [1][0] == NORMALMIZQ)
                coste = 1;
            break;

        case NORMALMCEN:
            if (estado -> asientos [1][1] == DESPLAZADOMCEN)
                coste = 1;
            else if (estado -> asientos [1][1] == ABATIDOMCEN)
                coste = 2;
            break;
        
        case ABATIDOMCEN:
            if (estado -> asientos [1][1] == NORMALMCEN)
                coste = 2;
            break;

        case DESPLAZADOMCEN:
            if (estado -> asientos [1][1] == NORMALMCEN)
                coste = 1;
            break;

        case NORMALMDER:
            if (estado -> asientos [1][2] == DESPLAZADOMDER)
                coste = 1;
            else if (estado -> asientos [1][2] == ABATIDOMDER)
                coste = 2;
            break;
        
        case ABATIDOMDER:
            if (estado -> asientos [1][2] == NORMALMDER)
                coste = 2;
            break;

        case DESPLAZADOMDER:
            if (estado -> asientos [1][2] == NORMALMDER)
                coste = 1;
            break;

        case NORMALATRASIZQ:
            if (estado -> asientos [2][0] == DESPLAZADOATRASIZQ)
                coste = 1;
            else if (estado -> asientos [2][0] == ABATIDOATRASIZQ)
                coste = 2;
            break;
        
        case ABATIDOATRASIZQ:
            if (estado -> asientos [2][0] == NORMALATRASIZQ)
                coste = 2;
            break;

        case DESPLAZADOATRASIZQ:
            if (estado -> asientos [2][0] == NORMALATRASIZQ)
                coste = 1;
            break;

        case NORMALATRASDER:
            if (estado -> asientos [2][1] == DESPLAZADOATRASDER)
                coste = 1;
            else if (estado -> asientos [2][1] == ABATIDOATRASDER)
                coste = 2;
            break;
        
        case ABATIDOATRASDER:
            if (estado -> asientos [2][1] == NORMALATRASDER)
                coste = 2;
            break;

        case DESPLAZADOATRASDER:
            if (estado -> asientos [2][1] == NORMALATRASDER)
                coste = 1;
            break;
        
        default:
            break;
    }

    return coste;
}

void calculaHeuristica (tEstado *estado) //no se mubien como hacerlo
{

}

//expansion del arbol de busqueda en anchura hasta profundidad 2