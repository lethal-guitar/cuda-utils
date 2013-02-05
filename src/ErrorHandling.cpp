#include "ErrorHandling.h"
#include "CudaError.h"

namespace CudaUtils {

    void checkError(cudaError_t state) {
        if (state != cudaSuccess) {
            throw CudaError(state);
        }
    }

    void checkState() {
        checkError(cudaGetLastError());
    }
}
