import com.GraphLibrary.Graph;

public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph("First");

        graph.addVertex("$$$");
        graph.addVertex("bimbimbombom");
        graph.addVertex("1");
        graph.addVertex("Claire");
        graph.addVertex("C++");
        graph.addVertex("Second");

        graph.addArc("First", "$$$");
        graph.addArc("First", "C++");
        graph.addArc("C++", "1");
        graph.addArc("$$$", "Claire");
        graph.addArc("$$$", "Second");

        graph.DFSTree();
    }
}