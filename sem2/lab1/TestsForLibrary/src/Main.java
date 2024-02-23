import com.GraphLibrary.Graph;

public class Main {
    public static void main(String[] args) {
        Graph graph = new Graph("First");

        System.out.println("Тест добавления вершин");

        graph.addVertex("$$$");
        graph.addVertex("1");
        graph.addVertex("bimbimbombom");
        graph.addVertex("1");
        graph.addVertex("Claire");
        graph.addVertex("C++");
        graph.addVertex("First");
        graph.addVertex("Second");

        System.out.println("Тест удаления вершин");

        graph.deleteVertex("bimbimbombom");
        graph.deleteVertex("q");
        graph.deleteVertex("bimbimbombom");

        System.out.println("Тест добавления дуг");

        graph.addArc("$$$", "Second");
        graph.addArc("$$$", "First");
        graph.addArc("$$$", "Second");

        System.out.println("Тест удаления дуг");

        graph.deleteArc("$$$", "Second");
        graph.deleteArc("First", "$$$");
        graph.deleteArc("$$$", "C++");

        System.out.println("Тест построения дерева обхода в глубину");

        graph.addArc("First", "$$$");
        graph.addArc("First", "C++");
        graph.addArc("C++", "1");
        graph.addArc("$$$", "Claire");
        graph.addArc("$$$", "Second");

        graph.DFSTree();


    }
}