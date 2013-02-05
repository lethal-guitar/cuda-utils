Cuda Utilities
==============

Some C++ classes to simplify working with the CUDA Runtime API. Requires a C++ 11 compatible compiler.

= Overview =

Currently, this contains the following classes/functions, all in namespace `CudaUtils`:

=== Memory ===

RAII-Wrapper for device memory. Example usage:

```cpp
// Allocate dataSize float elements on device
CudaUtils::Memory<float> deviceData(dataSize);

// Perform cudaMemcpy from dataSource
float* dataSource = //...
deviceData.transferFrom(dataSource);

// Perform cudaMemcpy into hostData
std::vector<float> hostData(dataSize);
deviceData.transferTo(hostData.data());

// Get raw device pointer in order to pass it into a kernel call etc.
float* rawGpuPtr = deviceData.get();
```

=== CudaError ===

A C++ exception wrapper class for CUDA error codes.

=== Error checking functions ===

The header file `ErrorHandling.h` defines the following helper functions to ease error checking:

```cpp
// Throws CudaError if state indicates an error
void checkError(cudaError_t state);

// Throws CudaError if cudaGetLastError() indicates an error
void checkState();
```
