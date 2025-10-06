#include "gac_common.h"

#define DATA_SIZE    ((512) * (1024) * (1024))
#define STORAGE_SIZE ((1024) * (1024) * (1024))

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

	if(kvs_exists(key))
		printf("key: \'%s\' is exists\n",key);

	kvs_deinit();

	return 0;
}
