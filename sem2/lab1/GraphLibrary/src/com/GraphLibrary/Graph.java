package com.GraphLibrary;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Queue;

public class Graph {
    ArrayList<ArrayList<String>> adjacency;
    Hashtable<String, Integer> indexes;

    public Graph() {
        adjacency = new ArrayList<ArrayList<String>>();
        adjacency.add(new ArrayList<String>());

        adjacency.get(0).add("Main");

        indexes = new Hashtable<>();
        indexes.put("Main", 0);
    }

    public Graph(String name) {
        adjacency = new ArrayList<ArrayList<String>>();
        adjacency.add(new ArrayList<String>());

        adjacency.get(0).add(name);

        indexes = new Hashtable<>();
        indexes.put(name, 0);
    }

    public void addVertex(String name) {
        adjacency.add(new ArrayList<String>());
        adjacency.get(adjacency.size() - 1).add(name);

        indexes.put(name, adjacency.size() - 1);
    }

    public void addEdge(String first, String second) {
        adjacency.get(indexes.get(first)).add(second);
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

    public Queue<String> addNeighbours(String nameOfActuallyVertex, Queue<String> before, ArrayList<String> protect) {

        for (int i = 1; i < adjacency.get((indexes.get(nameOfActuallyVertex))).size(); i++) {
            if (protect.contains(adjacency.get((indexes.get(nameOfActuallyVertex))).get(i)))
                continue;
            before.add(adjacency.get((indexes.get(nameOfActuallyVertex))).get(i));
        }

        return before;
    }

    public ArrayDeque<String> getFirstElement() {
        ArrayDeque<String> q = new ArrayDeque<>();

        q.add(adjacency.get(0).get(0));

        return q;
    }
}
