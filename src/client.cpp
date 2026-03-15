#include <iostream>
#include <exception>
// Подключаем заголовочный файл библиотеки
#include "CoolProp.h"

int main() {
    std::cout << "Starting...\n";
    try {
        // Расчет точки росы для пропана при 1600 кПа
        double pressure = 1600000.0;
        double vapor_quality = 1.0;
        
        double T_dew_K = CoolProp::PropsSI("T", "P", pressure, "Q", vapor_quality, "Propane");
        double T_dew_C = T_dew_K - 273.15;
        
        std::cout << "Dew point temperature: " << T_dew_C << " C\n";
    } catch (const std::exception& e) {
        std::cerr << "Thermodynamic backend error: " << e.what() << '\n';
    }
    
    std::cout << "Done!";
    getchar();
    return 0;
}