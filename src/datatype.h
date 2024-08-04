//remember to import your header file in additional including file

#ifndef DATATYPE
#define DATATYPE
#include <xtensor/xarray.hpp>
using namespace xt;

//use macro to define common datatype
#define INT16 short int
#define INT32  int
#define INT64 long long int

#define UNSIGNED_INT16 unsigned short int
#define UNSIGNED_INT32 unsigned  int
#define UNSIGNED_INT64 unsigned long long int

#define FLOAT32 float
#define FLOAT64 double

//default tensor datatype
#define DEFAULT_TENSOR_INT16 xarray<INT16>({0})
#define DEFAULT_TENSOR_INT32 xarray<INT32>({0})
#define DEFAULT_TENSOR_INT64 xarray<INT64>({0})

#define DEFAULT_TENSOR_UNSIGNED_INT16 xarray<UNSIGNED_INT16>({0})
#define DEFAULT_TENSOR_UNSIGNED_INT32 xarray<UNSIGNED_INT32>({0})
#define DEFAULT_TENSOR_UNSIGNED_INT64 xarray<UNSIGNED_INT64>({0})

#define DEFAULT_TENSOR_FLOAT32 xarray<FLOAT32>({0.})
#define DEFAULT_TENSOR_FLOAT64 xarray<FLOAT64>({0.})

#endif // !DATATYPE
