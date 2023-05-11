#include "greedy_solver.h"

//Implementar la solución que se corresponde con la estrategia FCFS. 
//Para ello, completar la clase GreedySolver, que toma una instancia y 
//resuelve el problema con la estrategia FCFS. Esta clase debe guardar 
//la información respecto al valor de la función objetivo, tiempo de resolución, 
//y la solución a implementar usando la clase TaxiAssignmentSolution, ya implementada.

GreedySolver::GreedySolver() {}

GreedySolver::GreedySolver(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
    this->_objective_value = 0;
    this->_solution_status = 0;
    this->_solution_time = 0;
}

void GreedySolver::setInstance(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
}

void GreedySolver::solve() {
    //inicializo mis cantidades (como siempre son iguales van a tener el mismo valor)
    int numTaxis, numPaxs = _instance.n;
    //solucion inicializar con -1 como valor arbitrario para indicar que no hay solucion todavia 
    //es de tipo TaxiAssignmentSolution
    TaxiAssignmentSolution solution(numTaxis);
    for (int i = 0; i < numTaxis; i++) {
        solution.assign(i, -1);
    }
    // veo los pasajeros y agarro el primer taxi que vea 
    for (int pax = 0; pax < numPaxs; pax++) {
        //primera instancia: llega el pasajero pero no tiene auto
        bool asignado = false;
        //veo si los taxis estan vacios
        for (int taxi = 0; taxi < numTaxis; taxi++) {
            //si el taxi no tiene un pasajero, lo lleno
            if (!solution.isTaxiAssigned(taxi)) {
                solution.assign(taxi, pax);
                asignado = true;
                break;
            }
        }
        //si no encontre un taxi, aviso que el pasajero no tiene taxi
        if (!asignado) {
            solution.assign(-1, pax);
        }
    }
    //objective value?
    _solution = solution;
    _solution_status = 1; 
}

double GreedySolver::getObjectiveValue() const {
    return this->_objective_value;
}

TaxiAssignmentSolution GreedySolver::getSolution() const {
    return this->_solution;
}

int GreedySolver::getSolutionStatus() const {
    return this->_solution_status;
}

double GreedySolver::getSolutionTime() const {
    return this->_solution_time;
}






