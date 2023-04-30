#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include "analyseLexicale.hpp"
using std::cerr;
using std::stoi;


int main(int argc, char* argv[]) {
    
    
    // 检查命令行参数数量
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << " <filename> <entre> <sortie> <distance>" << endl;
        return 1;
    }

    // 解析命令行参数
    string filename = argv[1];
    string reactant = argv[2];
    string product = argv[3];
    int distance = stoi(argv[4]);
    
    
    auto start_time = std::chrono::high_resolution_clock::now();



    std::shared_ptr<analyseLexicale> analyseLexicale_ptr(new analyseLexicale(filename));


    nodeFromTo nft = analyseLexicale_ptr->getTraces(reactant, product);

    vector<std::thread> threads;
    vector<std::string> results;
    std::mutex results_mutex;



     for (int entre : nft.from) {
         for (int sortie : nft.to) {
             std::thread t([&, analyseLexicale_ptr]() {
                 string res = analyseLexicale_ptr->findPaths(entre, sortie, distance);
                 std::lock_guard<std::mutex> lock(results_mutex);
                 if (std::find(results.begin(), results.end(), res) == results.end()) {
                     results.push_back(res);
                 }
                 cout<< "thread finished" << endl;
             });

             threads.push_back(std::move(t));
         }
     }
     for (auto& t : threads) {
         t.join();
     }


  std::ofstream output_file("output.txt", std::ios::trunc);
    if (output_file.is_open()) {
        output_file << "Entre: " << reactant <<std::endl;
        output_file << "Sortie: " << product <<std::endl;
        output_file << "Distance: " << distance <<std::endl;
        output_file << "Nombre de traces: " << results.size() << std::endl;
        for (const auto& result : results) {
            if(result == "")
            continue;
            output_file << result << std::endl;
        }
        output_file.close();
    } else {
        std::cerr << "Unable to open file: output.txt" << std::endl;
    }

    auto end_time = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    cout << "Program running time: " << duration << " milliseconds" << endl;
    return 0;



}

