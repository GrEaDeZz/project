#include <stdio.h>
#include "kvs.h"

#define DATA_SIZE    ((64) * (1))
#define STORAGE_SIZE ((1024) * (1024))

int main(void)
{

	size_t size = DATA_SIZE;
	char bigdata[DATA_SIZE],bigdata_recv[DATA_SIZE];
	char key[KVS_KEY_SIZE] = "key1_bigdata";

	for(int i = 0; i < DATA_SIZE - 1; i++)
		bigdata[i] = 'a';
	bigdata[DATA_SIZE-1] = 0;

	kvs_init(STORAGE_SIZE);

	kvs_put(key,KVS_KEY_SIZE,bigdata,DATA_SIZE);

	kvs_deinit();

	kvs_init(STORAGE_SIZE);

	kvs_get(key,bigdata_recv,&size);

	printf("Data: %s\n",bigdata_recv);

	kvs_deinit();

	return 0;
}
