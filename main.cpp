#include "taxi_assignment_instance.h"
#include "taxi_assignment_solution.h"
#include "checker.h"
#include "greedy_solver.h"


int main(int argc, char** argv) {
    std::string filename = "input/xl_0.csv";

    TaxiAssignmentInstance instance(filename);
    std::cout << filename << std::endl;

    TaxiAssignmentSolution solution(instance.n);

    GreedySolver solver(instance);

    solver.solve();

    TaxiAssignmentSolution solucion = solver.getSolution();
    
    //devuelve las asignaciones de los taxis
    for (int i = 0; i < instance.n; i++) {
        std::cout <<"El taxi " << i <<  " fue asignado al pasajero " << solucion.getAssignedPax(i) << std::endl;
    };

    std::cout << "El estado de la solucion es: " << solver.getSolutionStatus() << std::endl;

    std::cout << "El tiempo de ejecucion es: " << solver.getSolutionTime() << std::endl;

    return 0;
}