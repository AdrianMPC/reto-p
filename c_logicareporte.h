#include "./s_data.h"

class LogicaNegocio{
    private:
        double m_balance_final;
        double m_monto_mayor;
        unsigned long m_id_montomayor;
        int m_conteo_credito;
        int m_conteo_debito;
    public:
        LogicaNegocio();
        void evaluar_data(s_interbank_data*);
        void generar_reporte();
};