#include <iostream>
#include <vector>

const int SIZE = 1024; 

void init_matrices(std::vector<float>& A, std::vector<float>& B, std::vector<float>& C) {
    for (int i = 0; i < SIZE * SIZE; ++i) {
        A[i] = static_cast<float>(i % 100) * 0.1f;
        B[i] = static_cast<float>((i * 2) % 100) * 0.1f;
        C[i] = 0.0f;
    }
}

void multiply_matrices(const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    for (int i = 0; i < SIZE; ++i) {
        for (int k = 0; k < SIZE; ++k) {
            for (int j = 0; j < SIZE; ++j) {
                C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }
}

float calculate_checksum(const std::vector<float>& C) {
    float sum = 0.0f;
    for (int i = 0; i < SIZE * SIZE; ++i) {
        sum += C[i];
    }
    return sum;
}

int main() {
    std::vector<float> A(SIZE * SIZE);
    std::vector<float> B(SIZE * SIZE);
    std::vector<float> C(SIZE * SIZE);

    init_matrices(A, B, C);
    multiply_matrices(A, B, C);
    
    float checksum = calculate_checksum(C);
    std::cout << "Done. Checksum: " << checksum << std::endl;

    return 0;
}

