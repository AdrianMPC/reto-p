#include "./c_csvreader.h"
#include <fstream>
#include <sstream>

CSVreader::CSVreader(const std::string& p_narchivo, char p_delimitador)
{
    m_narchivo = p_narchivo;
    m_delimitador = p_delimitador;
}

std::vector<std::vector<std::string>> CSVreader::getData() const
{
    return m_data;
}

bool CSVreader::read()
{
    std::ifstream file(m_narchivo);
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line); // ignora la primer linea

    while (std::getline(file, line)) {
        if (!line.empty()){
            m_data.push_back(m_split(line, m_delimitador));
        }  
    }

    file.close();
    return true;
}

std::vector<std::string> CSVreader::m_split(const std::string& line, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}