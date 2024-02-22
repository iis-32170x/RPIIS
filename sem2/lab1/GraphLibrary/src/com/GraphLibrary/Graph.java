package com.GraphLibrary;

import java.util.ArrayList;
import java.util.Hashtable;

public class Graph {
    ArrayList<ArrayList<String>> adjacency;
    Hashtable<String, Integer> indexes;
    int countOfTable = 0;

    public Graph() {
        adjacency = new ArrayList<ArrayList<String>>();
        adjacency.add(new ArrayList<String>());

        adjacency.get(0).add("Main");

        indexes = new Hashtable<>();
        indexes.put("Main", countOfTable);

        countOfTable++;
    }

    public Graph(String name) {
        adjacency = new ArrayList<ArrayList<String>>();
        adjacency.add(new ArrayList<String>());

        adjacency.get(0).add(name);

        indexes = new Hashtable<>();
        indexes.put(name, countOfTable);

        countOfTable++;
    }

    public void addVertex(String name) {
        adjacency.add(new ArrayList<String>());
        adjacency.get(adjacency.size() - 1).add(name);

        indexes.put(name, countOfTable);

        countOfTable++;
    }

    public void addEdge(String first, String second) {
        adjacency.get(indexes.get(first)).add(second);
        adjacency.get(indexes.get(second)).add(first);
    }

    public void printAdjacencyList() {
        for (ArrayList<String> strings : adjacency) {
            System.out.println("Adjacency list of " + strings.get(0));

            for (int j = 1; j < strings.size(); j++) {
                System.out.println(strings.get(j) + " ");
            }

            System.out.println();
        }
    }

    public void deleteVertex(String nameOfVertex) {
        int index = indexes.get(nameOfVertex);

        for (int i = 1; i < adjacency.get(index).size(); i++) {
            int tempIndex = indexes.get(adjacency.get(index).get(i));

            adjacency.get(tempIndex).remove(nameOfVertex);
        }

        adjacency.remove(index);
    }
}
