cmake_minimum_required(VERSION 3.27)
project(AiZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AiZO2 main.cpp
        Helpers/Generator.cpp
        Helpers/Generator.h
        AdjacencyList/AdjacencyList.cpp
        AdjacencyList/AdjacencyList.h
        IncidenceMatrix/IncidenceMatrix.cpp
        IncidenceMatrix/IncidenceMatrix.h
        MST/Kruskal.cpp
        MST/Kruskal.h
        MST/Prim.cpp
        MST/Prim.h
        Structures/EdgeQueue.cpp
        Structures/EdgeQueue.h
        Structures/SimpleStructures.h
        SP/Dijkstry.cpp
        SP/Dijkstry.h
        Test/Test.cpp
        Helpers/Timer.h
        Simulation/Simulation.cpp
        Simulation/Simulation.h
        SP/BellmanFord.cpp
        SP/BellmanFord.h
        SP/BellmanFord.h)
