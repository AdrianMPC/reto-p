#include "./c_logicareporte.h"

#include "iostream"

LogicaNegocio::LogicaNegocio()
{
    m_balance_final = 0;
    m_monto_mayor = 0;
    m_id_montomayor = 0;
    m_conteo_credito = 0;
    m_conteo_debito= 0;
}

void LogicaNegocio::evaluar_data(s_interbank_data* data){
    if(data->tipo_transaccion == "Crédito"){
        m_conteo_credito++;
        m_balance_final += data->monto;
    } 

    if(data->tipo_transaccion == "Débito"){
        m_conteo_debito++;
        m_balance_final -= data->monto;
    }

    if(data->monto > m_monto_mayor){
        m_monto_mayor = data->monto;
        m_id_montomayor = data->id;
    }
}

void LogicaNegocio::generar_reporte()
{
    std::cout<<"Reporte de Transacciones\n";
    std::cout<<"---------------------------------------------\n";
    std::cout<<"Balance Final: " << m_balance_final;
    std::cout<<"Transacción de Mayor Monto: ID " << m_id_montomayor << " - " << m_monto_mayor;
    std::cout<<"Conteo de Transacciones: Crédito: " << m_conteo_credito << " Débito: " << m_conteo_debito;
}
    