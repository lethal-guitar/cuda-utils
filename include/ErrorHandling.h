#pragma once

#include <cuda.h>
#include <cuda_runtime_api.h>

namespace CudaUtils {
    /************************************************************************
     * Check Cuda API return code, throws CudaError
     * if given state indicates an error
     ************************************************************************/
    void checkError(cudaError_t state);

    /************************************************************************
     * Checks cudaGetLastError() and throws CudaError if error detected
     ************************************************************************/
    void checkState();
}
