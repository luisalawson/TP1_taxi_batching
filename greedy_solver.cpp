#include "greedy_solver.h"
#include <limits>
using namespace std;
#include <ctime>
#include <chrono>

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

    //guardo tiempo inicial
    auto start_time = std::chrono::high_resolution_clock::now();
    int cantTaxis = _instance.n;
    int cantPaxs = _instance.n;

    //inicializa la solucion asignando -1 a las asignaciones de los taxis y pasajeros.
    TaxiAssignmentSolution solution(cantTaxis);

    for (int pax = 0; pax < cantPaxs; pax++) {
        bool asignado = false;
        int minTaxi = -1; // Variable para almacenar el taxi más cercano
        double minDist = std::numeric_limits<double>::max(); // Distancia mínima inicializada con el máximo valor posible
        //Recorro la matriz fijando el pasajero buscando el taxi mas cercano al mismo
        for (int taxi = 0; taxi < cantTaxis; taxi++) {
            double dist = _instance.dist[taxi][pax];
            //Si el taxi no esta asignado y tiene menor distancia que el minimo, actualizo minDist y minTaxi.
            if (!solution.isTaxiAssigned(taxi) && dist < minDist) {
                minDist = dist;
                minTaxi = taxi;
            }
        }
        //si encontre un taxi, lo asigno. Si no, dejo el -1 asignado previamente.
        if (minTaxi != -1) {
            solution.assign(minTaxi, pax);
            asignado = true;
        }
        this->_objective_value = this->_objective_value + minDist;
    }

    //guardo la solucion y cambio el status
    this->_solution = solution;
    this->_solution_status = 1;

    //defino tiempo final y calculo el tiempo de ejecucion en milisegundos
    auto end_time = std::chrono::high_resolution_clock::now();
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    cout << "Tiempo de ejecucion: " << time << " ms" << endl;
    cout << "Kilometros recorridos: " << this->_objective_value << "km "<< endl;
    //guardo el tiempo de ejecucion (milisegundos)
    this->_solution_time = time;
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






