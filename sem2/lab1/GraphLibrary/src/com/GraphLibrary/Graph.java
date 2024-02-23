package com.GraphLibrary;

import java.util.Stack;
import java.util.ArrayList;
import java.util.Hashtable;

public class Graph {
    ArrayList<ArrayList<String>> adjacency;
    Hashtable<String, Integer> indexes;
    int countOfTable = 0;

    public Graph(String name) {
        adjacency = new ArrayList<>();
        adjacency.add(new ArrayList<>());

        adjacency.get(0).add(name);

        indexes = new Hashtable<>();
        indexes.put(name, countOfTable);

        countOfTable++;
    }

    public void addVertex(String name) {
        if (!indexes.containsKey(name)) {
            adjacency.add(new ArrayList<>());
            adjacency.get(adjacency.size() - 1).add(name);

            indexes.put(name, countOfTable);

            countOfTable++;

            System.out.println("Добавлена вершина " + name);
        } else {
            System.out.println("Вершина с таким название уже имеется");
        }
    }

    public void addEdge(String first, String second) {
        if (!adjacency.get(indexes.get(first)).contains(second)) {
            if (indexes.containsKey(first) && indexes.containsKey(second)) {
                adjacency.get(indexes.get(first)).add(second);
                adjacency.get(indexes.get(second)).add(first);

                System.out.println("Дабавлено ребро между " + first + " и " + second);
            } else {
                System.out.println("Данные введены некорректно");
            }
        } else {
            System.out.println("Такое ребро уже имеется");
        }
    }

    public void printAdjacencyList() {
        for (ArrayList<String> strings : adjacency) {
            if (strings.contains(null))
                continue;
            System.out.println("Adjacency list of " + strings.get(0));

            for (int j = 1; j < strings.size(); j++) {
                System.out.println(strings.get(j) + " ");
            }

            System.out.print("_____________________\n");
        }
    }

    public void deleteVertex(String nameOfVertex) {
        if (indexes.containsKey(nameOfVertex)) {
            int index = indexes.get(nameOfVertex);

            for (int i = 1; i < adjacency.get(index).size(); i++) {
                int tempIndex = indexes.get(adjacency.get(index).get(i));

                adjacency.get(tempIndex).remove(nameOfVertex);
            }

            adjacency.get(index).set(0, null);
            indexes.remove(nameOfVertex);


            System.out.println("Удалена вешина " + nameOfVertex);
        } else {
            System.out.println("Данные введены некорректно");
        }
    }

    public void addArc(String fromVertexName, String toVertexName) {
        if (!adjacency.get(indexes.get(fromVertexName)).contains(toVertexName)) {
            System.out.println("Добавлена дуга из " + fromVertexName + " в " + toVertexName);

            adjacency.get(indexes.get(fromVertexName)).add(toVertexName);
        } else {
            System.out.println("Эти вершины уже связаны");
        }
    }

    public void deleteArc(String fromVertexName, String toVertexName) {
        if (adjacency.get(indexes.get(fromVertexName)).contains(toVertexName)) {

            System.out.println("Удалена дуга из " + fromVertexName + " в " + toVertexName);

            adjacency.get(indexes.get(fromVertexName)).remove(toVertexName);
        } else {
            System.out.println("Данные введены некорректно");
        }
    }

    public void DFSTree() {
        Stack<String> stack = new Stack<>();
        Hashtable<String, String> loopProtection = new Hashtable<>();
        int i = 2;

        stack.push(adjacency.get(0).get(0));

        while (!stack.isEmpty()) {
            i = 2;
            String temp = stack.pop();
            loopProtection.put(temp, "Verified");

            if (adjacency.get(indexes.get(temp)).size() > 2) {
                System.out.print("\nВершина " + temp + " продолжается в ");
                System.out.print("\n");
            }

            if (indexes.get(temp) == 0)
                i = 1;

            for (; i < adjacency.get(indexes.get(temp)).size(); i++) {

                System.out.print(adjacency.get(indexes.get(temp)).get(i) + " ");

                if (!loopProtection.containsKey(adjacency.get(indexes.get(temp)).get(i)))
                    stack.push(adjacency.get(indexes.get(temp)).get(i));
            }
        }
    }
}
