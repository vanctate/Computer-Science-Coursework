/*
	- Patrick Tate
	- CSCI 3761 Lab 3
	- program runs and compiles on csegrid
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

/* FUNCTIONS */
void start_program();
void mst(string fileName);
/* FUNCTIONS */

/* STRUCTS */
struct disj_sets {

    int *parent, *rank;
    int n;

    disj_sets(int n);

    // find the path
    int find(int node);
    // Union by rank
    void merge(int x, int y);

};

// int pairs
typedef  pair<int, int> iPair;

// struct for a Graph
struct Graph
{
    int vertex;
    vector< pair<int, iPair> > edges;

    // Constructor
    Graph(int vertex) {
        this->vertex = vertex;
    }

    // adding an edge
    void add_edge(int firstNode, int secondNode, int weight) {
        edges.push_back({weight, {firstNode, secondNode}});
    }

    // Kruskal's algo for mst
    int kruskal_algo(int print);
};

struct cons {
    int first;
    int second;
};
/* STRUCTS */

int main()
{
    start_program();
    return 0;
}

disj_sets::disj_sets(int n) {

    this->n = n;
    parent = new int[n+1];
    rank = new int[n+1];

    // all vertices have rank 0 and in different sets to begin
    for (int i = 0; i <= n; i++) {
        rank[i] = 0;
        parent[i] = i;
    }
}

// find parent nodes
int disj_sets::find(int node) {
    if (node != parent[node])
        parent[node] = find(parent[node]);
    return parent[node];
}

// union the disj sets and rank
void disj_sets::merge(int x, int y)
{
    x = find(x);
    y = find(y);

    // create subtree
    if (rank[x] > rank[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (rank[x] == rank[y])
        rank[y]++;
}

//ask for user input function
void start_program() {
    string inFile = "";

    cout << endl << "Enter the filename, including the extension\n";
    cin >> inFile;
    mst(inFile);
}

// load input file
void mst(string fileName){

    // variables to measure program run time
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    int vectorInt = 0;
    string vectorString;

    int firstNode = 0;
    int secondNode = 0;
    int weight = 0;
    string firstNodeString;
    string secondNodeString;
    string weightString;

    fstream inFile;
    inFile.open(fileName);

    // if file fails to open, exit program
    if (!inFile) {
        cerr << "*** Error: could not open filename: " << fileName << " ***" << "\n\n";
        exit(1);
    }

    getline(inFile, vectorString);
    stringstream geek0(vectorString);
    geek0 >> vectorInt;

    Graph g(vectorInt);

    while (getline(inFile, firstNodeString, ' ')) {
        getline(inFile, secondNodeString, ' ');
        getline(inFile, weightString);

        //conversions
        stringstream geek1(firstNodeString);
        geek1 >> firstNode;
        stringstream geek2(secondNodeString);
        geek2 >> secondNode;
        stringstream geek3(weightString);
        geek3 >> weight;

        //store data into graph
        g.add_edge(firstNode, secondNode, weight);

    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << endl << "Program run time = " << elapsed_seconds.count() * 1000 << " ms\n";

    int mst_wt = g.kruskal_algo(0);
    cout << "Minimum Cost = " << mst_wt << endl;

    cout << "MST (Minimum Spanning Tree) (T): ";
    g.kruskal_algo(1);
    cout << endl << endl;

}

/* Functions returns weight of the MST*/
int Graph::kruskal_algo(int print)
{
    int mstWeight = 0; // Initialize result

    // sort edges based on cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    disj_sets ds(vertex);

    vector< pair<int, iPair> >::iterator it;
    vector<cons> c;
    cons pairs;

    for (it = edges.begin(); it != edges.end(); it++) {
        int firstNode = it->second.first;
        int secondNode = it->second.second;

        int firstNodeSet = ds.find(firstNode);
        int secondNodeSet = ds.find(secondNode);

        // check for cycles
        if (firstNodeSet != secondNodeSet)
        {
            pairs.first = firstNode;
            pairs.second = secondNode;
            c.push_back(pairs);

            mstWeight += it->first;
            ds.merge(firstNodeSet, secondNodeSet);
        }
    }
    // print results
    if (print == 1) {
        for (int i = 0; i < c.size(); i++) {
            cout <<"(" << c[i].first << "," << c[i].second << ")";
            if (i != c.size() - 1)
                cout << " -> ";
        }
    }

    return mstWeight;
}
