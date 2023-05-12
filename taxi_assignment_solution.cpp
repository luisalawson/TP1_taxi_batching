#include "taxi_assignment_solution.h"

TaxiAssignmentSolution::TaxiAssignmentSolution() {}

//Inicializa todas las asignacion en -1 para indicar que todavia no se hicieron
TaxiAssignmentSolution::TaxiAssignmentSolution(int n) {
    this->_n = n;
    this->_taxi_assignment = std::vector<int>(n, -1);
    this->_pax_assignment = std::vector<int>(n, -1);
}

//Devuelve la cantidad de Taxis/Pasajeros
int TaxiAssignmentSolution::getN() const {
    return this->_n;
}

//Asigna un Taxi a un Pasajero
void TaxiAssignmentSolution::assign(int taxi, int pax) {
    this->_taxi_assignment[taxi] = pax;
    this->_pax_assignment[pax] = taxi;
}

//Checkea que un Taxi haya sido asignado
bool TaxiAssignmentSolution::isTaxiAssigned(int taxi) const {
    return this->_taxi_assignment[taxi] != -1;
}

//Checkea que a un Pasajero ya se le haya asignado un Taxi
bool TaxiAssignmentSolution::isPaxAssigned(int pax) const {
    return this->_pax_assignment[pax] != -1;
}

//Dado un Taxi, obtener el Pasajero al cual se lo asigno
int TaxiAssignmentSolution::getAssignedPax(int taxi) const {
    return this->_taxi_assignment[taxi];
}

////Dado un Pasajero, obtener el Taxi que se le asigno
int TaxiAssignmentSolution::getAssignedTaxi(int pax) const {
    return this->_pax_assignment[pax];
}

std::ostream& operator<<(std::ostream& os, const TaxiAssignmentSolution& solution) {
    os << "paxs: ";
    for (int i = 0; i < solution.getN(); i++)
        os << solution.getAssignedPax(i) << " ";
    os << std::endl;
    os << "taxis: ";
    for (int i = 0; i < solution.getN(); i++)
        os << solution.getAssignedTaxi(i) << " ";
    os << std::endl;
    os << "taxi \t --> \t pax" << std::endl;
    for (int i = 0; i < solution.getN(); i++) {
        os << i << " \t --> \t" << solution.getAssignedPax(i) << std::endl;
    }

    return os;
}

