#include <hpx/local/algorithm.hpp>
#include <hpx/local/init.hpp>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

//matrix mtply for a given row
template <typename T>
T mtply_row(const vector<T>& matrix1, const vector<T>& matrix2,
                      size_t row, size_t col_size){
    T result = 0;
    for (size_t i=0;i<col_size;++i) {
        result+=matrix1[row*col_size+i]*matrix2[i*col_size+row];
    }c     
    return result;
}
//pll matrix mutply
template <typename T>
vector<T> parallel_mtply(const vector<T>& matrix1,
                                   const vector<T>& matrix2,
                                   size_t size){
    vector<T> result(size*size);
    //parallel transform to perform multiplication for each element
    transform(par.with_policy(par::static_chunk_size()),
              begin_index(size), end_index(size),
              begin(result),
              [&](size_t i){
                  return mtply_row(matrix1, matrix2, i, size);
              });
    return result;
}

int hpx_main(int argc, char* argv[]){
    size_t size=100; 
    vector<double> matrix1(size*size);
    vector<double> matrix2(size*size);
    //random vals
    default_random_engine generator;
    uniform_real_distribution<double> ranged(0.0, 100.0);
    auto rand_val=[&](){return ranged(generator);};

    generate(begin(matrix1), end(matrix1), rand_val);
    generate(begin(matrix2), end(matrix2), rand_val);
    //Perform pll matrix mtply
    vector<double> result=parallel_mtply(matrix1, matrix2, size);
    return hpx::local::finalize();
}
int main(int argc, char* argv[]){
    return hpx::local::init(argc, argv);
}