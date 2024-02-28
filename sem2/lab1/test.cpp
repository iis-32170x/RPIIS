#include <gtest/gtest.h>
#include "pch.h"
#include "../Undirected graph/undirectedGraph.h"

TEST(NgraphTest, AddVertex) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    EXPECT_TRUE(graph.VertexExists(1));
    EXPECT_TRUE(graph.VertexExists(2));
    EXPECT_TRUE(graph.VertexExists(3));
    EXPECT_FALSE(graph.VertexExists(0));
}

TEST(NgraphTest, AddEdge) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    EXPECT_TRUE(graph.EdgeExists(1, 2));
    EXPECT_TRUE(graph.EdgeExists(2, 1));
    EXPECT_TRUE(graph.EdgeExists(2, 3));
    EXPECT_FALSE(graph.EdgeExists(1, 3));
}

TEST(NgraphTest, DeleteVertex) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    graph.DeleteVertex(2);

    EXPECT_FALSE(graph.VertexExists(2));
    EXPECT_FALSE(graph.EdgeExists(1, 2));
    EXPECT_FALSE(graph.EdgeExists(2, 3));
}

TEST(NgraphTest, DeleteEdge) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    graph.DeleteEdge(1, 2);

    EXPECT_FALSE(graph.EdgeExists(1, 2));
    EXPECT_FALSE(graph.EdgeExists(2, 1));
    EXPECT_TRUE(graph.EdgeExists(2, 3));
}

TEST(NgraphTest, DFSTreeTest) {
    Ngraph graph;

    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    testing::internal::CaptureStdout();
    graph.DFSTree(1);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "1 2 3 \n");
}