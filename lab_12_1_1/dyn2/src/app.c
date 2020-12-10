#include "main_header.h"
#include "file_io.h"
#include "int_cmp.h"
#include "processing.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef void (__cdecl *fn_mysort_t)(void *, size_t, size_t, int(*comparator)(const void*, const void*));

typedef int (__cdecl *fn_key_t)(int *, int, int *, int *);

typedef int (__cdecl *fn_count_amount_t)(FILE *, int *);

typedef void (__cdecl *fn_from_file_to_array_t)(FILE *, const int *, const int *);

typedef void (__cdecl *fn_from_array_to_file_t)(FILE *, const int *, const int *);


int main(int argc, char **argv)
{
	HMODULE hlib;
	fn_mysort_t mysort;
	fn_key_t key;
	fn_count_amount_t count_amount;
	fn_from_file_to_array_t from_file_to_array;
	fn_from_array_to_file_t from_array_to_file;
	
    setbuf(stdout, NULL);
    int rc = OK;
    int n = 0;
    FILE *f;

    if ((argc < 3) || (argc > 4) || ((argc == 4) && strcmp(argv[3], "f")))
        rc = ERRARGS;
    else
    {
        f = fopen(argv[1], "r");
        if (f)
        {
			//Загружаем динамическую библиотеку
			hlib = LoadLibrary("libdyn2.dll");
			//проверяем, что она загрузилась
			if (!hlib)
			{
				printf("ERROR: Can't load library libdyn2.dll!\n");
				fclose(f);
				return ERRLIBRARRY;
			}
			//получаем адрес функции count_amount
			count_amount = (fn_count_amount_t) GetProcAddress(hlib, "count_amount");
			if (!count_amount)
			{
				printf("ERROR: Can't load function count_amount!\n");
				fclose(f);
				FreeLibrary(hlib);
				return ERRLIBRARRY;
			}
            rc = count_amount(f, &n);
            if (rc == OK)
            {
                fclose(f);

                int *pb0, *pe0;
                pb0 = calloc(n, sizeof(int));
                if (pb0 != NULL)
                {
                    pe0 = pb0 + n;
                    f = fopen(argv[1], "r");
                    if (f)
                    {
						//получаем адрес функции from_file_to_array
						from_file_to_array = (fn_from_file_to_array_t) GetProcAddress(hlib, "from_file_to_array");
						if (!from_file_to_array)
						{
							printf("ERROR: Can't load function from_file_to_array!\n");
							fclose(f);
							free(pb0);
							FreeLibrary(hlib);
							return ERRLIBRARRY;
						}
                        from_file_to_array(f, pb0, pe0);
						fclose(f);/////////////////////////////////
                        if (argc == 4)
                        {
                            int *pb1 = NULL, *pe1;
                            int n = 0;
							//получаем адрес функции key
							key = (fn_key_t) GetProcAddress(hlib, "key");
							if (!key)
							{
								free(pb0);
								FreeLibrary(hlib);
								printf("ERROR: Can't load function key!\n");
								return ERRLIBRARRY;
							}
                            rc = key(pb0, pe0 - pb0, pb1, &n);
                            if (rc == NOTENOUGH)
                            {
                                pb1 = malloc(n * sizeof(int));
                                if (pb1)
                                {
                                    rc = key(pb0, pe0 - pb0, pb1, &n);
                                    if (rc == OK)
                                    {
                                        pe1 = pb1 + n;
										//получаем адрес функции mysort
										mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
										if (!mysort)
										{
											FreeLibrary(hlib);
											free(pb0);
											free(pb1);
											printf("ERROR: Can't load function mysort!\n");
											return ERRLIBRARRY;
										}
                                        mysort(pb1, n, sizeof(int), int_cmp);
                                        f = fopen(argv[2], "w");
                                        if (f)
                                        {
											//получаем адрес функции from_array_to_file
											from_array_to_file = (fn_from_array_to_file_t) GetProcAddress(hlib, "from_array_to_file");
											if (!from_array_to_file)
											{
												FreeLibrary(hlib);
												free(pb0);
												free(pb1);
												printf("ERROR: Can't load function from_array_to_file!\n");
												fclose(f);
												return ERRLIBRARRY;
											}
                                            from_array_to_file(f, pb1, pe1);
                                            fclose(f);
                                        }
                                        else
                                            rc = ERROPEN;
                                        free(pb1);
                                    }
                                }
                                else
                                    rc = ERRMEM;
                            }
                        }
                        else
                        {
							//получаем адрес функции mysort
							mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
							if (!mysort)
							{
								FreeLibrary(hlib);
								free(pb0);
								printf("ERROR: Can't load function mysort!\n");
								return ERRLIBRARRY;
							}
                            mysort(pb0, pe0 - pb0, sizeof(int), int_cmp);
                            f = fopen(argv[2], "w");
                            if (f)
                            {
								//получаем адрес функции from_array_to_file
								from_array_to_file = (fn_from_array_to_file_t) GetProcAddress(hlib, "from_array_to_file");
								if (!from_array_to_file)
								{
									FreeLibrary(hlib);
									printf("ERROR: Can't load function from_array_to_file!\n");
									fclose(f);
									free(pb0);
									return ERRLIBRARRY;
								}
                                from_array_to_file(f, pb0, pe0);
                                fclose(f);
                            }
                            else
                                rc = ERROPEN;
                        }
                    }
                    else
                        rc = ERROPEN;
                    free(pb0);
                }
                else
                    rc = ERRMEM;
            }
			FreeLibrary(hlib);
        }
        else
            rc = ERROPEN;
    }
    return rc;
}
