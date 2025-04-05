typedef struct  {
    unsigned long id; // tam suficiente; sera nuestro punto de busqueda; tambien se puede implementar para credito o debito
    char tipo_transaccion[255];
    double monto;
} s_interbank_data;