#include "./c_dbmanager.h"

#include <iostream>
#include <cstring>

DBManager::DBManager(const std::string& p_archivoCSV, char p_delimitador, size_t p_hashSize)
: m_csvReader(p_archivoCSV, p_delimitador), m_hashTable(p_hashSize) {}
  
s_interbank_data* DBManager::m_parseRow(const std::vector<std::string>& fila) {
    if (fila.size() < 3) return nullptr;

    s_interbank_data* data = new s_interbank_data;

    data->id = std::stoul(fila[0]);

    strncpy(data->tipo_transaccion, fila[1].c_str(), sizeof(data->tipo_transaccion) - 1);
    data->tipo_transaccion[sizeof(data->tipo_transaccion) - 1] = '\0';

    data->monto = std::stod(fila[2]);

    return data;
}

bool DBManager::loadData() {
    if (!m_csvReader.read()) return false;

    for (const auto& fila : m_csvReader.getData()) {
        s_interbank_data* dato = m_parseRow(fila);
        if (dato) {
            m_hashTable.insertDataChunk(dato);
        }
    }

    return true;
}

s_interbank_data* DBManager::searchID(unsigned long id) {
    return m_hashTable.searchData(id);
}
