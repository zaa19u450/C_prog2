#ifndef ARR_LIB_H
#define ARR_LIB_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL void ARR_DECL fill_with_fib(int n, int *arr);

ARR_DLL void ARR_DECL take_first_occur(int *src, int src_len, int *dst, int *dst_len);

int met_before(int *arr, int i);

#endif // ARR_LIB_H
