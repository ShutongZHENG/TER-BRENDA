# BRENDA Database Enzymatic Reaction Extractor

## Project Introduction
This project aims to create a tool to extract enzymatic reactions from the BRENDA database. The extractor should be able to find all possible paths from a given reactant to a specified product, considering a specific distance.

## Project Goals
- To help students become familiar with biochemical reactions, lexical and syntactic analysis methods, graph algorithms, parallel programming, and modular software design.
- To implement an efficient method to extract enzymatic reactions from the BRENDA database, using parallel approaches to accelerate computation.
- To design a user-friendly interface and a user manual for the software.

## Lexical Analyzer
### Principle
The lexical analyzer is the first step in analyzing the reactions described in a text file. Its task is to break down the text into elements such as enzyme names, substrates, products, rate constants, and inhibitors.

### Implementation
Implemented using regular expressions to recognize different patterns in the reaction description language. Each pattern is associated with an identifier for storage in an appropriate data structure. Data is stored in objects representing reactions, enzymes, substrates, products, rate constants, and inhibitors.

## Syntactic Analyzer
### Principle
The basic principle is to extract information about chemical reactions and inhibitions from a given input file. It first reads each line of the file and creates Reaction and Inhibition objects from its content, then adds these objects to corresponding data structures for further processing and calculations.

### Language Syntax
- For chemical reactions, the syntax is as follows: `Enzyme : Substrats -> Produits | Unités ; Kcat`
- For inhibition, the syntax is as follows: `Inhibiteur : Substrat | Unité`

### Implementation
Based on the provided code, mainly includes the following parts:
- Define Space, Reaction, and Inhibition classes to represent information in the input file.
- Create the analyzeLexicale class, containing private properties and methods (extract and buildGraph) and public properties (espaces, inhibitions, and réactions).
- Implement the constructor and destructor of the analyzeLexicale class.
- Implement the extract method of the analyzeLexicale class to analyze the input file and create reaction and inhibition objects.
- Define auxiliary functions split and extractContent for string operations.

## Extraction Algorithm
### Principle
The algorithm is used to search and identify all possible paths between two nodes of a graph, respecting a specific distance. In the provided code, several search methods have been implemented, including DFS (Depth-First Search), BFS (Breadth-First Search), and IDDFS (Iterative Deepening Depth-First Search).

### Architecture
The architecture of the extraction algorithm consists of a Graph class that contains search functions, as well as methods to add edges between nodes and to search for paths between nodes.

### Implementation
Implemented the Graph class and its associated functions. Search functions use recursive programming techniques for DFS and DLS, and an iterative approach using a queue for BFS. IDDFS uses DLS with increasing depth.

### Performance Comparison
In the comparison of BFS, DFS, and IDDFS for finding paths of a specific distance between two nodes, a significant observation is the superior performance of IDDFS, particularly when the reaction distance exceeds 4. The key points of comparison are as follows:

- **DFS (Depth-First Search)**: While DFS is efficient in certain scenarios, it can be less effective for larger distances as it deeply explores branches of the graph before moving to others. This could lead to substantial time spent on paths that do not match the desired distance.

- **BFS (Breadth-First Search)**: BFS explores all nodes at a given depth before moving to the next level. While it finds the shortest paths first, it also explores all possible paths up to the desired distance, which can be inefficient in densely connected graphs.

- **IDDFS (Iterative Deepening Depth-First Search)**: IDDFS combines the advantages of both DFS and BFS. It explores nodes at varying depths using a DFS approach while progressively increasing the search depth up to the desired distance. This approach allows IDDFS to quickly eliminate paths that are either too long or too short and efficiently find paths that match the specified distance. Notably, when the reaction distance is greater than 4, the speed of IDDFS is significantly faster than both BFS and DFS. This advantage is attributed to the way IDDFS balances depth exploration with breadth coverage, making it an ideal choice for exploring complex networks with longer paths.

Overall, IDDFS demonstrates a more efficient performance in searching for paths of a specific distance between two nodes, especially in scenarios where the reaction distance is greater than 4, thereby outperforming both BFS and DFS in terms of speed and efficiency.

## Output Module
### Principle
The output module is responsible for converting the results of the lexical analysis into a readable and understandable format for the user. It generates a formatted string describing reactions, inhibitions, and associated information, such as enzymes, substrates, products, units, and rate constants.

### Output Formats
The main output format is a textual string, which can be easily displayed on the screen or written to a file.

### Implementation
Implemented mainly through the operator << function, which takes an output stream (ostream) and an instance of the analyzeLexicale class as parameters. The function traverses the reactions and inhibitions stored in the analyzeLexicale instance and builds a formatted string to represent the associated information. This string is then written into the output stream.

## Demonstration
### Demonstration Introduction
The demonstration includes compiling the source code using a Makefile to generate an executable file. Then, the user runs the program by providing four arguments: a .ssa format reaction file, a reaction substrate, a reaction product, and a distance. The program will analyze the reactions in the file, apply the extraction algorithm, and save the results in an output.txt file in the current directory.

### Demonstration Scenarios
- Compile the program: Open a terminal and go to the directory containing the source code and Makefile. Execute the `make` command to compile the code and generate the executable file.
- Run the program: In the terminal, run the executable file with the required arguments. For example:
    ```
    ./executable reaction.ssa entre sortie distance
    ```
    where:
    - `reaction.ssa` is the file containing the reactions.
    - `entre` is the reaction's substrate.
    - `sortie` is the reaction's product.
    - `distance` is the distance between the substrate and the product.

### Demonstration Results
After running the program with the provided arguments, the results of the reaction analysis, the application of the extraction algorithm, and the generation of the output module will be saved in the output.txt file. The results will include information on reactions, inhibitions, enzymes, substrates, products, as well as the paths found between the substrate and product at the specified distance.、

<img src="/documents/output.png" width="50%" alt="Enzymatic Reactions output.txt">

