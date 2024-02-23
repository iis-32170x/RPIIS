import com.GraphLibrary.Graph;

public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph("1");
        graph.addVertex("2");
        graph.addVertex("3");
        graph.addVertex("4");
        graph.addVertex("5");
        /*
        graph.addVertex("Claire");
        graph.addVertex("C++");
        graph.addVertex("First");
        graph.addVertex("Second");
        graph.addEdge("Alise", "Antony");
        graph.addEdge("Alise", "Bob");
        graph.addEdge("Alise", "Jhon");
        graph.addEdge("Alise", "Marat");
        graph.addEdge("Antony", "C++");
        graph.addEdge("Bob", "Claire");
        graph.addEdge("Claire", "First");
        graph.addEdge("Claire", "Second");
        graph.addEdge("Alise", "Second");
        graph.addEdge("Alise", "First");
        graph.addEdge("Alise", "C++");
        graph.printAdjacencyList();
        */

        graph.addEdge("1", "2");
        graph.addEdge("1", "3");
        graph.addEdge("2", "4");
        graph.addEdge("2", "5");
        graph.addEdge("5", "1");
        graph.addEdge("5", "1");

       // graph.printAdjacencyList();
        //graph.DFSTree();
    }
}