#include "greedy_solver.h"
#include <limits>


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

//Codigo anterior
// void GreedySolver::solve() {
//     //inicializo mis cantidades (como siempre son iguales van a tener el mismo valor)
//     int cantTaxis, cantPaxs = _instance.n;
//     //solucion inicializar con -1 como valor arbitrario para indicar que no hay solucion todavia 
//     //es de tipo TaxiAssignmentSolution
//     TaxiAssignmentSolution solution(cantTaxis);
//     //Los taxis todavia no tienen pasajero ==> estan en -1
//     for (int i = 0; i < cantTaxis; i++) {
//         solution.assign(i, -1);
//     }
//     // veo los pasajeros y agarro el primer taxi que vea 
//     for (int pax = 0; pax < cantPaxs; pax++) {
//         //primera instancia: llega el pasajero pero no tiene auto
//         bool asignado = false;
//         //veo si los taxis estan vacios
//         //*agregar* que sea el taxi que este mas cerca
//         for (int taxi = 0; taxi < cantTaxis; taxi++) {
//             //si el taxi no tiene un pasajero, lo lleno
//             int minTaxi = min(_instance.dist());
//             if (!solution.isTaxiAssigned(minTaxi)) {
//                 solution.assign(taxi, pax);
//                 asignado = true;
//             }
//         }
//         //si no encontre un taxi, aviso que el pasajero no tiene taxi
//         if (!asignado) {
//             solution.assign(-1, pax);
//         }
//     }
//     //objective value?
//     _solution = solution;
//     _solution_status = 1; 
// }

void GreedySolver::solve() {
    int cantTaxis, cantPaxs = _instance.n;

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
    }

    this->_solution = solution;
    this->_solution_status = 1;
    
    //falta guardar solution time

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






